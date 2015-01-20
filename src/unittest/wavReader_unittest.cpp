#include "wavReader_unittest.h"

#include "devices\wavReader.h"
#include "base\unittest\AbstractAudioTest.h"
#include "cassert"

#include <iostream>

using namespace std;


//Sample header to be used to create a test file with
//Not including audio data.  That will have to be generated
//DATA chunk size and overall file size must be properly filled in as well
short testFileHeader[] = {
	0x52, 0x49, 0x46, 0x46, 	//RIFF header
	0x00, 0x00, 0x00, 0x00,		//file size - 4 byte Little Endian
	0x57, 0x41, 0x56, 0x45,		//WAVE header
	0x66, 0x6D, 0x74, 0x20,     //fmt header
	0x10, 0x00, 0x00, 0x00,		//fmt header size - 4 byte LE
	0x01, 0x00,					//Compression code (PCM uncompressed) - 2 byte LE
	0x02, 0x00,					//Number of Channels - 2 byte LE
	0x44, 0xAC, 0x00, 0x00,		//Sample rate - 4 byte LE
	0x10, 0xB1, 0x02, 0x00,		//Average bytes per second - 4 byte LE (Sample rate * bytes per sample * num channels)
	0x04, 0x00,					//Block align - 2 byte LE
	0x10, 0x00,					//Significant bits per sample - 2 byte LE
								//Extra format bytes (none)
	0x64, 0x61, 0x74, 0x61,		//DATA header
	0x00, 0x00, 0x00, 0x00		//DATA chunk size - 4 byte LE
};


//Helper method to set the filesize in the file header
void SetFileSize(int size)
{
	
}

//Helper method to set the data size in the file header
void SetDataSize(int size)
{
	
}

//Create a test file for this unit test to read in and verify against
void CreateTestFile(string filename)
{
	
}

//Delete a test file that was created for this unit test
void DeleteTestFile(string filename)
{
	
}

void ValidateSamples(float *samples, int bufferSize)
{
	
}

bool WavReaderTest::RunTest()
{

	return false;
}


int main()
{
	//Run tests for WavReader Source Device

	cout << "Running WavReader Unit Test" << endl;
	string filename = "..\\..\\..\\audio\\Yamaha-SY-35-Clarinet-C5.wav";

	WavReader reader(filename);
	AATestSink sink("Sink");


	reader.setNext(&sink);
	sink.setPrevious(&reader);

	//bool res = sink.RunTest();
	AudioFormatStruct wavInfo = reader.getAudioFormat();
	assert(wavInfo.SampleRate == 44100);
	assert(wavInfo.NumChannels == 2);
	assert(wavInfo.BitsPerSample == 16);

	int calculatedByteRate = wavInfo.BitsPerSample / 8;
	calculatedByteRate *= wavInfo.SampleRate *wavInfo.NumChannels;
	assert(wavInfo.ByteRate == calculatedByteRate);

	const int bufferSize = 20;
	float samples[bufferSize];
	int numSamples = reader.getSamples(samples, bufferSize);

	assert(numSamples == bufferSize);

	ValidateSamples(samples, numSamples);

	cout << "WavReader Unit Test Complete" << endl;
	
	system("pause");
	
}



