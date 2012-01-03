//window.h
#include "dep.h"
#include <string>
#include <iostream>
#include "sprite.h"


#ifndef _WINDOW_
#define _WINDOW_

enum WINDOW_MODE { WINDOW, FULLSCREEN };

typedef void ( *funcP )( int delta ); // Funktionszeiger	auf die externe Funktion, die bei jedem Frame
					//ausgefuehrt werden soll.

class Window {
	
	private:
	int width;
	int height;
	int bpp;
	int delta;
	long fps, lastFPS, lastFrame;
	std::string caption;
	WINDOW_MODE w_mode;
	bool mouse_cursor;
	bool fullscreen;
	bool running;
	
	void initGL();
	void loop();
	void handleInput();
	void render();

	SDL_Event event;
	funcP extLoop;

		
	public:
	Window( int width, int height, int bpp, bool fullscreen );
	Window( const Window& src );
	Window operator=( const Window& src );
	virtual ~Window();

		
	int getWidth() { return width; }
	int getHeight() { return height; }
	int getBPP() { return bpp; }
	std::string getCaption() { return caption; }
	void setCaption( std::string caption ) { this->caption = caption; }
	void setMouseCursor( bool mouse_cursor ) { this->mouse_cursor = mouse_cursor; }
	void stop() { running = false; }	
	void setExternLoop( void ( *extLoop )( int delta ) );
	bool createDisplay();
		


};

#endif
