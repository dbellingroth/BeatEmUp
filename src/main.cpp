//main.cpp

//standard includes
#include <iostream>
#include <string>

//own includes
#include "dep.h"
#include "window.h"
#include "spritelib.h"


void loop( int delta );



Sprite* s = NULL;


int main(int argc, char **argv) {	

	
	Window window( 800, 600, 32, false );
	window.setCaption( "SDL / OpenGL - Test" );
	window.setExternLoop( &loop );

	SpriteLib sLib;

	s = sLib.getSprite( "img/apple.png" );

	window.createDisplay();
	
	sLib.deleteAll();
	
	return 0;
}


void loop( int delta ) {
	
	s->draw();

}
