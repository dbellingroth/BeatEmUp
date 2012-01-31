
#ifndef _GAME_
#define _GAME_

#include "gameobject.h"
#include "inputlistener.h"
#include "drawable.h"

class Game: public GameObject, public Drawable, public InputListener {

};

#endif
