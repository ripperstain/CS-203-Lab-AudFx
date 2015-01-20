#include <iostream>
#include "cassert"

#include "../../../src/devices/WavReader.h"
#include "../../../src/devices/filters/gainfilter.h"

#include "../../../src/base/unittest/abstractaudiotest.h"
using namespace std;

void main()
{
	GainFilter Gain("gaintest");
	AATestSource Source("Source");

	Source.setNext(&Gain);
	Gain.setPrevious(&Source);

	float gain_level;
	cout << "Enter Gain level to be applied: ";
	cin >> gain_level;

	Gain.setgain(gain_level);

	//get samples and verify
	const int bufsize = 10;

	float* mybuf = new float[bufsize];
	int samplesReturned = Gain.getSamples((float*)mybuf, bufsize);

	assert(samplesReturned == bufsize);

	for (int i = 0; i < samplesReturned; i++)
	{
		float temp = i;
		cout << " Verifying element " << i << " is " << temp * gain_level << " : ";
		cout << mybuf[i] << endl;
		assert(mybuf[i] == i * gain_level);
	}

	cout << "Gain Filter has been applied and is functional." << endl;

	delete mybuf;
}