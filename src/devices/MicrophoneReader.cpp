
#include "MicrophoneReader.h"
#include "../support/SampleConverter.h"

#include <stdio.h>
#include <sstream>

using namespace std;

MicrophoneReader::MicrophoneReader(string name) : AbstractAudio(name, AudioType::Source)
{
	deviceNum = 0;
	NumChannels = 1;
	SamplingRate = 44100;
	AudioFormat.NumChannels = NumChannels;
	AudioFormat.SampleRate = SamplingRate;
	AudioFormat.BitsPerSample = 16;
	clearCache();
	
	atomic_init(&isRecording, false);
	atomic_init(&waveFreeBlockCounter, -1);
	atomic_init(&waveCurrentBlockIndex, 0);
}

MicrophoneReader::~MicrophoneReader()
{

}



int MicrophoneReader::getSamples(float* buffer, int length)
{

	std::lock_guard<std::mutex> l(sampleMutex);
	for (int i = 0; i < length; i++){
		buffer[i] = sampleCache[i];
	}

	return length;
}

devicelist MicrophoneReader::GetDevices()
{
	devicelist devices;
	numDevices = waveInGetNumDevs();

	for (int i = 0; i < numDevices; i++){
		WAVEINCAPS caps;
		MMRESULT res = waveInGetDevCaps(i, &caps, sizeof(caps));
		wstringstream ws;
		ws << caps.szPname;
		devices.push_back(ws.str());
	}
	return devices;
}

void MicrophoneReader::record()
{
	if (isRecording.load()){
		return;
	}

	isRecording.store(true);
	recordThread = thread(&MicrophoneReader::recordBackground, this);

}

void MicrophoneReader::stop()
{
	if (isRecording.load() == false){
		return;
	}

	isRecording.store(false);
	if (recordThread.joinable()){
		recordThread.join();
	}
	
}


void MicrophoneReader::clearCache()
{
	for (int i = 0; i < BLOCK_SIZE; i++){
		sampleCache[i] = 0.0f;
	}
}


static void CALLBACK waveInProc(HWAVEIN hWaveIn, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2)
{
	WAVEHDR *block = (WAVEHDR*)dwParam1;
	switch (uMsg){
	case WIM_DATA:
		//
		atomic<int> *freeBlockIndex = (atomic<int>*)dwInstance;
		freeBlockIndex->store(block->dwUser);
	}
}


bool MicrophoneReader::initializeRecorder()
{

	WAVEFORMATEX pFormat;
	pFormat.wFormatTag = WAVE_FORMAT_PCM;
	pFormat.nChannels = 1;
	pFormat.nSamplesPerSec = SamplingRate;
	pFormat.nAvgBytesPerSec = 2 * SamplingRate;
	pFormat.nBlockAlign = 2;
	pFormat.wBitsPerSample = AudioFormat.BitsPerSample;
	pFormat.cbSize = 0;

	result = waveInOpen(&hWaveIn, WAVE_MAPPER, &pFormat, (DWORD_PTR)&waveInProc, (DWORD_PTR)&waveFreeBlockCounter, CALLBACK_FUNCTION);

	if (result != MMSYSERR_NOERROR) {
#ifdef CONSOLEOUT
		switch (result){
		case MMSYSERR_INVALHANDLE:
			cout << "Invalid Device Handle" << endl;
			break;
		case MMSYSERR_NOMEM:
			cout << "Unable to allocate or lock memory" << endl;
			break;
		case MMSYSERR_NODRIVER:
			cout << "No device driver is present" << endl;
			break;
		default:
			cout << "Unknown Error: " << result << endl;
		}
		cout << "Failed to open Wave Input Device." << endl;
#endif
		return false;
	}

	for (int i = 0; i < BLOCK_COUNT; i++){
		WaveInHdr[i].lpData = new char[BLOCK_SIZE];
		WaveInHdr[i].dwBufferLength = BLOCK_SIZE * 2;
		WaveInHdr[i].dwBytesRecorded = 0;
		WaveInHdr[i].dwUser = i;
		WaveInHdr[i].dwFlags = 0;
		WaveInHdr[i].dwLoops = 0;
	}

	result = waveInStart(hWaveIn);
	if (result != MMSYSERR_NOERROR) {
#ifdef CONSOLEOUT
		cout << "Failed to start Wave Input Device." << endl;
#endif
		return false;
	}

	return true;
}


void MicrophoneReader::recordBackground()
{
	if (!initializeRecorder()){
		isRecording.store(false);
		return;
	}

	int index = waveFreeBlockCounter.load();
	
	//Prepare all headers
	for (int i = 0; i < BLOCK_COUNT; i++){
		waveInPrepareHeader(hWaveIn, &WaveInHdr[i], sizeof(WAVEHDR));
		waveInAddBuffer(hWaveIn, &WaveInHdr[i], sizeof(WAVEHDR));
	}

	while (isRecording.load()){
		
		//Sleep a millisecond if the Counter hasn't changed
		if (index == waveFreeBlockCounter.load()){
			Sleep(1);
		}
		else{
			//If counter has changed, we have a buffer of data
			//copy it into the sample Cache to be grabbed by getSamples
			//Then add the buffer back to the Audio In device
			index = waveFreeBlockCounter.load();
			{
				std::lock_guard<std::mutex> l(sampleMutex);
				SampleConverter::convertShortToFloat((short*)WaveInHdr[index].lpData, sampleCache, WaveInHdr[index].dwBytesRecorded / 2);
			}
			if (WaveInHdr[index].dwFlags & WHDR_PREPARED){
				waveInUnprepareHeader(hWaveIn, &WaveInHdr[index], sizeof(WAVEHDR));
			}
			waveInPrepareHeader(hWaveIn, &WaveInHdr[index], sizeof(WAVEHDR));
			waveInAddBuffer(hWaveIn, &WaveInHdr[index], sizeof(WAVEHDR));
		}
	}


	waveInReset(hWaveIn);

	for (int i = 0; i < BLOCK_COUNT; i++){
		if (WaveInHdr[i].dwFlags & WHDR_PREPARED){
			waveInUnprepareHeader(hWaveIn, &WaveInHdr[i], sizeof(WAVEHDR));
		}
		delete WaveInHdr[i].lpData;
	}

	waveInStop(hWaveIn);

	clearCache();
	isRecording.store(false);
}