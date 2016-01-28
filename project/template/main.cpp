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
	Bec3 mySession = Bec3( "assets/conf/Bec3.json" );
	Key Right = Key("Right", &mySession);
	Key Left = Key("Left", &mySession);
    signal(SIGINT, stopSignal); 
	
	while(done){
		mySession.updateObjects();
		Right.simulate();
		Left.simulate();
	}
	
    return 0;
}
