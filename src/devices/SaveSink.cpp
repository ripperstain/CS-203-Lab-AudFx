#include "SaveSink.h"
#include "../support/SampleConverter.h"

#ifdef CONSOLEOUT
#include <iostream>
#endif

using namespace std;

SaveSink::SaveSink(string name) : AbstractAudio(name, AudioType::Sink){
	
}

SaveSink::~SaveSink() {
	
}

bool SaveSink::saveWav(string filepath){
	if (!NegotiateParameters()){
		return false;
	}
	if (previous == nullptr){
		return false;
	}

	AudioFormat = previous->getAudioFormat();

	WAVEFORMATEX wf;
	wf.nSamplesPerSec = AudioFormat.SampleRate;
	wf.wBitsPerSample = AudioFormat.BitsPerSample;
	wf.nChannels = AudioFormat.NumChannels;
	wf.cbSize = 0; // unused
	wf.wFormatTag = WAVE_FORMAT_PCM;
	wf.nBlockAlign = (wf.wBitsPerSample * wf.nChannels) >> 3;
	wf.nAvgBytesPerSec = wf.nBlockAlign * wf.nSamplesPerSec;

	ofstream outputBuffer(filepath, ios::out | ios::binary);

	float buffer[BLOCK_SIZE];
	unsigned char saveBuffer[BLOCK_SIZE];

	//get header stuff here
	//write the header to the begining of the file

	char RIFF_marker[4] = { 'R', 'I', 'F', 'F' };
	int overall_filesize;
	char WAVE_fth[4] = { 'W', 'A', 'V', 'E' };
	char fmt_format_chunk_marker[4] = { 'f', 'm', 't', NULL }; //Trailing null
	int length_of_format = 16; //16?
	short type_format = 1; //PCM is 1
	short num_channels = wf.nChannels;
	int sample_rate = wf.nSamplesPerSec;
	int sbc = (wf.nSamplesPerSec * wf.wBitsPerSample * wf.nChannels) /8; //(Sample Rate * BitsPerSample * Channels) / 8.
	short bitsize;//(BitsPerSample * Channels) / 8
	int bits_per_sample = wf.wBitsPerSample;
	char data_header[4] = { 'd', 'a', 't', 'a' }; //data header marked "data"
	int file_size; //data - size(equals file - size - 44).


	//write the individual samples to the rest of the file

	//check for what size samples they are/were
	while (1) {
		DWORD readBytes;
		readBytes = previous->getSamples(buffer, BLOCK_SIZE);

		SampleConverter::convertFloatToUChar(saveBuffer, buffer, BLOCK_SIZE);

		outputBuffer.write(reinterpret_cast<const char*>(saveBuffer), BLOCK_SIZE);

		if (readBytes == 0) break;
	}

	return true;
}

bool SaveSink::NegotiateParameters()
{
	NegotiateSamplingRate();
	NegotiateNumberOfChannels();
	SetBufferSizeRecursive(BLOCK_SIZE);
	return true;
}