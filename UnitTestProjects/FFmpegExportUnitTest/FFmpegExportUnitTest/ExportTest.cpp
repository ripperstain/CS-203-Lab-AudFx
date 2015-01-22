#include <Windows.h>
void main()
{
	//To access the ffmpeg convert exe, keep the first part completely the same. Always use
	//
	//cd /d ../../../ffmpeg/exe && ffmpeg.exe -i
	//
	//The first parameter dictates the file path of the input song file and type
	//The second parameter dictates the output file location and type. 
	//
	system("cd /d ../../../ffmpeg/exe && ffmpeg.exe -i  ../../audio/Output2.wma ../../audio/Output3.wav");
}