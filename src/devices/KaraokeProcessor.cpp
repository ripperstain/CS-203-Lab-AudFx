#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "KaraokeProcessor.h"

KaraokeProcessor::KaraokeProcessor(std::string name) : AbstractAudio(name, AudioType::Processor) {

}
int KaraokeProcessor::getSamples(char* buffer, int length){
	//Grabs the samples from the previous audio device
	int samplesReturned = previous->getSamples(buffer, length);

	//Check to see how many channels there are
	if (NumChannels == 2) {
		//Checks to see if the audio is 8 bit
		if (previous->getAudioFormat().BitsPerSample == 8) {
			//Subtracts Right from Left, store in left, and vice versa
			//Then multiplying by .8 to adjust amplitude
			for (int i = 0; i < samplesReturned; i += 2){
				char tempSample = buffer[i];
				buffer[i] = (buffer[i] - buffer[i + 1]) / .8;
				buffer[i + 1] = (buffer[i + 1] - tempSample) / .8;
			}
		}
		//Checks to see if the audio is 16 bit
		else if (previous->getAudioFormat().BitsPerSample == 16) {
			//Subtracts Right from Left, store in left, and vice versa
			//Then multiplying by .8 to adjust amplitude
			for (int i = 0; i < samplesReturned; i += 4){
				char tempSample = buffer[i];
				char tempSample2 = buffer[i + 1];
				buffer[i] = (buffer[i] - buffer[i + 2]) * .8;
				buffer[i + 1] = (buffer[i + 1] - buffer[i + 3]) * .8;
				buffer[i + 2] = (buffer[i+2] - tempSample) * .8;
				buffer[i + 3] = (buffer[i + 3] - tempSample2) * .8;
			}
		}
	}
	return samplesReturned;
}