#ifndef FAKEKEYBOARD_HPP
#define FAKEKEYBOARD_HPP

#include <string>
#include <Bec3-lib/Bec3.hpp>

class Key {
	private :
		Bec3 *keySession;
		std::string id;
		bool previousState;
	
	public :
		Key();
		Key(std::string key, Bec3 *session);
		~Key();
		void simulate();
};

#endif
