#include "AbstractAudioTest.h"
#include <iostream>

using namespace std;

/********************************************

	Methods for AATestSource

*********************************************/
AATestSource::AATestSource(string name) : AbstractAudio(name, AudioType::Source)
{
	//Use nonvalid values here for test purposes
	SamplingRate = 40404;
	NumChannels = 77;

}


int AATestSource::getSamples(float* buffer, int length)
{
	//Generate some test samples here
	for (int i = 0; i < length; i++){
		buffer[i] = i;
	}
	return length;
}


/********************************************

	Methods for AATestProcessor

*********************************************/
AATestProcessor::AATestProcessor(string name) : AbstractAudio(name, AudioType::Processor)
{


}

int AATestProcessor::getSamples(float* buffer, int length)
{
	//Perform some simple test processing of samples here
	int samplesReturned = previous->getSamples(buffer, length);
	for (int i = 0; i < samplesReturned; i++){
		//Process each sample
		buffer[i] += 1;
	}

	return samplesReturned;
}


/********************************************

	Methods for AATestSink

*********************************************/
AATestSink::AATestSink(string name) : AbstractAudio(name, AudioType::Sink)
{


}

int AATestSink::getSamples(float* buffer, int length)
{

	int samplesReturned = previous->getSamples(buffer, length);
	return samplesReturned;
}


bool AATestSink::RunTest()
{
	if (previous == nullptr) return false;

	cout << "Negotiating Sampling Rate" << endl;
	NegotiateSamplingRate();
	cout << "Sampling Rate is " << SamplingRate << endl;
	assert(SamplingRate == 44100);

	cout << "Negotiating Number of Channels" << endl;
	NegotiateNumberOfChannels();
	cout << "Number of Channels is " << NumChannels << endl;
	assert(NumChannels == 2);


	//get samples and verify
	const int bufsize = 10;
	float* mybuf = new float[bufsize];
	int samplesReturned = getSamples(mybuf, bufsize);
	
	assert(samplesReturned == bufsize);

	/*for (int i = 0; i < samplesReturned; i++){
		cout << " Verifying element " << i << " is " << i + 1 << " : ";
		cout << (int)mybuf[i] << endl;
		assert(mybuf[i] == i + 1);
	}*/

	delete mybuf;

	return true;
}