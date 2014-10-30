#pragma once;

#include "base\AbstractAudio.h"

const int size=10;
class GainFilter: public AbstractAudio
{
public:
	
	GainFilter(std::string name);
	virtual int getSamples(char* buffer, int length);
	void setgain(float);
	float getgain();
	
	


private:
	float gainvalue;
	
	
};