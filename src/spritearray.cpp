#include "spritearray.h"
#include <cmath>
#include <iostream>



SpriteArray::SpriteArray( const string image_path, int nx, int ny ) :
		displayTime( 0 ), displayedTime( 0 ), animation( false ), loop( false ) {

	sprites = Sprite::getSubImages( image_path, nx, ny );
	currentSprite = sprites.begin();

	if ( currentSprite == sprites.end() )
		std::cout << "true\n";
	loopStart = sprites.begin();
	loopEnding = sprites.end();
	visible = true;
}



SpriteArray::~SpriteArray() {

}



void SpriteArray::update(int delta) {

	if ( visible && animation ) {

		displayedTime += ( delta * pow( 10.0, -1.0) );

		if ( displayedTime >= displayTime ) {

			displayedTime = 0;
			currentSprite++;

			if ( currentSprite == loopEnding ) {
				if ( loop )
					currentSprite = loopStart;
				else
					setVisibility( false );
			}
		}
	}

}



void SpriteArray::draw() {

	if (visible) {
		glPushMatrix();

		transform();
		currentSprite->draw();

		glPopMatrix();
	}

}



void SpriteArray::setCurrent( int index ) {

	currentSprite = sprites.begin();
	for ( int i = 0 ; i < index && currentSprite != --( sprites.end() ) ; i++, currentSprite++);

}



bool SpriteArray::setLoop( int loopStarti, int loopEndingi ) {

	int loopEndingio, loopStartio;

	if ( loopStarti > loopEndingi ) {
		int temp = loopEndingi;
		int loopEndingio = loopStarti;
		int loopStartio = temp;
	} else {
		loopStartio = loopStarti;
		loopEndingio = loopEndingi;
	}


	if ( loopEndingio <= sprites.size() ) {
		for ( int i = 0 ; i < loopStartio ; i++, loopStart++ );
		for ( int i = 0 ; i <= loopEndingio ; i++, loopEnding++ );
		loopEnding++;
		return true;
	}

	return false;
}
