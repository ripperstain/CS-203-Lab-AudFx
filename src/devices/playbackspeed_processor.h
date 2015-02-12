#ifndef PLAYBACKSPEED_PROCESSOR_H
#define PLAYBACKSPEED_PROCESSOR_H

#include "base/AbstractAudio.h"
#include <string>
#include <fstream>
/*
PlaybackSpeedDevice provides a simple adjuster to speed up or slow down
the speed of the audio playback.  This device does not maintain pitch when
it speeds up or slows down playback, so the pitch will increase or decrease
with playback speed
*/
class PlaybackSpeedDevice : public AbstractAudio
{
public:
	//Sole constructor for PlaybackSpeedDevice
	//default playback speed is normal speed (1.0)
	PlaybackSpeedDevice(std::string fileName);

	//Use to set playback speed to adjust to
	//1.0 is normal speed, 0.5 would be half speed
	//2.0 would be double speed
	//Values must be greater than zero
	void SetPlaybackSpeed(float speed);

	//Get the currently set playback speed
	float GetPlaybackSpeed();

	//Method used by audio chain to get samples with speed
	//adjusted
	virtual int getSamples(float* buffer, int length);

private:

	float playback_speed;
	int input_buffer_length;
	float* input_buffer;
	float intermediate_point;
};



#endif