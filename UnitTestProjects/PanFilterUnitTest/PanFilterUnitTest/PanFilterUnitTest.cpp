#include <iostream>
#include "cassert"

#include "../../../src/devices/WavReader.h"
#include "../../../UnitTestProjects/PanFilterUnitTest/PanFilterUnitTest/PanFilter.h"

#include "../../../src/base/unittest/AbstractAudioTest.h"
using namespace std;

void main()
{
	PanFilter Pan("pantest");
	AATestSource Source("Source");

	Source.setNext(&Pan);
	Pan.setPrevious(&Source);

	float panLevel;
	cout << "Enter Pan level to be applied: ";
	cin >> panLevel;

	Pan.setPan(panLevel);

	//get samples and verify
	const int bufsize = 10;

	float* mybuf = new float[bufsize];
	int samplesReturned = Pan.getSamples((float*)mybuf, bufsize);

	assert(samplesReturned == bufsize);


	cout << "Pan Filter has been applied and is functional." << endl;

	delete mybuf;
}