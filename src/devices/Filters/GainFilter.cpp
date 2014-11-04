#include "GainFilter.h"
#include <iostream>

using namespace std;



GainFilter::GainFilter(string name) : AbstractAudio(name, AudioType::Processor)
{
	//defult gain value set to 1
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
	//returns the modified sample
	return samplesReturned;
}

void GainFilter::setgain(float temp)
{
	//sets the gain to the amount specified by the user
	gainvalue = temp;
}
float GainFilter::getgain()
{
	//returns the gain value 
	return gainvalue;
}
