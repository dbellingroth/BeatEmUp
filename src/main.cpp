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
	SpriteArray* sArray;


	public:
	TestGame() {
		
		sArray = new SpriteArray( "img/apple.png", 2, 2 );
		sArray->enableAnimation();
		sArray->enableLoop();
		sArray->setDisplayTime( 1.0 );
		sArray->setLoop( 4, 0 );
	}



	virtual ~TestGame() {
		delete sArray;
	}



	void input(SDL_Event& event) { /**/ }



	void update(int delta) {
		sArray->update( delta );
	}



	void draw() {

		sArray->draw();
	}

};



int main(int argc, char **argv) {

	Window window(800, 600, 32, false);
	window.setCaption("SDL / OpenGL - Test");

	TestGame test;
	window.createDisplay( &test );
	return 0;
}

