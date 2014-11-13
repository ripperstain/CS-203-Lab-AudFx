#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include "base\AbstractAudio.h"

enum class eSignalType
{
	SignWave,
	SquareWave,
	TriangleWave
};

class SignalGenerator : public AbstractAudio
{
public:
	SignalGenerator(std::string name);
	int getSamples(float* buffer, int length);
private:
	eSignalType signalType;
	AudioFormatStruct AudioFormat;
	int frequency;
	float amplitude;

	void setSquareWave(float* buffer, int length);
};

#endif