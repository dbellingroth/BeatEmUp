#ifndef _SPRITE_LIB_
#define _SPRITE_LIB_

#include <iostream>
#include <string>
#include <map>
#include <list>

#include "spritearray.h"

typedef map<string, Sprite> SpriteMap;
typedef map<string, SpriteArray> SpriteListMap;
class SpriteLib {

private:
	SpriteMap sprites;
	SpriteMap::iterator sprites_it;

	SpriteListMap spriteArrays;
	SpriteListMap::iterator spriteArrays_it;

public:
	SpriteLib();
	virtual ~SpriteLib();

	Sprite* getSprite(const string sprite_name);
	bool deleteSprite(const string sprite_name);

	SpriteArray* getSpriteArray(const string name, int nx, int ny);
	bool deleteSpriteArray(const string name);

	bool deleteAll();

};

#endif
