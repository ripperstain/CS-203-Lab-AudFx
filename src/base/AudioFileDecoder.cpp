#include "AudioFileDecoder.h"




//Helper methods for negotiating Sampling Rate and # Channels
virtual void MinMaxSamplingRate(int &min, int &max, int &preferred)
{
	initializeDecoder();
	
	min = SamplingRate;
	max = SamplingRate;
	preferred = SamplingRate;
}
virtual void MinMaxChannels(int &min, int &max, int &preferred)
{
	initializeDecoder();
	
	min = numChannels;
	max = numChannels;
	preferred = numChannels;
}
