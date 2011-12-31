
#include "dep.h"
#include <iostream>
#include "window.h"
#include "sprite.h"
#include <string>
using namespace std;


void loop( int delta );

Sprite* s = 0;

int main(int argc, char **argv) {	

	cout << "Programm gestartet..." << endl;

	s = new Sprite();
	

	string str( "hello.bmp" );	
	sprite = Sprite(str);
	Window window( 800, 600, 32, false );
	window.setExternLoop( &loop );

	cout << "Programm beendet..." << endl;

	delete s;
	
	return 0;
}


void loop( int delta ) {

	s->draw();

}
