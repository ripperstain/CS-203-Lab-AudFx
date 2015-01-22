#ifndef SAVESINK_H
#define SAVESINK_H

#include "..\base\AbstractAudio.h"

class SaveSink : public AbstractAudio
{
public:
	SaveSink(std::string name);
	~SaveSink();

	int getSamples(float* buffer, int length) { return 0; }

private:
	
};

#endif