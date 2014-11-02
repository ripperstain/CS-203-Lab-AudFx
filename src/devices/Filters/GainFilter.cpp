#include "GainFilter.h"
#include <iostream>

using namespace std;



GainFilter::GainFilter(string name) : AbstractAudio(name, AudioType::Processor)
{
	gainvalue = 1;

}


int GainFilter::getSamples(float* buffer, int length)
{
	//Perform some simple test processing of samples here
	int samplesReturned = previous->getSamples(buffer, length);
	for (int i = 0; i < samplesReturned; i++){
		//Process each sample
		buffer[i] = buffer[i] * gainvalue;

	}

	return samplesReturned;
}

void GainFilter::setgain(float temp)
{
	gainvalue = temp;
}
float GainFilter::getgain()
{
	return gainvalue;
}
