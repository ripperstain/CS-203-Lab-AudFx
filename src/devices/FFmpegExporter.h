#include <cstdlib>
#include <string>
#include <windows.h>

//To utilize the ffmpeg converter, a command line prompt is run

// Function requires four string parameters. All actual parameters should not contain "" like in the examples
// sourceFile:       The file location of the song being converted. This string should 
//			         include the filename as well as the file type
//					 Ex. "../../audio/song.wav"
// outputFolder:     The raw file location of where the converted song will be stored
//                   Ex.. "../../audio"
// outputFileName:   What the user wishes to name their converted audio file
//                   Ex: "newsong"
// outputFileType:   The desired file type of the exported file
//					 Ex: "mp3"
void ExportSongFile(std::string sourceFile, std::string outputFolder, std::string outputFileName, std::string outputFileType)
{
	std::string commandline;

	//Command line for ffmpeg has the following format: cd /d ../../../ffmpeg/exe && ffmpeg.exe -i exampleinput.wav exampleoutput.mp3
	commandline = "cd /d ../../../ffmpeg/exe && ffmpeg.exe -i " + sourceFile + " " +
		outputFolder + "/" + outputFileName + "." + outputFileType;

	const char * c = commandline.c_str();
	system(c);
	
}