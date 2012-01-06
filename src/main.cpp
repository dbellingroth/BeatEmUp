//main.cpp

//standard includes
#include <iostream>
#include <string>

//own includes
#include "dep.h"
#include "window.h"
#include "sprite.h"



void loop( int delta );

Sprite* s = NULL;


int main(int argc, char **argv) {	

	
	Window window( 800, 600, 32, false );
	window.setCaption( "SDL / OpenGL - Test" );
	window.setExternLoop( &loop );

	s = new Sprite( "img/test.png" );
	
	window.createDisplay();
	
	delete s;
	
	return 0;
}


void loop( int delta ) {
	
	s->draw();

}
