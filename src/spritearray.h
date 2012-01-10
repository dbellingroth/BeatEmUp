
#ifndef _SPRITE_ARRAY_
#define _SPRITE_ARRAY_

#include "sprite.h"
#include <list>
#include <string>
using namespace std;


typedef list<Sprite*> spriteList;
class SpriteArray : public Drawable, public Transformable {

	private:
	spriteList sprites;
	spriteList::iterator it;

		
	float displayTime, displayedTime;	//Bei ANIMATION: Anzeigedauer in Milisekunden
	spriteList::iterator currentSprite;
	spriteList::iterator loopStart, loopEnding;
	bool animation, loop;

		
	public:
	SpriteArray( const string image_path, int nx, int ny );
	virtual ~SpriteArray();

	void enableAnimationMode() { animation = true; }
	void disableAnimationMode() { animation = false; }
	void setDisplayTime( float displayTime ) { this->displayTime = displayTime; }
	bool setLoop( int loopStart, int loopEnding );
	void update( int delta );
	void draw();
};

#endif