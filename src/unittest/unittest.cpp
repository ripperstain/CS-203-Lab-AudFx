
#include "cassert"
#include "base\unittest\AbstractAudioTest.h"
#include "devices\WavReader.h"
#include "devices\KaraokeProcessor.h"
#include "devices\PCMPlayer.h"
#include <iostream>

using namespace std;

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
	if (1){
		reader.setNext(&processor);
		processor.setPrevious(&reader);
		processor.setNext(&player);
		player.setPrevious(&processor);
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