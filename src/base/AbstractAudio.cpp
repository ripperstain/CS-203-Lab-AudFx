#include "AbstractAudio.h"

AbstractAudio::AbstractAudio(string name, AudioType type)
{
	Name = name;
	Type = type;
	
	next = nullptr;
	previous = nullptr;
	
	SamplingRate = 0;
	NumChannels = 0;
	
	SamplingRateFrozen = false;
	NumChannelsFrozen = false;
	
}


//Methods to negotiate Sampling Rat and # Channels in Audio Chain
void NegotiateSamplingRate()
{
	if(next != nullptr){
		next->NegotiateSamplingRate();
	}else{
		int min = 11025;
		int max = 44000;
		int preferred = 11025;
		
		MinMaxSamplingRate(min, max, preferred);
		if(min > max){
			//Failed to negotiate sampling rate
		}
		SetSamplingRateRecursive(preferred);
	}
}

void NegotiateNumberOfChannels()
{
	if(next != nullptr){
		next->NegotiateNumberOfChannels();
	}else{
		int min = 1;
		int max = 2;
		int preferred = 1;
		
		MinMaxChannels(min, max, preferred);
		if(min > max){
			//Failed to negotiate num channels
		}
		SetChannelsRecursive(preferred);
	}
}


//Helper methods for negotiating Sampling Rate and # Channels
void MinMaxSamplingRate(int min, int max, int preferred)
{
	if(previous != nullptr){
		previous->MinMaxSamplingRate(min, max, preferred);
	}
	
	int thisMin = min;
	int thisMax = max;
	int thisPreferred = preferred;
	
	if(SamplingRate != 0){
		thisPreferred = SamplingRate;
		preferred = SamplingRate;
	}
	
	if(thisPreferred < thisMin){
		preferred = thisMin;
	}
	
	if(thisPreferred > thisMax){
		preferred = thisMax;
	}
}

void MinMaxChannels(int min, int max, int preferred)
{
	if(previous != null){
		previous->MinMaxChannels(min, max, preferred);
	}
	
	if(numChannels != 0){
		preferred = numChannels;
	}
	
	int currentMin = min;
	int currentMax = max;
	int currentPreferred = preferred;
	
	if(currentPreferred < currentMin){
		preferred = currentMin;
	}
	
	if(currentPreferred > currentMax){
		preferred = currentMax;
	}
}


//Methods to set negotiated values to all devices in the chain
void SetSamplingRateRecursive(int rate)
{
	if(previous != nullptr){
		previous->SetSamplingRateRecursive(rate);
	}
	
	SamplingRate = rate;
	SamplingRateFrozen = true;
}

void SetChannelsRecursive(int ch)
{
	if(previous != nullptr){
		previous->SetChannelsRecursive(ch);
	}
	
	NumChannels = ch;
	NumChannelsFrozen = true;
}
