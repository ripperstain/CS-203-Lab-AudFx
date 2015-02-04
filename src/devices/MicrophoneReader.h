#include "base\AbstractAudio.h"
#include "devices\PCMPlayer.h"
#include <iostream>
#include <Windows.h>
#include <MMSystem.h>
#include <dsound.h>
#include <thread>
#include <atomic>
#include <mutex>

static void CALLBACK waveInProc(HWAVEIN hWaveIn, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2);

class MicrophoneReader : public AbstractAudio
{
public:
	MicrophoneReader(std::string name);
	~MicrophoneReader();

	int getSamples(float* buffer, int length);
	
	devicelist GetDevices();
	bool SelectDevice(int devnum);
	int GetSelectedDevice(){ return deviceNum; }
	AudioFormatStruct getAudioFormat(){ return AudioFormat; }

	bool Open();
	void Close();

private:
	int deviceNum;
	int numDevices;
	AudioFormatStruct AudioFormat;

	float sampleCache[BLOCK_SIZE];
	volatile int samplesRecorded;
	void clearCache();
	void WaveInCleanup();

	HWAVEIN hWaveIn;
	WAVEHDR WaveInHdr[BLOCK_COUNT];
	MMRESULT result;

	bool initializeRecorder();
	enum{
		AudioClosedState,
		AudioInitializingState,
		AudioRecordingState,
		AudioInitializeFailedState
	};

	std::thread recordThread;
	std::atomic<int> isRecording;
	std::atomic<int> waveFreeBlockCounter;
	std::atomic<int> waveCurrentBlockIndex;

	std::mutex sampleMutex;
	void recordBackground();
};