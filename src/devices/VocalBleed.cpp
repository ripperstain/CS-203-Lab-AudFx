#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "VocalBleed.h"

VocalBleed::VocalBleed(std::string name) : AbstractAudio(name, AudioType::Processor) {
	Enabled = true;
}
int VocalBleed::getSamples(float* buffer, int length){
	//Grabs the samples from the previous audio device
	int samplesReturned = previous->getSamples(buffer, length);

	//Check to see how many channels there are
	if (Enabled == true && NumChannels == 2) {
		for (int i = 0; i < samplesReturned; i += 2){
			float oldLeft, newLeft, oldRight, newRight;

			oldLeft = buffer[i];
			oldRight = buffer[i + 1];

			newLeft = (oldLeft - oldRight) / .8;
			newRight = (oldRight - oldLeft) / .8;

			buffer[i] = (oldLeft - newLeft);
			buffer[i + 1] = (oldRight - newRight);
		}

	}
	return samplesReturned;
}
