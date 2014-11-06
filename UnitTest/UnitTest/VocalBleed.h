#include "base\AbstractAudio.h"
#include "cassert"


class VocalBleed : public AbstractAudio
{
public:
	VocalBleed(std::string name);
	virtual int getSamples(float* buffer, int length);

	void Enable(){ Enabled = true; }
	void Disable(){ Enabled = false; }
	bool isEnabled(){ return Enabled; }

private:
	bool Enabled;
};
