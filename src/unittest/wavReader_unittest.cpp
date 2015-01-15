#include "wavReader_unittest.h"

#include "devices\wavReader.h"

short testfile[] = {
	0x52, 0x49, 0x46, 0x46, 	//RIFF header
	0x00,						//file size - 8
	0x57, 0x41, 0x56, 0x45,		//WAVE header
	0x66, 0x6D, 0x74, 0x20,     //fmt header
	0x10, //fmt header size
	0x01, //Compression code (PCM uncompressed)
	0x02, //Number of Channels
	
	
	0x64, 0x61, 0x74, 0x61,		//DATA header
};

bool WavReaderTest::RunTest()
{
	//Run tests for WavReader Source Device
}