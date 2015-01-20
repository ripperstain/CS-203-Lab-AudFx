#include "DistortionFilterUnitTest.h"

#include "devices\Filters\DistortionFilter.h"
#include "base\unittest\AbstractAudioTest.h"
#include "cassert"

#include <iostream>

using namespace std;

int main(){

	AATestSource source("Source");

	DistortionFilter distortion("Distortion");

	const int bufferSize = 20;
	float samples[bufferSize];
	int numSamples = source.getSamples(samples, bufferSize);

	distortion.SetMix(.5);

	assert(distortion.GetMix() == .5);

	distortion.SetGain(1.5);

	assert(distortion.GetGain() == 1.5);

	distortion.SetDistort(2.0);

	assert(distortion.GetDistort() == 2.0);

	system("pause");

	return 0;
}