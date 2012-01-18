//main.cpp

//standard includes
#include <iostream>
#include <string>
//#include <time.h>

//own includes
#include "dep.h"
#include "game.h"
#include "window.h"
#include "spritelib.h"
#include "gameobject.h"
#include "inputlistener.h"
#include "spritearray.h"




class TestGame : public Game {

	private:
	SpriteArray* sa;
	SpriteLib sLib;

		
	public:
	TestGame() {
		sa = new SpriteArray( "img/apple.png", 2, 2 );
		//sa->setDisplayTime( 1 );
		//sa->enableLoop();
	}

		
	virtual ~TestGame() { 
		sLib.deleteAll();
	}	


	void input( SDL_Event event ) {}

	
	void update( int delta ) {
		sa->update( delta );
	}
		

	void draw() {
		sa->draw();
	}


};




int main(int argc, char **argv) {	

	Window window( 800, 600, 32, false );
	window.setCaption( "SDL / OpenGL - Test" );	

	TestGame test;

	window.createDisplay( &test );

	return 0;
}


