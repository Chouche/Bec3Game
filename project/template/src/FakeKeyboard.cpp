#include <iostream>
#include "FakeKeyboard.hpp"

Key::Key(){}

Key::Key(std::string key, Bec3 *session){
	keySession = session;
	id = key;
	previousState = false;
}

Key::~Key(){}

void Key::simulate(){
	bool state = keySession->getObjectState(id.c_str()).getBool();
	//std::cout << state << std::endl;
	if(state != previousState){
		if(state==true)
			system(("xdotool keydown " + id).c_str());
		else
			system(("xdotool keyup " + id).c_str());
		previousState = state;
	}
}
