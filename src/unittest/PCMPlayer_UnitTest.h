#ifndef PCMPLAYER_UNITTEST_H
#define PCMPLAYER_UNITTEST_H

#include <string>

class UnitTestInterface
{
	virtual std::string TestName() = 0;
	virtual bool RunTest() = 0;
};

class PCMPlayerTest : public UnitTestInterface
{
	std::string TestName() { return "PCMPlayer Unit Test"; }
	bool RunTest();
};

#endif