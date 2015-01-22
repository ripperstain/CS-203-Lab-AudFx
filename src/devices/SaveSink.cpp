#include "SaveSink.h"

#ifdef CONSOLEOUT
#include <iostream>
#endif

using namespace std;

SaveSink::SaveSink(string name) : AbstractAudio(name, AudioType::Sink){
	
}

SaveSink::~SaveSink() {
	
}