#ifndef AUDIOFILEDECODER_H
#define AUDIOFILEDECODER_H

#include <string>
#include "Interfaces.h"
#include "AbstractAudio.h"


class AudioFileDecoder : public AbstractAudio
{
	AudioFileDecoder(String fileName, ReadCompleteIF rcIF) : FileName(filename), readCompleteIF(rcif) 
	{}

	// Stage told to reset
	virtual void reset() = 0;
	
	// Read wave file and initialize appropriate decoder
	virtual boolean initializeDecoder() = 0;

protected:
	std::string FileName;
	ReadCompleteIF* readCompleteIF;
	AbstractDecoderIF* decoder;
};

#endif