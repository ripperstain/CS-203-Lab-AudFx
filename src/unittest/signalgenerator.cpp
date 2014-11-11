#include "signalgenerator.h"



using namespace std;
SignalGenerator::SignalGenerator(string name) : AbstractAudio(name, AudioType::Source)
{
	 signalType = eSignalType::SquareWave;
	 frequency = 440;
	 amplitude = 0.6F;
}

void SignalGenerator::setSquareWave(float* buffer, int length)
{
	AudioFormat = previous->getAudioFormat();
	int interval = AudioFormat.SampleRate / frequency;
	bool high = false;
	int count = 0;
	for (int i = 0; i < length; i++){
		if (high){
			buffer[i] = amplitude;
		}
		else{
			buffer[i] = -amplitude;
		}
		count++;
		if (count == interval){
			count = 0;
			high = !high;
		}
	}
}

int SignalGenerator::getSamples(float* buffer, int length)
{
	previous->getSamples(buffer, length);
	switch (signalType){
	case eSignalType::SquareWave:
		setSquareWave(buffer, length);
		break;
	}
	return length;
}