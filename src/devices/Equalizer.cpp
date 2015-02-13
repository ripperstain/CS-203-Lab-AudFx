#include "Equalizer.h"

Equalizer::Equalizer(std::string name) : AbstractAudio(name, AudioType::Processor) 
{
	enabled = true;

	low.setFreq(60.0);
	lowMid.setFreq(300.0);
	mid.setFreq(1000.0);
	highMid.setFreq(5000.0);
	high.setFreq(10000.0);
}

int Equalizer::getSamples(float* buffer, int length)
{
	int samplesReturned = previous->getSamples(buffer, length);

	for (int i = 0; i < samplesReturned; i++)
	{
		float l, lm, m, hm, h;

		l = low.doFilter(buffer[i]);
		lm = lowMid.doFilter(buffer[i]);
		m = mid.doFilter(buffer[i]);
		hm = highMid.doFilter(buffer[i]);
		h = high.doFilter(buffer[i]);

		buffer[i] = ((l + lm + m + hm + h) / 5);
	}

	return samplesReturned;
}