#ifndef PCMPLAYER_H
#define PCMPLAYER_H

#include "AbstractAudio.h"

class PCMPlayer : public AbstractAudio
{
public:

	bool NegotiateParameters();
	bool play();
	void stop();
protected:

private:

};

#endif