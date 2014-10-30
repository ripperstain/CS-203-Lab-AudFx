
#include "cassert"
#include "base\unittest\AbstractAudioTest.h"
#include "devices\WavReader.h"
#include "devices\KaraokeProcessor.h"
#include "devices\PCMPlayer.h"
#include "devices\Filters\GainFilter.h"
#include <iostream>

using namespace std;
void testgain();

int main()
{
	cout << "Testing AbstractAudio class via derived test classes" << endl;
	//AATestSource source("Source");
	KaraokeProcessor processor("Processor");
	AATestSink sink("Sink");
	PCMPlayer player("Player");
	WavReader reader("..\\..\\audio\\norestforthewicked.wav");

	//Set up the links of our audio chain
	//Source is always the first device in the chain
	//so it does not have a previous link
	//Sink is always the last device in the chain
	//so it does not have a next link
	testgain();
	if (1){
		reader.setNext(&player);
		//processor.setPrevious(&reader);
		//processor.setNext(&player);
		player.setPrevious(&reader);
		devicelist devs = player.GetDevices();
		for (auto it = devs.begin(); it != devs.end(); ++it){
			wcout << *it << endl;
		}
		player.play();
		char cmd;
		bool stop = false;
		while (stop == false){
			cin >> cmd;
			switch (cmd){
			case 'p':
				if (player.isPlaying()){
					player.pause();
				}
				else{
					player.play();
				}
				break;
			case 's':
				player.stop();
				break;
			case 'x':
				stop = true;
				break;
			}
		}
		//system("pause");
		//player.stop();
	}
	else{
		reader.setNext(&processor);
		processor.setPrevious(&reader);
		processor.setNext(&sink);
		sink.setPrevious(&processor);

		bool res = sink.RunTest();
	}
	cout << "Test completed." << endl;
	system("pause");

	return 0;
}
void testgain()
{

	//Testing if the gain filter modifies values 
	//miltiplier: 2
	float g;
	g = 2;

	GainFilter gain1("gaintest");
	AATestSource source("Source");

	source.setNext(&gain1);
	gain1.setPrevious(&source);

	gain1.setgain(g);

	//get samples and verify
	const int bufsize = 10;
	unsigned char* mybuf = new unsigned char[bufsize];
	int samplesReturned = gain1.getSamples((char*)mybuf, bufsize);

	assert(samplesReturned == bufsize);

	for (int i = 0; i < samplesReturned; i++){
		cout << " Verifying element " << i << " is i * 2 = " << i * 2 << " : ";
		cout << (int)mybuf[i] << endl;
		assert(mybuf[i] == i * 2);
	}

	delete mybuf;

}