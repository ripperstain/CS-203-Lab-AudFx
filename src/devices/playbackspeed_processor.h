#ifndef PLAYBACKSPEED_PROCESSOR_H
#define PLAYBACKSPEED_PROCESSOR_H

#include "base/AbstractAudio.h"
#include <string>
#include <fstream>

class PlaybackSpeedDevice : public AbstractAudio
{
public:
	PlaybackSpeedDevice(std::string fileName);

	void SetPlaybackSpeed(float speed);
	float GetPlaybackSpeed();
	virtual int getSamples(float* buffer, int length);

private:
	float playback_speed;
	int input_buffer_length;
	float* input_buffer;
	float intermediate_point;
};



#endif