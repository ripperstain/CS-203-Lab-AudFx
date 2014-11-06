#ifndef SAMPLECONVERTER_H
#define SAMPLECONVERTER_H


class SampleConverter
{
public:
	static int convertShortToFloat(short* inBuffer, float* outBuffer, int numSamples);
	static int convertFloatToShort(float* inBuffer, short* outBuffer, int numSamples);

	static int convertUCharToFloat(unsigned char* inBuffer, float* outBuffer, int numSamples);
	static int convertFloatToUChar(unsigned char* inBuffer, float* outBuffer, int numSamples);
};
#endif