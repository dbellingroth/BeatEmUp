//main.cpp

//standard includes
#include <iostream>
#include <string>

//own includes
#include "dep.h"
#include "game.h"
#include "window.h"
#include "spritelib.h"
#include "gameobject.h"
#include "inputlistener.h"
#include "spritearray.h"
#include <list>
#include "sprite.h"
#include "vec2.h"

#include "vec2.h"




class TestGame : public Game {

	private:
	SpriteArray* sa;
	SpriteLib sLib;
	list<Sprite> sprites;
	list<Sprite>::iterator it;
		
	public:
	TestGame() {
		sa = new SpriteArray( "img/apple.png", 2, 2 );
		sa->setCurrent( 1 );
		sa->setDisplayTime( 1 );
		sa->enableLoop();
	
		sprites = Sprite::getSubImages( "img/apple.png", 2, 2 );
		it = sprites.begin();
		//it++;
	}

	

		
	virtual ~TestGame() { 
		sLib.deleteAll();
	}	


		
	void input( SDL_Event& event ) {}

	
	void update( int delta ) {
		//sa->update( delta );
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


