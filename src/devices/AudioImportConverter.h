#include <string>
#include <stdlib.h>
#include <windows.h>

//This function takes in a wav file and then creates a .wav file in the same folder to be used for
//audio processing and effects. 
//
// It takes one parameter labled filepath, which should take the format of 
// Ex: ../../audio/hotelcalifornia.mp3
// Or any other desired filetype that you're opening.

void AudioImportConverter(std::string filepath)
{
	std::string desired_file_type = ".wav";		//You can replace the .wav if desired, but all our audio functions
	std::string commandline;					//rely on .wav format
	std::string original_filepath = filepath;		//Keeps the filepath name intact. This may be useful for future updates
	std::string new_filepath = filepath;

	//Remove the file extension by searching through the string and removing things after the .
	const size_t period_idx = new_filepath.rfind('.');
	if (std::string::npos != period_idx)
	{
		new_filepath.erase(period_idx);
	}

	new_filepath = new_filepath + desired_file_type;

	//Command line for ffmpeg has the following format: cd /d ../../../ffmpeg/exe && ffmpeg.exe -i exampleinput.wav exampleoutput.mp3
	commandline = "cd /d ../../../ffmpeg/exe && ffmpeg.exe -i " + original_filepath + " " + new_filepath;

	const char * c = commandline.c_str();	//converts the file to a .wav
	system(c);
}