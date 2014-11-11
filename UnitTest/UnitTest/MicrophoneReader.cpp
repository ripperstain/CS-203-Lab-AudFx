#include "MicrophoneReader.h"
#include <stdio.h>


using namespace std;

MicrophoneReader::MicrophoneReader(string name) : AbstractAudio(name, AudioType::Source)
{
	deviceNum = 0;
	NUMPTS = 44100;
	sampleRate = 44100;
}

int MicrophoneReader::getSamples(float* buffer, int length)
{




	return size;
}

void MicrophoneReader::initializeRecorder()
{

	WAVEFORMATEX pFormat;
	pFormat.wFormatTag = WAVE_FORMAT_PCM;
	pFormat.nChannels = 1;
	pFormat.nSamplesPerSec = sampleRate;
	pFormat.nAvgBytesPerSec = 2 * sampleRate;
	pFormat.nBlockAlign = 2;
	pFormat.wBitsPerSample = 16;
	pFormat.cbSize = 0;

	result = waveInOpen(&hWaveIn, WAVE_MAPPER, &pFormat, (DWORD_PTR)&waveInProc, (DWORD_PTR)&freeBlockIndex, CALLBACK_FUNCTION);

	for (int i = 0; i < BLOCK_COUNT; i++){
		WaveInHdr[i].lpData = new char[BLOCK_SIZE*2];
		WaveInHdr[i].dwBufferLength = 2 * NUMPTS;
		WaveInHdr[i].dwBytesRecorded = 0;
		WaveInHdr[i].dwUser = 0;
		WaveInHdr[i].dwFlags = 0;
		WaveInHdr[i].dwLoops = 0;

		waveInPrepareHeader(hWaveIn, &WaveInHdr[i], sizeof(WAVEHDR));
		result = waveInAddBuffer(hWaveIn, &WaveInHdr[i], sizeof(WAVEHDR));
	}

	result = waveInStart(hWaveIn);

}

static void CALLBACK waveInProc(HWAVEIN hWaveIn, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2)
{
	switch (uMsg){
	case WIM_DATA:
		atomic<int> *freeBlockCounter = (atomic<int>*)dwInstance;
	}
}
//void MicrophoneReader::stopRecord()
//{
//
//	waveInUnprepareHeader(hWaveIn, &WaveInHdr, sizeof(WAVEHDR));
//	waveInClose(hWaveIn);
//}