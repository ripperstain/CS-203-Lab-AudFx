#pragma once;

#include "base\AbstractAudio.h"
#include "GainFilter.h"

class DistortionFilter : public AbstractAudio
{
public:

	DistortionFilter(std::string name);
	virtual int getSamples(float* buffer, int length);
	void SetDistort(float d){ distort = d; }
	float GetDistort(){ return distort; }

	void SetMix(float m);
	float GetMix(){ return mix; }

	void SetGain(float g){ gain.setgain(g); }
	float GetGain(){ return gain.getgain(); }

	virtual void setNext(AbstractAudio *n);
	virtual void setPrevious(AbstractAudio *p);

private:
	float distort, mix;
	GainFilter gain;

};