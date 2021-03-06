
#include "PCMPlayer.h"
#include "../support/SampleConverter.h"
#include <stdio.h>
#include <sstream>
#ifdef CONSOLEOUT
#include <iostream>
#endif

using namespace std;

PCMPlayer::PCMPlayer(string name) : AbstractAudio(name, AudioType::Sink)
{
	deviceNum = 0;
	numDevices = waveOutGetNumDevs();

	atomic_init(&bPlaying, false);
	atomic_init(&bPaused, false);

	atomic_init(&waveFreeBlockCount, BLOCK_COUNT);
	//for (int i = 0; i < BLOCK_COUNT; i++){
	//	waveBlocks[i].lpData = new char[BLOCK_SIZE];
	//}
}

PCMPlayer::~PCMPlayer()
{
	if (bPlaying.load()){
		bPlaying.store(false);
		
	}
	if (playThread.joinable()){
		playThread.join();
	}

}

bool PCMPlayer::NegotiateParameters()
{
	NegotiateSamplingRate();
	NegotiateNumberOfChannels();
	SetBufferSizeRecursive(BLOCK_SIZE);
	return true;
}

void PCMPlayer::play()
{

	if (bPlaying.load()){
		//Already playing
		return;
	}

	/*
	Initialize everything to start playing
	audio from the start
	*/
	previous->reset();
	bPlaying.store(true);
	bPaused.store(false);

	if (playThread.joinable()){
		playThread.join();
	}

	//start playing audio in the background
	playThread = thread(&PCMPlayer::playBackground, this);

	return;

}

void PCMPlayer::pause()
{
	//toggle bPaused flag
	bool tmp = bPaused.load();
	bPaused.store(!tmp);

}
void PCMPlayer::stop()
{
	bPlaying.store(false);
	playThread.join();
	previous->reset();
}

void PCMPlayer::playBackground()
{
	if (!NegotiateParameters()){
		return;
	}
	if (previous == nullptr){
		return;
	}

	AudioFormat = previous->getAudioFormat();

	//initialise current block index
	waveCurrentBlock = 0;
	waveFreeBlockCount.store(BLOCK_COUNT);

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
	res = waveOutOpen(&hwo, deviceNum, &wf, (DWORD_PTR)&waveOutProc, (DWORD_PTR)&waveFreeBlockCount, 
						CALLBACK_FUNCTION);

	if (res != MMSYSERR_NOERROR) {
#ifdef CONSOLEOUT
		cout << "Failed to open Wave Output Device." << endl;
#endif
		return;
	}


	int readCount = 0;
#ifdef CONSOLEOUT
	cout << "buffersize: " << BLOCK_SIZE << endl;
#endif
	for (int i = 0; i < BLOCK_COUNT; i++){
		switch (AudioFormat.BitsPerSample){
		case 8:
			waveBlocks[i].lpData = new char[BLOCK_SIZE];
			break;
		case 16:
			waveBlocks[i].lpData = new char[BLOCK_SIZE*2];
			break;
		}
		
	}

	if (AudioFormat.BitsPerSample == 8){
		signedNative = false;
	}
	else{
		signedNative = true;
	}
	offset = 1 << (AudioFormat.BitsPerSample - 1);

	//buffer used by getSamples
	//data will be copied from this buffer into an available audio block
	//to be written to output device
	float buffer[BLOCK_SIZE];

	//Get and play samples while bPlaying is true
	//if stop() is called, it sets bPlaying to false and
	//waits for play thread to join.
	while (bPlaying.load()) 
	{

		DWORD readBytes;
		readBytes = previous->getSamples(buffer, BLOCK_SIZE);

		//Check if we've reached the end of the audio stream
		//Two cases, completely empty buffer, or partially empty buffer
		if (readBytes <= 0){
			break;
		}
		if (readBytes < BLOCK_SIZE) {
			//Set the rest of the buffer to match the last valid entry
			//Otherwise we can get a bit of noise at the end of the stream
#ifdef CONSOLEOUT
			//cout << "Partial buffer received: " << readBytes << " bytes." << endl;
#endif
			//More involved than just a memset when dealing with different bit rates
			//and number of channels.  This needs to be fixed properly
			//memset(buffer + readBytes, buffer[readBytes - 1], BLOCK_SIZE - readBytes);
		}


		//Send audio data to output device
		writeAudio(hwo, buffer, readBytes);

		if (bPaused.load()){
			waveOutPause(hwo);
			while (bPaused.load() && bPlaying.load()){
				Sleep(10);
			}
			//Only restart if we're still playing
			//stop could have been called while paused
			if (bPlaying.load()){
				waveOutRestart(hwo);
			}

		}
	}

	if (bPlaying.load()){
		//Wait until all blocks have been played
		while (waveFreeBlockCount < BLOCK_COUNT)
			Sleep(10);

	}
	else{
		waveOutReset(hwo);
	}

	//Clean up
	for (int i = 0; i < waveFreeBlockCount; i++){
		if (waveBlocks[i].dwFlags & WHDR_PREPARED)
			waveOutUnprepareHeader(hwo, &waveBlocks[i], sizeof(WAVEHDR));
	}
	
	waveOutClose(hwo);
	//delete buffer;
	for (int i = 0; i < BLOCK_COUNT; i++){
		delete waveBlocks[i].lpData;
	}
	bPlaying.store(false);

}


static void CALLBACK waveOutProc(HWAVEOUT hWaveOut, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2)
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
	return devices;
}

bool PCMPlayer::SelectDevice(int num)
{
	if (num >= 0 && num < numDevices){
		deviceNum = num;
		return true;
	}
	return false;
}

void PCMPlayer::writeAudio(HWAVEOUT hWaveOut, float* data, int size)
{
	WAVEHDR* current = &waveBlocks[waveCurrentBlock];

	//Clean up current header
	if (current->dwFlags & WHDR_PREPARED)
		waveOutUnprepareHeader(hWaveOut, current, sizeof(WAVEHDR));

	
	//copy audio data into header, prepare, and write to device
	for (int i = 0; i < size; i++){
		//First, clip input to the range 1.0 : -1.0
		//In case any intermediate device left values outside the range
		if (data[i] > 0){
			if (data[i] > 1.0F){
				data[i] = 1.0F;
			}
		}
		else{
			if (data[i] < -1.0F){
				data[i] = -1.0F;
			}
		}
		
	}

	//Now convert back to native format
	switch (AudioFormat.BitsPerSample){
	case 8:
		SampleConverter::convertFloatToUChar((unsigned char*)current->lpData, data, size);
		break;
	case 16:
		SampleConverter::convertFloatToShort(data, (short*)current->lpData, size);
		break;
	}
	
	current->dwBufferLength = size * (AudioFormat.BitsPerSample / 8);
	waveOutPrepareHeader(hWaveOut, current, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, current, sizeof(WAVEHDR));

	//Decrement free block counter
	waveFreeBlockCount--;

	//Wait loop for when no blocks are free
	while (waveFreeBlockCount.load() == 0 && bPlaying.load())
		Sleep(10);

	//if we're here, next block is avaiable for writing
	//Increment current block (rolling back to first block when necessary)
	waveCurrentBlock++;
	waveCurrentBlock %= BLOCK_COUNT;
	return;
}
