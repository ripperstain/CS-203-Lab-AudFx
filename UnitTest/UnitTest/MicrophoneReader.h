#include "base\AbstractAudio.h"
#include "devices\PCMPlayer.h"
#include <iostream>
#include <Windows.h>
#include <MMSystem.h>
#include <dsound.h>
#include <thread>
#include <atomic>

static void CALLBACK waveInProc(HWAVEIN hWaveIn, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2);

class MicrophoneReader : public AbstractAudio
{
public:
	MicrophoneReader(std::string name);
	~MicrophoneReader();

	void initializeRecorder();

	int getSamples(float* buffer, int length) { return 0; }// Cast char buffer to short

private:
	int deviceNum;
	int numDevices;
	int NUMPTS; //Frequency * recording length in seconds
	int sampleRate;  //Frequency

	HWAVEIN hWaveIn;
	WAVEHDR WaveInHdr[BLOCK_COUNT];
	MMRESULT result;

	std::thread recordThread;

};