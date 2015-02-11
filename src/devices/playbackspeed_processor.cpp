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
	int compute_buffer_size = (int)(length * playback_speed);
	compute_buffer_size -= compute_buffer_size % 2;
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
	do{
		assert(out_index != length); 
		int left_index1 = sample_point;
		int left_index2 = left_index1 + 2;

		int right_index1 = left_index1 + 1;
		int right_index2 = left_index2 + 1;

		float interpolation_point = sample_point - left_index1;

		float interpolated_sample = input_buffer[left_index1] * interpolation_point +
			input_buffer[left_index2] * (1 - interpolation_point);
		buffer[out_index++] = interpolated_sample / 2.0f;

		interpolated_sample = input_buffer[right_index1] * interpolation_point +
			input_buffer[right_index2] * (1 - interpolation_point);
		buffer[out_index++] = interpolated_sample / 2.0f;

		sample_point += 2 + playback_speed;
		
		
	}while (out_index < length && sample_point < samples_received);

	if (sample_point > samples_received){
		intermediate_point = sample_point - samples_received;
	} else{
		intermediate_point = 0.0f;
	}
	
	return out_index;
}