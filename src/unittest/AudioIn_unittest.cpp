#include "wavReader_unittest.h"

#include "devices\MicrophoneReader.h"
//#include "base\unittest\AbstractAudioTest.h"
#include "cassert"

#include <iostream>

using namespace std;

int main()
{
	//Run tests for WavReader Source Device

	cout << "Running AudioIn Unit Test" << endl;

	MicrophoneReader reader("Unit Mic");
	
	reader.record();
	//reader.stop();
	
	AudioFormatStruct wavInfo = reader.getAudioFormat();
	assert(wavInfo.SampleRate == 44100);
	assert(wavInfo.NumChannels == 1);
	assert(wavInfo.BitsPerSample == 16);

	int calculatedByteRate = wavInfo.BitsPerSample / 8;
	calculatedByteRate *= wavInfo.SampleRate *wavInfo.NumChannels;

	//For some reason the Win32 WaveIn API does not provide ByteRate or
	assert(wavInfo.ByteRate == calculatedByteRate);

	const int bufferSize = 20;
	float samples[bufferSize];
	int numSamples = reader.getSamples(samples, bufferSize);

	assert(numSamples == bufferSize);

	cout << "AudioIn Unit Test Complete" << endl;

	system("pause");

}



