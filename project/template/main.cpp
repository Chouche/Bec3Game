#include <iostream>
#include <string>
#include <signal.h>
#include <Bec3-lib/Bec3.hpp>

#include "FakeKeyboard.hpp"

using namespace std;

volatile sig_atomic_t done = 1;

void stopSignal(int sig){
  done = 0;
}

int main(int argc, const char **argv) {
	bool test=false;
	bool state;
	Bec3 mySession = Bec3( "assets/conf/Bec3.json" );
	
    signal(SIGINT, stopSignal); 
	
	while(done){
		mySession.updateObjects();
		state = mySession.getObjectState( "X" ).getBool();

		if(test!=state){
			SimuleKeyboard(state, "x");
			test = state;
			
		}
	}
	
    return 0;
}
