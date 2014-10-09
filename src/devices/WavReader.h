#ifndef WAVREADER_H
#define WAVREADER_H

#include "base\AudioFileDecoder.h"
#include <string>
#include <fstream>

class WavReader : public AudioFileDecoder
{
public:
	WavReader(std::string fileName);
	virtual void reset();
	virtual bool initializeDecoder();
	
protected:
	virtual int getSamples(char* buffer, int length);
private:
	std::ifstream infile;
};

#endif