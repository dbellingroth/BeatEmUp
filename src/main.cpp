//main.cpp
#include "dep.h"
#include <iostream>
#include "window.h"
#include "sprite.h"
#include <string>
using namespace std;


void loop( int delta );

Sprite* s = NULL;


int main(int argc, char **argv) {	

	
	Window window( 800, 600, 32, false );
	window.setExternLoop( &loop );
	window.createDisplay();
	
	delete s;
	
	return 0;
}


void loop( int delta ) {
	
	if ( !s ) s = new Sprite();
	if ( s ) s->draw();

}
