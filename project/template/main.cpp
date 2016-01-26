#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <Bec3/Bec3.hpp>

#include "FakeKeyboard.hpp"
#include "debug.hpp"
#include "rapidjson/document.h"

using namespace std;
using namespace glimac;
using namespace rapidjson;

int main(int argc, const char **argv) {
	bool test=false,testA=false,testZ=false,testE=false,testR=false,testQ=false,testS=false,testD=false,testF=false;
	bool state,stateA,stateZ,stateE,stateR,stateQ,stateS,stateD,stateF;
	Bec3 mySession = Bec3( "assets/conf/Bec3.json" );

	//Test d'affichage des objects sur la platerforme Bec3
	for(int i = 0; i < 500000000; ++i){
		mySession.updateObjects();
		state	 = mySession.getObjectState( "X" ).getBool();

		if(test!=state){
			SimuleKeyboard(state, "x");
			test = state;
		}

		


		//cout << "TestLight: " << mySession.getObjectState( "TestLight" ).getBool() << endl;
	}


	//cout << "MSG: "       << mySession.getObjectState( "MSG" ).getString()     << endl;


    return 0;
}
