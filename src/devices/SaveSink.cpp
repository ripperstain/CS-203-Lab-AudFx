#include "SaveSink.h"

#ifdef CONSOLEOUT
#include <iostream>
#endif

using namespace std;

SaveSink::SaveSink(string name, string filepath) : AbstractAudio(name, AudioType::Sink){
	ofstream outputBuffer(filepath, ios::out | ios::binary);
}

SaveSink::~SaveSink() {
	
}

SaveSink::