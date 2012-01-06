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
typedef void ( *funcP_event )( SDL_Event* event );

class Window {
	
	private:
	int width;
	int height;
	int bpp;
	int delta;
	long fps, lastFPS, lastFrame;
	std::string caption;
	WINDOW_MODE w_mode;
	bool mouse_cursor, fullscreen;
	bool running;
	
	void initGL();
	void loop();
	void handleInput();
	void render();

	SDL_Event event;
	funcP extLoop;
	funcP_event mouseInput;
	funcP_event keyInput;

		
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

	//Funktionspointer uebergeben
	void setExternLoop( funcP extLoop );
	void setInputLoop( funcP_event mouse, funcP_event key );
	
	bool createDisplay();
	
};

#endif
