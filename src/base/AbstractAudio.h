#ifndef ABSTRACTAUDIO_H
#define ABSTRACTAUDIO_H

#include <string>

enum class AudioType{
NoType,
Source,
Processor,
Monitor,
Sink
};

class AbstractAudio
{
public:
	AbstractAudio(string name, AudioType type);
	
	virtual int getsamples(int16* buffer, int length) = 0;
	
	std::string getName() { return Name; }
	bool getByPass() { return ByPass; }
	void setByPass(bool b) { ByPass = b; }
	
	void setNext(AbstractAudio *n) { next = n; }
	void setPrevious(AbstractAudio *p) { previous = p; }
	
protected:
	//Methods to negotiate Sampling Rat and # Channels in Audio Chain
	void NegotiateSamplingRate();
	void NegotiateNumberOfChannels();
	
	//Helper methods for negotiating Sampling Rate and # Channels
	void MinMaxSamplingRate(int &min, int &max, int &preferred);
	void MinMaxChannels(int &min, int &max, int &preferred);
	
	//Methods to set negotiated values to all devices in the chain
	void SetSamplingRateRecursive(int rate);
	void SetChannelsRecursive(int ch);
private:
	//Pointers to next and previous devices in chain
	AbstractAudio *next, *previous;
	
	std::string Name;
	AudioType Type;
	int SamplingRate;
	int NumChannels;
	
	bool SamplingRateFrozen, NumChannelsFrozen, ByPass;

};

#endif