#include "WavReader.h"
#include <iostream>


using namespace std;

WavReader::WavReader(string fileName) : AudioFileDecoder(fileName, nullptr)
{
	FileName = fileName;
	infile.open(FileName, ios::binary | ios::in);
	initializeDecoder();

}


void WavReader::reset()
{
	

}


//Read in a Little Endian Unsigned Int (4 bytes)
void getLEInt(ifstream &infile, unsigned int& data);
//Read in a Little Endian Unsigned Short (2 bytes)
void getLEShort(ifstream &infile, unsigned short& data);
//Read in a 4 byte ASCII tag (useful for RIFF, WAVE, and 'fmt ')
void getTag(ifstream &infile, string &tag);
//Read in a block of Audio data (not for use reading header data)
int getAudioBlock(ifstream &infile, char *data, int size);


int WavReader::getSamples(char* buffer, int length)
{
	memset(buffer, 0, length);
	int size = getAudioBlock(infile, buffer, length);

	return size;
	
}

bool WavReader::initializeDecoder()
{
     
    string tag;
    unsigned int filesize;
    //unsigned int SampleRate, ByteRate;
    unsigned short AudioFormat, BlockAlign, BitsPerSample;
    char *audioData = nullptr;
    bool played = false, audioLoaded = false;
 
    
	if (!infile.is_open()){
		return false;
	}
    getTag(infile, tag);
#ifdef CONSOLEOUT
    cout << tag << endl;
#endif
	if (tag != "RIFF"){
		return false;
	}

	//filesize
    getLEInt(infile, filesize);
	//wav tag
    getTag(infile, tag);
#ifdef CONSOLEOUT
    cout << tag << endl;
#endif
	if (tag != "WAVE"){
		return false;
	}
	getTag(infile, tag);
#ifdef CONSOLEOUT
	cout << tag << endl;
#endif
	if (tag != "fmt "){
		return false;
	}
	getLEInt(infile, chunksize);

	//Audio Format 2 bytes
	getLEShort(infile, AudioFormat);
	//Num Channels 2 bytes
	getLEShort(infile, NumChannels);
	//Sample Rate 4 bytes
	getLEInt(infile, SamplingRate);
	//Byte Rate 4 bytes
	getLEInt(infile, ByteRate);
	//Block Align 2 bytes
	getLEShort(infile, BlockAlign);
	//Bits Per Sample 2 bytes
	getLEShort(infile, BitsPerSample);
#ifdef CONSOLEOUT 
	cout << "Filesize:        " << filesize << endl;
	cout << "Chunksize:       " << chunksize << endl;
	cout << "Audio Format:    " << AudioFormat << endl;
	cout << "Num Channels:    " << NumChannels << endl;
	cout << "Sample Rate:     " << SamplingRate << endl;
	cout << "Byte Rate:       " << ByteRate << endl;
	cout << "Block Align:     " << BlockAlign << endl;
	cout << "Bits Per Sample: " << BitsPerSample << endl;
#endif 
	getTag(infile, tag);
	if (tag != "data"){
		return false;
	}
	getLEInt(infile, DataSize);
#ifdef CONSOLEOUT
	cout << "DataSize:        " << DataSize << endl << endl;
#endif
	audioData = new char[20];
	getAudioBlock(infile, audioData, 20);
	return true;

}


//Read in a Little Endian Unsigned Int (4 bytes)
void getLEInt(ifstream& infile, unsigned int& data)
{
	unsigned char inchar[4];
	for (int i = 0; i < 4; i++){
		if (infile.eof() == false){
			inchar[i] = infile.get();
		}
	}
	data = inchar[0] | (inchar[1] << 8) | (inchar[2] << 16) | (inchar[3] << 24);
}

//Read in a Little Endian Unsigned Short (2 bytes)
void getLEShort(ifstream& infile, unsigned short& data)
{
	unsigned char inchar[2];
	for (int i = 0; i < 2; i++){
		if (infile.eof() == false){
			inchar[i] = infile.get();
		}
	}
	data = inchar[0] | (inchar[1] << 8);
}

//Read in a 4 byte ASCII tag
void getTag(ifstream& infile, string &tag)
{
	char inchar;
	tag = "";
	for (int i = 0; i < 4; i++){
		if (infile.eof() == false){
			inchar = infile.get();
			tag += inchar;
		}
	}
}

//Read in a block of Audio data (not for use reading header data)
int getAudioBlock(ifstream &infile, char *data, int size)
{
	if (!infile) return -1;
	int index = 0;
	
	infile.read(data, size);
	index = infile.gcount();

	if (!infile){
#ifdef CONSOLEOUT
		cout << "Failed to read in audio data." << endl;
		cout << "Only read in " << index << " bytes." << endl;
#endif
		return -1;
	}

	return index;
}