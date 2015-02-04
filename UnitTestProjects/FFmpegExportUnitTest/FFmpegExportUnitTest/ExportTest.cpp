#include "../../../src/devices/FFmpegExporter.h"
void main()
{
	using namespace std;
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
	string sourceFile = "../../audio/norestforthewicked.wav";
	string outputFolder = "../../audio";
	string outputFileName = "TestOutput";
	string outputFileType = "mp3";

	ExportSongFile(sourceFile, outputFolder, outputFileName, outputFileType);
	

	//At the end of the unit test, there should be a song in the audio folder with the name TestOutput in mp3 format
}