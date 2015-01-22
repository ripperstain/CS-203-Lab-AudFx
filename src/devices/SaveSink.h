#ifndef SAVESINK_H
#define SAVESINK_H

#include "..\base\AbstractAudio.h"
#include <fstream>
#include <string>
class SaveSink : public AbstractAudio
{
public:
	SaveSink(std::string name, string filepath);
	~SaveSink();

	int getSamples(float* buffer, int length) { return 0; }

private:
	
};

#endif