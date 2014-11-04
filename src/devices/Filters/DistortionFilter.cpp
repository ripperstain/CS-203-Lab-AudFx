#include "DistortionFilter.h"
#include <iostream>

using namespace std;


DistortionFilter::DistortionFilter(string name) : AbstractAudio(name, AudioType::Processor), gain("mygain")
{
	distort = 2.0F;

	//Default mix to 80% distorted signal, 20% original
	mix = 0.8F;

	//Set up links with gain processor
	this->next = &gain;
	gain.setPrevious(this);
}


//Mix can only range from 0.0 to 1.0.  any other values are invalid
void DistortionFilter::SetMix(float m)
{
	if (m > 1.0F || m < 0.0F) return;
	mix = m;
}

int DistortionFilter::getSamples(float* buffer, int length)
{
	
	int samplesReturned = previous->getSamples(buffer, length);
	
	
	for (int i = 0; i < samplesReturned; i++){
		//Process each sample
		float sample = buffer[i];
		float q = sample / abs(sample);
		float z = q * (1 - exp(distort * sample * sample / abs(sample)));

		//mix distorted signal with original
		sample = z * mix + sample * (1 - mix);

		/*if (sample > drive){
			sample = drive;
		}
		else if (sample < -drive){
			sample = -drive;
		}*/

		buffer[i] = sample;

	}

	return samplesReturned;
}

void DistortionFilter::setNext(AbstractAudio *n)
{
	gain.setNext(n);
}

void DistortionFilter::setPrevious(AbstractAudio *p)
{
	this->previous = p;
}
