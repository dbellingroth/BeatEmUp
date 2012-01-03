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

	initGL();


}



Window::~Window() {

	SDL_Quit();
	
}

void Window::setExternLoop( funcP extLoop ) { 
	
	this->extLoop = extLoop; 
	
}


bool Window::createDisplay() {

	running = true;

	if( glGetError() == GL_NO_ERROR ) loop();

}



void Window::initGL() {

	//Set OpenGl memory usage
	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32 );
	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	
	//Set size, bpp and OpenGl usage
	SDL_SetVideoMode( width, height, 32, SDL_OPENGL );

	//the clear Color
	glClearColor( 1, 1, 1, 1 ); //RED, GREEN, BLUE; ALPHA

	//What portion of the screen we will display
	glViewport( 0, 0, width, height );

	//Shader-Model - Use this!
	glShadeModel( GL_SMOOTH );

	//2D rendering
	glMatrixMode( GL_PROJECTION );

	//"Save" it
	glLoadIdentity();

	//disable depth checking
	glDisable( GL_DEPTH_TEST );

	//enable blending for displaying textures
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	glEnable( GL_TEXTURE_2D );
	
	glOrtho( 0, width, height, 0, 1, -1 );

}


void Window::loop() {
	
	while(running) {

		handleInput();
		render();	

		SDL_Delay( 30 );

	}
	
}


void Window::handleInput() {

	while ( SDL_PollEvent( &event ) ) {
			if ( event.type == SDL_QUIT )
				running = false;
			if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE )
				running = false;
			if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_r ) 
				glClearColor( 1, 0, 0, 1 ); //RED, GREEN, BLUE; ALPHA
		}
	
}


void Window::render() {


	glClear( GL_COLOR_BUFFER_BIT );     // Aktuellen Bildpuffer löschen

	glMatrixMode( GL_MODELVIEW ); // Die Transformationsmatrix
	glLoadIdentity();           // zurücksetzen...

	glColor4f(1, 1, 1, 1);
	///////////HIER///////////////////

	if ( extLoop ) extLoop( 1 );
	
	///////////ZEICHNEN///////////////


	SDL_GL_SwapBuffers(); // Bildpuffer vertauschen
                      // Wichtig ist, dass wir die Puffer erst nach
                      // der letzten Zeichenoperation tauschen.

}





