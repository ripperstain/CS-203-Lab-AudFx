#include "base\AbstractAudio.h"
#include "cassert"


class KaraokeProcessor : public AbstractAudio
{
public:
	KaraokeProcessor(std::string name);
	virtual int getSamples(char* buffer, int length);

};