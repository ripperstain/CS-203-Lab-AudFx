#pragma once;

#include "../../base/AbstractAudio.h"


class PanFilter : public AbstractAudio
{
public:

	PanFilter(std::string name);
	virtual int getSamples(float* buffer, int length);
	void setPan(float);
	float getPan();




private:
	float panValue;


};