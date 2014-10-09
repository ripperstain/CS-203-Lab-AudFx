#include "AbstractAudio.h"

using namespace std;

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
void AbstractAudio::NegotiateSamplingRate()
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

void AbstractAudio::NegotiateNumberOfChannels()
{
	if(next != nullptr){
		next->NegotiateNumberOfChannels();
	}else{
		int min = 1;
		int max = 1000;
		int preferred = 1;
		
		MinMaxChannels(min, max, preferred);
		if(min > max){
			//Failed to negotiate num channels
		}
		SetChannelsRecursive(preferred);
	}
}


//Helper methods for negotiating Sampling Rate and # Channels
void AbstractAudio::MinMaxSamplingRate(int &min, int &max, int &preferred)
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

void AbstractAudio::MinMaxChannels(int &min, int &max, int &preferred)
{
	if(previous != nullptr){
		previous->MinMaxChannels(min, max, preferred);
	}
	
	if (NumChannels != 0){
		preferred = NumChannels;
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
void AbstractAudio::SetSamplingRateRecursive(int rate)
{
	if(previous != nullptr){
		previous->SetSamplingRateRecursive(rate);
	}
	
	SamplingRate = rate;
	SamplingRateFrozen = true;
}

void AbstractAudio::SetChannelsRecursive(int ch)
{
	if(previous != nullptr){
		previous->SetChannelsRecursive(ch);
	}
	
	NumChannels = ch;
	NumChannelsFrozen = true;
}
