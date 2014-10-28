
#include "PCMPlayer.h"
#include <sstream>
#ifdef CONSOLEOUT
#include <iostream>
#endif

using namespace std;
bool PCMPlayer::NegotiateParameters()
{


}


bool PCMPlayer::play()
{
	if (!NegotiateParameters()){
		return false;
	}
	if (previous == nullptr){
		return false;
	}

	AudioFormatStruct AudioFormat = previous->getAudioFormat();
	char *buffer = new char[BLOCK_SIZE];
	
	//initialise current block index
	waveCurrentBlock = 0;

	
	WAVEFORMATEX wf;
	wf.nSamplesPerSec = AudioFormat.SampleRate; 
	wf.wBitsPerSample = AudioFormat.BitsPerSample; 
	wf.nChannels = AudioFormat.NumChannels; 
	wf.cbSize = 0; // unused
	wf.wFormatTag = WAVE_FORMAT_PCM;
	wf.nBlockAlign = (wf.wBitsPerSample * wf.nChannels) >> 3;
	wf.nAvgBytesPerSec = wf.nBlockAlign * wf.nSamplesPerSec;
	/*
	 try to open the selected wave device (deviceNum)
	 GetDevices & SelectDevice can be used to show the list
	 of available devices and choose which you want to open
	*/
	MMRESULT res;
	res = waveOutOpen(&hwo, deviceNum, &wf, (DWORD_PTR)&waveOutProc, (DWORD_PTR)&waveFreeBlockCount, CALLBACK_FUNCTION);
	if (res != MMSYSERR_NOERROR) {
#ifdef CONSOLEOUT
		cout << "Failed to open Wave Output Device." << endl;
#endif
		return false;
	}


	int readCount = 0;
	printf("buffersize: %i\n", BLOCK_SIZE);


	while (1) {
		DWORD readBytes;
		readBytes = previous->getSamples(buffer, BLOCK_SIZE);
		
		//Check if we've reached the end of the audio stream
		//Two cases, completely empty buffer, or partially empty buffer
		if (readBytes == 0){
			break;
		}
		if (readBytes < BLOCK_SIZE) {
			//Set the rest of the buffer to zeroes and play the partial buffer
			//Otherwise we can get a bit of noise at the end of the stream
			memset(buffer + readBytes, 0, BLOCK_SIZE - readBytes);
		}
		
		writeAudio(hwo, buffer, BLOCK_SIZE);
	}
	
	//Wait until all blocks have been played
	while (waveFreeBlockCount < BLOCK_COUNT)
		Sleep(10);
	
	//Clean up
	for (int i = 0; i < waveFreeBlockCount; i++)
	if (waveBlocks[i].dwFlags & WHDR_PREPARED)
		waveOutUnprepareHeader(hwo, &waveBlocks[i], sizeof(WAVEHDR));

	waveOutClose(hwo);
	delete buffer;

}


void PCMPlayer::stop()
{


}


void PCMPlayer::waveOutProc(HWAVEOUT hWaveOut, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2)
{
	switch (uMsg){
	case WOM_OPEN:
		//cout << "waveOutProc: WOM_OPEN" << endl;
		break;
	case WOM_CLOSE:
		//cout << "waveOutProc: WOM_CLOSE" << endl;
		break;
	case WOM_DONE:
		//cout << "waveOutProc: WOM_DONE" << endl;
		//WAVEHDR* hdr = (WAVEHDR*)dwParam1;
		//block = hdr->dwUser;
		atomic<int> *freeBlockCounter = (atomic<int>*)dwInstance;
		(*freeBlockCounter)++;
		break;
	}

}

PCMPlayer::PCMPlayer(string name) : AbstractAudio(name, AudioType::Sink)
{
	deviceNum = 0;
	numDevices = waveOutGetNumDevs();
	waveFreeBlockCount.store(BLOCK_COUNT);
	for (int i = 0; i < BLOCK_COUNT; i++){
		waveBlocks[i].lpData = new char[BLOCK_SIZE];
	}
}

PCMPlayer::~PCMPlayer()
{
	for (int i = 0; i < BLOCK_COUNT; i++){
		delete waveBlocks[i].lpData;
	}
}

devicelist PCMPlayer::GetDevices()
{
	devicelist devices;
	
	for (int i = 0; i < numDevices; i++){
		WAVEOUTCAPS caps;
		MMRESULT res = waveOutGetDevCaps(i, &caps, sizeof(caps));
		wstringstream ws;
		ws << caps.szPname;
		devices.push_back(ws.str());
	}

}


void PCMPlayer::writeAudio(HWAVEOUT hWaveOut, char* data, int size)
{
	WAVEHDR* current = &waveBlocks[waveCurrentBlock];

	//Clean up current header
	if (current->dwFlags & WHDR_PREPARED)
		waveOutUnprepareHeader(hWaveOut, current, sizeof(WAVEHDR));

	//copy audio data into header, prepare, and write to device
	memcpy(current->lpData, data, size);
	current->dwBufferLength = size;
	waveOutPrepareHeader(hWaveOut, current, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, current, sizeof(WAVEHDR));

	//Decrement free block counter
	waveFreeBlockCount--;

	//Wait loop for when no blocks are free
	while (waveFreeBlockCount.load() == 0)
		Sleep(10);

	//Increment current block (rolling back to first block when necessary)
	waveCurrentBlock++;
	waveCurrentBlock %= BLOCK_COUNT;
	return;
}