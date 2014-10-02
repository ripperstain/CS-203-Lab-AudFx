#ifndef WAVREAD_H
#define WAVREAD_H

#include "AudioFileDecoder.h"

class WavRead : public AudioFileDecoder
{
public:
	WaveRead(String fileName, ReadCompleteIF readCompleteIF);
	virtual void reset();
	virtual bool initializeDecoder();
	
protected:
	virtual int getSamples(int16* buffer, int length);
	
private:

};