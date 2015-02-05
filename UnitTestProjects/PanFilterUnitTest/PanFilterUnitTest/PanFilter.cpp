#include "PanFilter.h"
#include <iostream>

using namespace std;



PanFilter::PanFilter(string name) : AbstractAudio(name, AudioType::Processor)
{
	//defult Pan value set to 1
	panValue = 0.75;

}


int PanFilter::getSamples(float* buffer, int length)
{
	//Perform some simple test processing of samples here
	int samplesReturned = previous->getSamples(buffer, length);

	float leftChannel = 1.0;//variable to hold the Left Channels Output
	float rightChannel;//variable to hold the Right Channels Output

	for (int i = 0; i < samplesReturned; i+=2)
	{
		leftChannel = leftChannel * panValue;
		rightChannel = leftChannel * (1 - panValue);

		buffer[i] = buffer[i] * leftChannel;
		buffer[i + 1] = buffer[i + 1] * rightChannel;
	}
	//returns the modified samples
	return samplesReturned;
}

void PanFilter::setPan(float temp)
{
	//sets the Pan(Balance) to the value set by the user
	panValue = temp;
}
float PanFilter::getPan()
{
	//returns the Pan value 
	return panValue;
}
