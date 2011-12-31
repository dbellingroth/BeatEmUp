//window.cpp
#include "window.h"
#include <iostream>
using namespace std;

Window::Window(int _width, int _height, int _bpp, bool _fullscreen) : 
						width(_width),
						height(_height),
						bpp(_bpp),
						fullscreen(_fullscreen) {

    
	SDL_Init( SDL_INIT_EVERYTHING );
	
	SDL_WM_SetCaption( caption.c_str(), NULL );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	surface = SDL_SetVideoMode( width, height, bpp, SDL_OPENGL | ( fullscreen ? SDL_FULLSCREEN : 0 ) );

	initGL();
	
	running = true;
	
	if( glGetError() == GL_NO_ERROR ) loop();

}




Window::~Window() {

	SDL_FreeSurface( surface );
	SDL_Quit();

}



void Window::initGL() {
	glEnable( GL_TEXTURE_2D );
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	glViewport(0, 0, width, height);
	glMatrixMode( GL_MODELVIEW );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho(0, width, height, 0, 1, -1);
	glMatrixMode( GL_MODELVIEW );
	glDisable( GL_DEPTH_TEST );	
}

void Window::loop() {

	while(running) {
		
		handleInput();
		render();	
	
	}
	
}


void Window::handleInput() {


}


void Window::render() {

	glClearColor( 1.0, 0.0, 0.0, 0.0 ); // Farbe zum Löschen setzen
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );     // Aktuellen Bildpuffer löschen
	
	glMatrixMode( GL_MODELVIEW ); // Die Transformationsmatrix
	glLoadIdentity();           // zurücksetzen...

	///////////HIER///////////////////


	externLoop( 1 );


	///////////ZEICHNEN///////////////


	SDL_GL_SwapBuffers(); // Bildpuffer vertauschen
                      // Wichtig ist, dass wir die Puffer erst nach
                      // der letzten Zeichenoperation tauschen.


}




