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


struct AudioFormatStruct{
	unsigned short AudioFormat;
	unsigned short NumChannels;
	unsigned int SampleRate;
	unsigned int ByteRate;
	unsigned short BlockAlign;
	unsigned short BitsPerSample;
};

/*\
AbstractAudio is the base class for all devices to be used in the
audio chain.  It provides the base implementation for negotiating sampling rate
and audio channels as well as the framework for passing audio samples through the
audio chain.
*/
class AbstractAudio
{
public:
	AbstractAudio(std::string name, AudioType type);
	
	/*
	getSamples() is the one method that needs to be implemented by
	the concrete child device.  For source devices, this is responsible
	for grabbing audio data from the 'source' (ex. reading samples from a file)
	and passing them on to the device requesting samples.  For process devices,
	they'll request samples from the Previous device via it's previous pointer,
	perform it's processing on those samples, and pass the processed samples on to
	the device requesting samples from it
	*/
	virtual int getSamples(float* buffer, int length) = 0;
	
	std::string getName() { return Name; }
	bool getByPass() { return ByPass; }
	void setByPass(bool b) { ByPass = b; }
	
	void setNext(AbstractAudio *n) { next = n; }
	void setPrevious(AbstractAudio *p) { previous = p; }

	virtual AudioFormatStruct getAudioFormat();
	virtual void reset(){}

protected:
	//Methods to negotiate Sampling Rat and # Channels in Audio Chain
	void NegotiateSamplingRate();
	void NegotiateNumberOfChannels();
	
	//Helper methods for negotiating Sampling Rate and # Channels
	virtual void MinMaxSamplingRate(int &min, int &max, int &preferred);
	virtual void MinMaxChannels(int &min, int &max, int &preferred);
	
	//Methods to set negotiated values to all devices in the chain
	void SetSamplingRateRecursive(int rate);
	void SetChannelsRecursive(int ch);


	//Pointers to next and previous devices in chain
	AbstractAudio *next, *previous;
	
	std::string Name;
	AudioType Type;
	unsigned int SamplingRate;
	unsigned short NumChannels;
	
	bool SamplingRateFrozen, NumChannelsFrozen, ByPass;

};

#endif