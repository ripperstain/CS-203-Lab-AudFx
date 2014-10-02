#ifndef INTERFACES_H
#define INTERFACES_H

class ReadCompleteIF
{
	virtual void signalReadComplete() = 0;
};

class AbstractDecoderIF
{
	virtual std::string getName() = 0;
	virtual int getSamples(char* buffer, int length) = 0;
};

class NegotiationCompleteIF {

	virtual void signalNegotiationComplete() = 0;
};


#endif