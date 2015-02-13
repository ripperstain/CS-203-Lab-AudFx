#define _USE_MATH_DEFINES

#include "IIRFilter.h"
#include <cmath>

using namespace std;

IIRFilter::IIRFilter()
{
	memset(&es, 0, sizeof(EQSTATE));

	vsa = (1.0 / 4294967295.0);

	mixFreq = 44100;
}

void IIRFilter::setFreq(double frq)
{
	filterFreq = frq;
}

void IIRFilter::setGain(double gn)
{
	gain = gn;
}

float IIRFilter::doFilter(float buffer)
{

	/*float sample;

	es.freq = 2 * sin(M_PI * (filterFreq / mixFreq));

	es.f1p0 += (es.freq * (buffer - es.f1p0)) + vsa;
	es.f1p1 += (es.freq * (es.f1p0 - es.f1p1));
	es.f1p2 += (es.freq * (es.f1p1 - es.f1p2));
	es.f1p3 += (es.freq * (es.f1p2 - es.f1p3));

	sample = es.f1p0 * gain;

	return sample;*/

	return buffer;
}