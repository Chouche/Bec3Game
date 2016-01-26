#include "FakeKeyboard.hpp"

void SimuleKeyboard(bool state, std::string key){

  std::string KEY =key;

  if(state==true){

    system(("xdotool keydown " + KEY).c_str());
    system(("xdotool keyup " + KEY).c_str());
  }



}
