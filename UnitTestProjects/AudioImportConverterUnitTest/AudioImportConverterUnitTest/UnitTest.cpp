#include <iostream>
#include "../../../src/devices/AudioImportConverter.h"

void main()
{
	//Edit this file name as needed. In the main program this willl be substituted with a 
	//real file name. This is merely an example.
	std::string sourceFile = "../../audio/hotelcalifornia.mp3";
	AudioImportConverter(sourceFile);
	std::cout << "Check the audio folder in the github directory to see if a .wav file has appeared!" << std::endl;

}