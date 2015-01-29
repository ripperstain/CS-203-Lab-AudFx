#include "SaveSink.h"
#include "../support/SampleConverter.h"

#ifdef CONSOLEOUT
#include <iostream>
#endif

using namespace std;

SaveSink::SaveSink(string name) : AbstractAudio(name, AudioType::Sink){
	
}

SaveSink::~SaveSink() {
	
}

bool SaveSink::saveWav(string filepath){
	ofstream outputBuffer(filepath, ios::out | ios::binary);

	float buffer[BLOCK_SIZE];
	unsigned char saveBuffer[BLOCK_SIZE];

	//get header stuff here
	//write the header to the begining of the file

	//write the individual samples to the rest of the file

	//check for what size samples they are/were
	while (1) {
		DWORD readBytes;
		readBytes = previous->getSamples(buffer, BLOCK_SIZE);

		SampleConverter::convertFloatToUChar(saveBuffer, buffer, BLOCK_SIZE);

		outputBuffer.write(reinterpret_cast<const char*>(saveBuffer), BLOCK_SIZE);

		if (readBytes == 0) break;
	}

	return true;
}