#ifndef AUDIOFILEDECODER_H
#define AUDIOFILEDECODER_H

#include <string>
#include "Interfaces.h"
#include "AbstractAudio.h"


class AudioFileDecoder : public AbstractAudio
{
	AudioFileDecoder(std::string filename, ReadCompleteIF* rcif) : FileName(filename), readCompleteIF(rcif),
	AbstractAudio(filename, AudioType::Source)
	{}

	// Stage told to reset
	virtual void reset() = 0;
	
	// Read wave file and initialize appropriate decoder
	virtual bool initializeDecoder() = 0;

protected:
	//Helper methods for negotiating Sampling Rate and # Channels
	virtual void MinMaxSamplingRate(int &min, int &max, int &preferred);
	virtual void MinMaxChannels(int &min, int &max, int &preferred);


	std::string FileName;
	ReadCompleteIF* readCompleteIF;
	AbstractDecoderIF* decoder;
};

#endif