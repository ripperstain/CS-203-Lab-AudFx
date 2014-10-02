#include "AudioFileDecoder.h"




//Helper methods for negotiating Sampling Rate and # Channels
void AudioFileDecoder::MinMaxSamplingRate(int &min, int &max, int &preferred)
{
	initializeDecoder();
	
	min = SamplingRate;
	max = SamplingRate;
	preferred = SamplingRate;
}
void AudioFileDecoder::MinMaxChannels(int &min, int &max, int &preferred)
{
	initializeDecoder();
	
	min = numChannels;
	max = numChannels;
	preferred = numChannels;
}
