#ifndef ABSTRACTAUDIOTEST_H
#define ABSTRACTAUDIOTEST_H

#include "../AbstractAudio.h"
#include "cassert"

/*
	The following test devices will be used to simulate
	an audio chain for testing and demonstration purposes
	The sink device will be responsible for initiating
	the test via it's RunTest() method.  The constructed
	audio chain will be:
	AATestSource -> AATestProcessor -> AATestSink

	Each device is only required to provide their specific implementation of
	getSamples, but each also provides their own constructor for their own
	specific initialization.

	The sink device also provides it's own unique RunTest() method, which is
	the call to run the unit tests.  This is where methods like Play(), Pause(),
	Stop() would be implemented as well.
*/
class AATestSource : public AbstractAudio
{
public:
	AATestSource(std::string name);
	virtual int getSamples(float* buffer, int length);
};

class AATestSourceDistortion : public AbstractAudio
{
public:
	AATestSourceDistortion(std::string name);
	virtual int getSamples(float* buffer, int length);
};

class AATestProcessor : public AbstractAudio
{
public:
	AATestProcessor(std::string name);
	virtual int getSamples(float* buffer, int length);
};

class AATestSink : public AbstractAudio
{
public:
	AATestSink(std::string name);
	virtual int getSamples(float* buffer, int length);
	bool RunTest();
};

#endif