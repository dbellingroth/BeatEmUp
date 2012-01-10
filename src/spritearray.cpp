
#include "spritearray.h"
#include <cmath>


SpriteArray::SpriteArray( const string image_path, int nx, int ny ) 
											: displayTime( 0 ),
											  displayedTime( 0 ),
											  currentSprite( 0 ),
											  loopStart( sprites.begin() ),
											  loopEnding( (sprites.end())-- ),
											  loop( false ) {

	sprites = Sprite::getSubImages( image_path, nx, ny );

}



SpriteArray::~SpriteArray() {

}


void SpriteArray::update(int delta) {
		
	if ( animation ) {
		
		displayedTime += (delta * pow(10, -3));
		
		if (displayedTime >= displayTime) {
			
			displayedTime = 0;
			currentSprite++;
			
			if ( currentSprite == ( loop ? loopEnding : sprites.end() )) {
				if ( loop ) currentSprite = loopStart;
				else setVisibility( false );
			}
		}
	}
}



void SpriteArray::draw() {

	if ( isVisible() ) {
		glPushMatrix();
		
		transform();
		(*currentSprite)->draw();
		
		glPopMatrix();
	}
}



bool SpriteArray::setLoop( int loopStarti, int loopEndingi ) {

	if ( loopStarti < loopEndingi && loopEndingi  > sprites.size() ) {

		for ( int i = 0 ; i < loopStarti ; i++, loopStart++ );
		for ( int i = 0 ; i <= loopEndingi ; i++, loopEnding++ );


		return true;
	}

	return false;
}
