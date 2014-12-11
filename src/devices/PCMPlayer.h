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

/*
PCMPLayer will initialize a Windows Wave Output Device and feed blocks of audio to it.
When the device finishes playing a block of audio, it will seamlessly transition to playing
the next block, as long as there is a next block to play.

So it is important to make sure there is always a next block to play.
waveOutProc lets PCMPlayer know when a block of audio has finished playing, and the player
will then write another block to the device.

BLOCK_COUNT defines the maximum number of blocks to use.  This needs to be no less than 2 to
maintain seemless playing.

===============================================
		~~~ Interface ~~~
===============================================
		GetDevices()
			returns a vector of strings with the name of each audio output device on the computer

		SelectedDevice():
			Specify which audio output device you want the player to connect to

		play()
			Start playing the audio stream.  This establishes a connection to the output device
			and streams audio to the device in a background thread.

		pause()
			pause playing.  If no audio is being played, this effectively does nothing.
			Calling pause repeatedly toggles the pause state.

		stop()
			Stop playing the audio stream.  Hitting play() again will restart the audio from the
			beginning.

		isPlaying()
			returns true if the player is in the process of playing audio (regardles of pause state)

*/


/*
Define # of available audio blocks and the size of each block
*/
#define BLOCK_SIZE 4096
#define BLOCK_COUNT 3

//Callback from audio device to let Player know when a block of audio has finished playing (and that buffer is
//then available for another block of audio)
static void CALLBACK waveOutProc(HWAVEOUT hWaveOut, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2);


class PCMPlayer : public AbstractAudio
{
public:
	PCMPlayer(std::string name);
	~PCMPlayer();
	void play();
	void pause();
	void stop();

	//This method should never be called on a sink device
	//but it needs an implementation as all AbstractAudio devices do
	int getSamples(float* buffer, int length) { return 0; }

	devicelist GetDevices();
	bool SelectDevice(int num);

	bool isPlaying() { return bPlaying.load(); }
protected:
	bool NegotiateParameters();

private:
	int deviceNum;
	int numDevices;
	WAVEHDR waveBlocks[BLOCK_COUNT]; /* array of wave headers */
	int waveCurrentBlock; /* currently available audio buffer */

	bool signedNative;
	unsigned int offset;

	HWAVEOUT hwo; /* device handle */
	AudioFormatStruct AudioFormat;
	std::thread playThread;

	/*
	This is the counter to keep track of how many free blocks are available
	STL atomic is used as the waveOutProc callback is called asynchronously.
	*/
	std::atomic<int> waveFreeBlockCount;

	/*
	bPlaying flag is used to indicate to background thread when to stop playing
	*/
	std::atomic<bool> bPlaying;

	/*
	bPaused flag is used to indicate to background thread when to pause
	*/
	std::atomic<bool> bPaused;

	/*
	playBackground and writeAudio are methods executed by the background thread to
	play audio in the background
	*/
	void playBackground();
	void writeAudio(HWAVEOUT hWaveOut, float* data, int size);

};

#endif