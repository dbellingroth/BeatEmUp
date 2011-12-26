
#include "dep.h"
#include <iostream>
#include "window.h"
#include "sprite.h"
#include <string>
using namespace std;


void loop( int delta );

Sprite sprite;

int main(int argc, char **argv) {	
	
	string str( "hello.bmp" );	
	sprite( str );
	Window window( 800, 600, 32, false );
	window.setExternLoop( &loop );

	return 0;
}


void loop( int delta ) {

	sprite.draw();

}
