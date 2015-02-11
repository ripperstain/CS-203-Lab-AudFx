
#include <iostream>
#include "cassert"

#include "PCMPlayer_UnitTest.h"
#include "devices\PCMPlayer.h"
#include "devices\WavReader.h"
#include "devices\playbackspeed_processor.h"

using namespace std;

bool PCMPlayerTest::RunTest()
{

	return false;
}

int main()
{
	cout << "Running PCMPlayer Unit Test... " << endl;
	string filename = "..\\..\\..\\audio\\norestforthewicked.wav";

	PCMPlayer player("Player");
	WavReader reader(filename);
	PlaybackSpeedDevice speed("Speed Adjuster");

	if (1){

		devicelist devs = player.GetDevices();
		for (auto it = devs.begin(); it != devs.end(); ++it){
		wcout << *it << endl;
		}

		reader.setNext(&speed);
		speed.setPrevious(&reader);
		speed.setNext(&player);
		player.setPrevious(&speed);
		speed.SetPlaybackSpeed(1.25);

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
	}

	cout << "Test completed." << endl;
	system("pause");

	return 0;

}