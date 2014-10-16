#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "KaraokeProcessor.h"

KaraokeProcessor::KaraokeProcessor() {
	struct stat results;

	std::ifstream openFile("C:\\Users\\Jeremy\\Downloads\\Problems.wav", std::ios::binary);
	std::ofstream saveFile("C:\\Users\\Jeremy\\Downloads\\ProblemsKareoke.wav", std::ios::binary);

	if (!openFile.is_open()) std::cout << "Error" << std::endl;

	char header[44];

	int lastCall = 0;
	int currentPosition = 44;

	//get file size
	stat("C:\\Users\\Jeremy\\Downloads\\Problems.wav", &results);
	std::cout << results.st_size << std::endl;

	const int size = results.st_size;

	//char ramMusic[size];

	char waveHeader[44];
	//Copy header
	openFile.read(waveHeader, 44);
	saveFile.write(waveHeader, 44);

	const float coefficent = 0.7;

	short oldLeft, oldRight, newLeft, newRight;

	while (!openFile.eof()){
		openFile.read((char *)&oldLeft, sizeof(oldLeft));
		openFile.read((char *)&oldRight, sizeof(oldRight));

		newLeft = (oldLeft - oldRight) / 2;
		newRight = (oldRight - oldLeft) / 2;

		saveFile.write((char *)&newLeft, sizeof(newLeft));
		saveFile.write((char *)&newRight, sizeof(newRight));

		currentPosition += 2;
		lastCall++;
		if (lastCall > 1000000) {
			std::cout << currentPosition << std::endl;
			lastCall = 0;
		}

	}


	std::cout << "Done at: " << currentPosition << std::endl;
}