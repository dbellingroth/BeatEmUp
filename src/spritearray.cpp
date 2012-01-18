
#include "spritearray.h"
#include <cmath>
#include <iostream>

SpriteArray::SpriteArray( const string image_path, int nx, int ny ) 
											: displayTime( 0 ),
											  displayedTime( 0 ),
											  animation ( false ),
											  loop( false ) {

	sprites = Sprite::getSubImages( image_path, nx, ny );
	currentSprite = sprites.begin() ;	
	currentSprite++;
	currentSprite++;
	if ( currentSprite == sprites.end() ) std::cout << "true\n";
	loopStart = sprites.begin() ;
	loopEnding = sprites.end() ;
	visible = true;
}



SpriteArray::~SpriteArray() {

}


void SpriteArray::update(int delta) {
/*
	if ( visible && animation ) {
		
		displayedTime += (delta * pow(10, -1));
		
		if ( displayedTime >= displayTime ) {
			
			displayedTime = 0;
			currentSprite++;
			
			if ( currentSprite == loopEnding )) {
				if ( loop ) currentSprite = loopStart;
				else setVisibility( false );
			}
		}
	}
*/
}



void SpriteArray::draw() {

	if ( visible ) {
		glPushMatrix();

		transform();
		currentSprite->draw();
		
		glPopMatrix();
	}

}



bool SpriteArray::setLoop( int loopStarti, int loopEndingi ) {

	if ( loopStarti < loopEndingi && loopEndingi > sprites.size() ) {

		for ( int i = 0 ; i < loopStarti ; i++, loopStart++ );
		for ( int i = 0 ; i <= loopEndingi ; i++, loopEnding++ );

		return true;
	}

	return false;
}
