#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "KaraokeProcessor.h"

KaraokeProcessor::KaraokeProcessor(std::string name) : AbstractAudio(name, AudioType::Processor) {

}
int KaraokeProcessor::getSamples(char* buffer, int length){

	int samplesReturned = previous->getSamples(buffer, length);
	for (int i = 0; i < samplesReturned; i+=2){
		//Karaoke Subtraction
		char tempSample = buffer[i];
		buffer[i] = (buffer[i] - buffer[i + 1]) / 2;
		buffer[i + 1] = (buffer[i + 1] - tempSample) / 2;
	}

	return samplesReturned;
}