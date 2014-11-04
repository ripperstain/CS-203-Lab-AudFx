#pragma once;

#include "base\AbstractAudio.h"


class GainFilter: public AbstractAudio
{
public:
	
	GainFilter(std::string name);
	virtual int getSamples(float* buffer, int length);
	void setgain(float);
	float getgain();
	
	


private:
	float gainvalue;
	
	
};