#ifndef ABSTRACTAUDIOTEST_H
#define ABSTRACTAUDIOTEST_H

#include "base\AbstractAudio.h"
#include "cassert"

/*
	The following test devices will be used to simulate
	an audio chain for testing and demonstration purposes
	The sink device will be responsible for initiating
	the test via it's RunTest() method.  The constructed
	audio chain will be:
	AATestSource -> AATestProcessor -> AATestSink
*/
class AATestSource : public AbstractAudio
{
public:
	AATestSource(std::string name);
	virtual int getSamples(char* buffer, int length);
};

class AATestProcessor : public AbstractAudio
{
public:
	AATestProcessor(std::string name);
	virtual int getSamples(char* buffer, int length);
};

class AATestSink : public AbstractAudio
{
public:
	AATestSink(std::string name);
	virtual int getSamples(char* buffer, int length);
	bool RunTest();
};

#endif