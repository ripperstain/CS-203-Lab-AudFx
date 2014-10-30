#include "GainFilter.h"
#include <iostream>
#include "base\unittest\AbstractAudioTest.h"
using namespace std;

void testgain()
{
	float g;
	g = 2;

	GainFilter gain1("gaintest");
	AATestSource source("Source");

	source.setNext(&gain1);
	gain1.setPrevious(&source);

	gain1.setgain(g);

	//get samples and verify
	const int bufsize = 10;
	unsigned char* mybuf = new unsigned char[bufsize];
	int samplesReturned = gain1.getSamples((char*)mybuf, bufsize);

	assert(samplesReturned == bufsize);

	for (int i = 0; i < samplesReturned; i++){
		cout << " Verifying element " << i << " is " << i + 1 << " : ";
		cout << (int)mybuf[i] << endl;
		assert(mybuf[i] == i * 2);
	}

	delete mybuf;

}