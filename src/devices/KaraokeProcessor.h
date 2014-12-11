#pragma once;
#include "base\AbstractAudio.h"
#include "cassert"


class KaraokeProcessor : public AbstractAudio
{
public:
	KaraokeProcessor(std::string name);
	virtual int getSamples(float* buffer, int length);

	void Enable(bool enabled){ Enabled = enabled; }
	bool isEnabled(){ return Enabled; }

	virtual void setNext(AbstractAudio *n);
	virtual void setPrevious(AbstractAudio *p);

private:
	bool Enabled;

};