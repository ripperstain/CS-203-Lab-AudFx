#include "..\devices\SaveSink.h"
#include "..\devices\WavReader.h"
#include "cassert"

#include <iostream>

using namespace std;

int main()
{
	cout << "Running SaveSink Unit Test... " << endl;
	string filename = "..\\..\\..\\audio\\norestforthewicked.wav";
	string filename2 = "..\\..\\..\\audio\\norestforthewickedCOPY2.wav";

	SaveSink saver("Saver");
	WavReader reader(filename);

	if (1){

		reader.setNext(&saver);
		saver.setPrevious(&reader);

		saver.saveWav(filename2);

	}

	cout << "Test completed." << endl;
	system("pause");

	return 0;

}