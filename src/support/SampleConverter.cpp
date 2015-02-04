#include "SampleConverter.h"

int SampleConverter::convertShortToFloat(short* inBuffer, float* outBuffer, int numSamples)
{
	int i;
	unsigned int offset = 1 << (sizeof(short)* 8 - 1);
	for (i = 0; i < numSamples; i++){
		outBuffer[i] = (float(inBuffer[i])) / offset;
	}
	return i;
}

int SampleConverter::convertFloatToShort(float* inBuffer, short* outBuffer, int numSamples)
{
	short tmp;
	unsigned int offset = 1 << (sizeof(short)* 8 - 1);
	int i = 0;
	for (i = 0; i < numSamples; i++){
		tmp = inBuffer[i] * offset;
		outBuffer[i] = tmp;// >> 8;
		//current->lpData[1 + i * 2] = (unsigned short)tmp >> 8;
	}
	return i;
}


int SampleConverter::convertUCharToFloat(unsigned char* inBuffer, float* outBuffer, int numSamples)
{
	int i;
	unsigned int offset = 1 << (sizeof(unsigned char)* 8 - 1);
	for (i = 0; i < numSamples; i++){
		outBuffer[i] = (float(inBuffer[i])) / offset;
	}
	return i;
}

int SampleConverter::convertFloatToUChar(unsigned char* outBuffer, float* inBuffer, int numSamples)
{
	int i;
	unsigned int offset = 1 << (sizeof(unsigned char)* 8 - 1);
	for (i = 0; i < numSamples; i++){
		outBuffer[i] = (inBuffer[i]) + offset;
	}
	return i;
}
