#include "playbackspeed_processor.h"
#include <cassert>

using namespace std;

PlaybackSpeedDevice::PlaybackSpeedDevice(string fileName) : AbstractAudio(fileName, AudioType::Processor)
{
	input_buffer = nullptr;
	input_buffer_length = 0;
	playback_speed = 1.0f;
	intermediate_point = 0.0f;
}

void PlaybackSpeedDevice::SetPlaybackSpeed(float speed)
{
	if (speed <= 0) return;
	playback_speed = speed;
}

float PlaybackSpeedDevice::GetPlaybackSpeed()
{
	return playback_speed;
}

int PlaybackSpeedDevice::getSamples(float* buffer, int length)
{
	int compute_buffer_size = length * playback_speed;

	//Create or recreate the input buffer if playback_speed has changed
	if (compute_buffer_size != input_buffer_length){
		if (input_buffer != nullptr){
			delete input_buffer;
			input_buffer = nullptr;
		}
		input_buffer_length = compute_buffer_size;
		input_buffer = new float[input_buffer_length];
	}

	int samples_received = previous->getSamples(input_buffer, input_buffer_length);
	float sample_point = intermediate_point;
	int out_index = 0;
	for (int i = 0; i < samples_received && sample_point < samples_received; i++){
		assert(out_index != length); 
		int index1 = sample_point;
		int index2 = index1 + 1;
		float interpolation_point = sample_point - index1;
		float interpolated_sample = input_buffer[index1] * (1 - interpolation_point) +
			input_buffer[index2] * interpolation_point;
		
		buffer[out_index] = interpolated_sample / 2.0f;
		sample_point += playback_speed;
		out_index++;
		
	}
	if (sample_point > samples_received){
		intermediate_point = sample_point - samples_received;
	} else{
		intermediate_point = 0.0f;
	}
	
	return out_index;
}