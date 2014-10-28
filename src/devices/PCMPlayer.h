#ifndef PCMPLAYER_H
#define PCMPLAYER_H

#include "base\AbstractAudio.h"
/*
must add winmm.lib and dsound.lib to Additional Dependencies of project
Properties->Linker->Input (set Configuration to All Configurations before changing)
*/
#include <Windows.h>
#include <dsound.h>
#include <thread>
#include <atomic>

#include <vector>
#include <string>
typedef std::vector<std::wstring> devicelist;

/*
PCMPLayer will initialize a Windows Wave Output Device and feed blocks of audio to it
When the device finished playing a block of audio, it will seamlessly transition to playing
the next block, as long as there is a next block to play.

So it is important to make sure there is always a next block to play.

*/
/*
Define # of available audio blocks and the size of each block
*/
#define BLOCK_SIZE 8192
#define BLOCK_COUNT 3
static void CALLBACK waveOutProc(HWAVEOUT hWaveOut, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2);


class PCMPlayer : public AbstractAudio
{
public:
	PCMPlayer(std::string name);
	~PCMPlayer();
	bool NegotiateParameters();
	bool play();
	void pause();
	void stop();
	//This method should never be called by a sink device
	int getSamples(char* buffer, int length) { return 0; }

	devicelist GetDevices();
	bool SelectDevice();

	bool isPlaying();
protected:
	
private:
	int deviceNum;
	int numDevices;
	WAVEHDR waveBlocks[BLOCK_COUNT];
	int waveCurrentBlock;
	HWAVEOUT hwo; /* device handle */
	AudioFormatStruct AudioFormat;
	std::thread playThread;

	/*
	This is the counter to keep track of how many free blocks are available
	STL atomic is used as the waveOutProc callback is called asynchronously.
	*/
	std::atomic<int> waveFreeBlockCount;
	std::atomic<bool> Playing;
	std::atomic<bool> Paused;
	void playBackground();
	void writeAudio(HWAVEOUT hWaveOut, char* data, int size);

};

#endif