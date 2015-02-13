#ifndef IIRFILTER_H
#define IIRFILTER_H

#include "base/AbstractAudio.h"

typedef struct
{

	double freq; // Frequency
	double f1p0; // Poles ...
	double f1p1;
	double f1p2;
	double f1p3;

} EQSTATE;

class IIRFilter
{
public:
	IIRFilter();
	void setFreq(double frq);
	void setGain(double gn);
	float doFilter(float buffer);

private:
	EQSTATE es;
	double vsa;
	double mixFreq;
	double filterFreq;
	double gain;
};

#endif