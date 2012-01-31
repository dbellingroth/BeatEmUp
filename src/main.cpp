//main.cpp

//standard includes
#include <iostream>
#include <string>
#include <list>

//own includes
#include "dep.h"
#include "game.h"
#include "window.h"
#include "spritelib.h"
#include "gameobject.h"
#include "inputlistener.h"
#include "spritearray.h"
#include "sprite.h"
#include "vec2.h"
#include "drawablelist.h"




class TestGame : public Game {

	private:
	Sprite* s1;
	Sprite* s2;

	
	public:
	TestGame() {

		s1 = new Sprite( "img/oalpha.png" );
		s2 = new Sprite( "img/apple.png" );

	}

	

		
	virtual ~TestGame() { 
		
		delete s1;
		delete s2;
	}	


		
	void input( SDL_Event& event ) { /**/ }


		
	void update( int delta ) { /**/ }

		

	void draw() {
		
		s2->draw();
		s1->draw();
	}

};




int main(int argc, char **argv) {	
  	
	Window window( 800, 600, 32, false );
	window.setCaption( "SDL / OpenGL - Test" );	

	TestGame test;

	window.createDisplay( &test );

	return 0;
}


