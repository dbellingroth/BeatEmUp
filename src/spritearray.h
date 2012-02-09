#ifndef _SPRITE_ARRAY_
#define _SPRITE_ARRAY_

#include "sprite.h"
#include <list>
#include <string>
using namespace std;

typedef list<Sprite> spriteList;
class SpriteArray: public Drawable, public Transformable {

private:
	spriteList sprites;
	spriteList::iterator it;

	float displayTime, displayedTime; //Bei animation = true: Anzeigedauer in Milisekunden / Bild
	spriteList::iterator currentSprite;
	spriteList::iterator loopStart, loopEnding;
	bool animation, loop;

public:
	SpriteArray(const string image_path, int nx, int ny);
	virtual ~SpriteArray();

	void setCurrent(int index);
	void enableAnimation() {
		animation = true;
	}
	void disableAnimation() { animation = false; }
	void setDisplayTime(float displayTime) { this->displayTime = displayTime; }
	void enableLoop() { animation = true, loop = true; }
	void disableLoop() { this->loop = false; }
	bool setLoop( int loopStart, int loopEnding );
	void update( int delta );
	void draw();
};

#endif
