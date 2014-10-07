
#include "cassert"
#include "base\unittest\AbstractAudioTest.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "Testing AbstractAudio class via derived test classes" << endl;
	AATestSource source("Source");
	AATestProcessor processor("Processor");
	AATestSink sink("Sink");

	//Set up the links of our audio chain
	//Source is always the first device in the chain
	//so it does not have a previous link
	//Sink is always the last device in the chain
	//so it does not have a next link
	source.setNext(&processor);
	processor.setPrevious(&source);
	processor.setNext(&sink);
	sink.setPrevious(&processor);

	bool res = sink.RunTest();
	
	cout << "Test completed successfully" << endl;
	system("pause");

	return 0;
}