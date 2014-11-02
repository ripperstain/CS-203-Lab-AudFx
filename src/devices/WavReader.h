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
	AudioFormatStruct getAudioFormat(){ return AudioFormat; }

protected:
	virtual int getSamples(float* buffer, int length);
private:
	std::ifstream infile;
	AudioFormatStruct AudioFormat;

	int get8bitSamples(float* buffer, int length);
	int get16bitSamples(float* buffer, int length);
	int get24bitSamples(float* buffer, int length);

};

template <class T>
//Read in a block of Audio data (not for use reading header data)
int getAudioBlock(std::ifstream &infile, T *data, int size)
{
	if (!infile) return 0;
	int index = -1;

	while (infile){
		index++;
		if (index == size) break;
		data[index] = 0;
		infile.read((char*)&data[index], sizeof(data[index]));

	}


	return index;
}

#endif