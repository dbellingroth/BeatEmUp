//main.cpp
#include "dep.h"
#include <iostream>
#include "window.h"
#include "sprite.h"
#include <string>
using namespace std;


void loop( int delta );

Sprite* s = 0;
Sprite* s2 = 0;

int main(int argc, char **argv) {	

	
	Window window( 800, 600, 32, false );
	window.setExternLoop( &loop );
	window.createDisplay();
	
	s = new Sprite();
	s2 = new Sprite();
	
	delete s;
	
	return 0;
}


void loop( int delta ) {
	

	s->draw();

}
