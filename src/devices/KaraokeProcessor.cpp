#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "KaraokeProcessor.h"

KaraokeProcessor::KaraokeProcessor(std::string name) : AbstractAudio(name, AudioType::Processor) {

}
int KaraokeProcessor::getSamples(char* buffer, int length){
	int samplesReturned = previous->getSamples(buffer, length);

	if (NumChannels == 2) {
		if (previous->getAudioFormat().BitsPerSample == 8) {
			for (int i = 0; i < samplesReturned; i += 2){
				char tempSample = buffer[i];
				buffer[i] = (buffer[i] - buffer[i + 1]) / 2;
				buffer[i + 1] = (buffer[i + 1] - tempSample) / 2;
			}
		}
		else if (previous->getAudioFormat().BitsPerSample == 16) {
			for (int i = 0; i < samplesReturned; i += 4){
				char tempSample = buffer[i];
				char tempSample2 = buffer[i + 1];
				buffer[i] = (buffer[i] - buffer[i + 2]) * .7;
				buffer[i + 1] = (buffer[i + 1] - buffer[i + 3]) * .7;
				buffer[i + 2] = (buffer[i+2] - tempSample) * .7;
				buffer[i + 3] = (buffer[i + 3] - tempSample2) * .7;
			}
		}
	}
	return samplesReturned;
}