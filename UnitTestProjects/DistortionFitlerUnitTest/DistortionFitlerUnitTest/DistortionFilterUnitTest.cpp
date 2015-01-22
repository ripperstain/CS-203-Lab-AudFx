#include "DistortionFilterUnitTest.h"

#include "devices\Filters\DistortionFilter.h"
#include "base\unittest\AbstractAudioTest.h"
#include "cassert"

#include <iostream>

using namespace std;

int main(){

	AATestSourceDistortion source("Source");

	DistortionFilter distortion("Distortion");

	source.setNext(&distortion);
	distortion.setPrevious(&source);

	const int bufferSize = 20;
	float samples[bufferSize];
	

	distortion.SetMix(.5);

	assert(distortion.GetMix() == .5);

	distortion.SetGain(1.5);

	assert(distortion.GetGain() == 1.5);

	distortion.SetDistort(2.0);

	assert(distortion.GetDistort() == 2.0);

	distortion.Enable(true);

	assert(distortion.isEnabled() == true);

	int distortSamples = distortion.getSamples(samples, bufferSize);

	assert(distortSamples == bufferSize);

	for (int i = 0; i < bufferSize; i++)
	{

		float testsample;
		if ((i % 2) == 0) testsample = -1;
		else testsample = 1;
		float q = testsample / abs(testsample);
		float z = q * (1 - exp(2.0 * testsample * testsample / abs(testsample)));
		testsample = z * .5 + testsample * (1.0 - .5);

		assert(testsample == samples[i]);
	}


	cout << "Distortion Filter Unit Test Complete" << endl;

	system("pause");

	return 0;
}