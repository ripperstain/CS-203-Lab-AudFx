#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "KaraokeProcessor.h"

KaraokeProcessor::KaraokeProcessor(std::string name) : AbstractAudio(name, AudioType::Processor) {
	Enabled = true;
}
int KaraokeProcessor::getSamples(float* buffer, int length){
	//Grabs the samples from the previous audio device
	int samplesReturned = previous->getSamples(buffer, length);

	//Check to see how many channels there are
	if (Enabled == true && NumChannels == 2) {
			for (int i = 0; i < samplesReturned; i += 2){
				float tempSample = buffer[i];
				buffer[i] = (buffer[i] - buffer[i + 1]) / .8;
				buffer[i + 1] = (buffer[i + 1] - tempSample) / .8;
			}

	}
	return samplesReturned;
}
