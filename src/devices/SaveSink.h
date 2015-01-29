#ifndef SAVESINK_H
#define SAVESINK_H

#include "..\base\AbstractAudio.h"
#include <fstream>
#include <string>
#include <Windows.h>
#define BLOCK_SIZE 4096
class SaveSink : public AbstractAudio
{
public:
	SaveSink(std::string name);
	~SaveSink();
	bool saveWav(std::string filepath);
	int getSamples(float* buffer, int length) { return 0; }

private:
	
};

#endif