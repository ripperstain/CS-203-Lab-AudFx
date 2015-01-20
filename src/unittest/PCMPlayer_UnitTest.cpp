#include "PCMPlayer_UnitTest.h"

#include "devices\PCMPlayer.h"
#include "devices\WavReader.h"
#include "cassert"

#include <iostream>

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

	if (1){

		devicelist devs = player.GetDevices();
		for (auto it = devs.begin(); it != devs.end(); ++it){
		wcout << *it << endl;
		}

		reader.setNext(&player);
		player.setPrevious(&reader);

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