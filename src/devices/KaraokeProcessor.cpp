#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "KaraokeProcessor.h"

KaraokeProcessor::KaraokeProcessor(std::string name) : AbstractAudio(name, AudioType::Processor) {

}
int KaraokeProcessor::getSamples(char* buffer, int length){
	int samplesReturned = previous->getSamples(buffer, length);

	if (NumChannels == 2) {
		for (int i = 0; i < samplesReturned; i += 2){
			//Karaoke Subtraction
			/*
				jhaskell notes:	
			This works only when sample size is 8 bits
			Does not work with 16 bit sample sizes
				example in audio\norestforthewicked.wav
			Need to query Source device for Audio Format and handle
			8 bit and 16 bit cases separately
			*/
			char tempSample = buffer[i];
			buffer[i] = (buffer[i] - buffer[i + 1]) / 2;
			buffer[i + 1] = (buffer[i + 1] - tempSample) / 2;
		}
		//std::cout << "Karaoke Processing Complete." << std::endl;
	}
	return samplesReturned;
}