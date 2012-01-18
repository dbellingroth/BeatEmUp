

#ifndef _INPUTLISTENER_
#define _INPUTLISTENER_

#include "gameobject.h"
#include "dep.h"


class InputListener {

	public:
	virtual void input( SDL_Event event ) = 0;
	//virtual void joystickInput( SDL_Event* event ) = 0;	

};


#endif