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
		//sa = new SpriteArray( "img/apple.png", 2, 2 );
		//sa->setCurrent( 10 );
		//sa->setDisplayTime( 1 );
		//sa->enableLoop();
	
		sprites = Sprite::getSubImages( "img/apple.png", 2, 2 );
		it = sprites.begin();
		//it++;
	}

	

		
	virtual ~TestGame() { 
		sLib.deleteAll();
	}	


		
	void input( SDL_Event event ) {}

	
	void update( int delta ) {
		//sa->update( delta );
	}
		

	void draw() {
		it->draw();
	}


};




int main(int argc, char **argv) {	
  
  Vec2<float> temp1(2.6,7.6);
  Vec2<float> temp2(0.4,0.4);
  temp1= temp1 + temp2;
  cout << "----------------" << endl;
  cout << temp1.x << endl;
  cout << temp1.y << endl;
  cout << "----------------" << endl;

	Vec2<float> a( 2.5, 1.5 );
	Vec2<float> b( 1.0, 2.0 );
	Vec2<float> c =  a + b ; 
	std::cout << a.x << ", " << a.y << std::endl;
	std::cout << b.x << ", " << b.y << std::endl;
	std::cout << c.x << ", " << c.y << std::endl;
	
	Window window( 800, 600, 32, false );
	window.setCaption( "SDL / OpenGL - Test" );	

	TestGame test;

	window.createDisplay( &test );

	return 0;
}


