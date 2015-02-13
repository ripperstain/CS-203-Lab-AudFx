#ifndef EQUALIZER_H
#define EQUALIZER_H

#include "base/AbstractAudio.h"
#include "Filters\IIRFilter.h"

class Equalizer : public AbstractAudio
{
public:
	Equalizer(std::string name);
	virtual int getSamples(float* buffer, int length);

	void Enable(bool Enabled){ enabled = Enabled; }
	bool isEnabled(){ return enabled; }

	void setLowGain(double lg){ low.setGain(lg); }
	void setLowMidGain(double lmg){ lowMid.setGain(lmg); }
	void setMidGain(double mg){ mid.setGain(mg); }
	void setHighMidGain(double hmg){ highMid.setGain(hmg); }
	void setHighGain(double hg){ high.setGain(hg); }

private:
	IIRFilter low;
	IIRFilter lowMid;
	IIRFilter mid;
	IIRFilter highMid;
	IIRFilter high;

	bool enabled;

};

#endif