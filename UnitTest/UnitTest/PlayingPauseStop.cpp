#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <windows.h>
#include<mmsystem.h>
#include<stdlib.h>
using namespace std;

int main(char argc)
{
	//Playing A WAV File
	PlaySound(TEXT("C:/EXAMPLE.wav"), NULL, SND_FILENAME | SND_ASYNC);

	//Stopping A WAV File
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
}