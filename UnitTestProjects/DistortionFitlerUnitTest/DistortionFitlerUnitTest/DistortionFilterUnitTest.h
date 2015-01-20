#ifndef DISTORTIONFILTERUNITTEST_H
#define DISTORTIONFILTERUNITTEST_H

#include <string>

class UnitTestInterface
{
	virtual std::string TestName() = 0;
	virtual bool RunTest() = 0;
};

class DistortionFilterTest : public UnitTestInterface
{
	std::string TestName() { return "DistortionFilter Unit Test"; }
	bool RunTest();
};


#endif