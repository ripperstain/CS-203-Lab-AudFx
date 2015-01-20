#ifndef WAVEREADER_UNITTEST_H
#define WAVEREADER_UNITTEST_H

#include <string>

class UnitTestInterface
{
	virtual std::string TestName() = 0;
	virtual bool RunTest() = 0;
};

class WavReaderTest : public UnitTestInterface
{
	std::string TestName() { return "WavReader Unit Test"; }
	bool RunTest();
};


#endif