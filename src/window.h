//window.h
#include "dep.h"
#include <string>
#include <iostream>
#include "sprite.h"
using namespace std;

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
	string caption;
	WINDOW_MODE w_mode;
	bool mouse_cursor;
	bool fullscreen;
	bool running;
	
	void initGL();
	void loop();
	void handleInput();
	void render();

	SDL_Event event;
	funcP externLoop;

		
	public:
	Window( int width, int height, int bpp, bool fullscreen );
	virtual ~Window();
	Sprite spr();
	int getWidth() { return width; }
	int getHeight() { return height; }
	int getBPP() { return bpp; }
	string getCaption() { return caption; }
	void setCaption( string caption ) { this->caption = caption; }
	void setMouseCursor( bool mouse_cursor ) { this->mouse_cursor = mouse_cursor; }
	void stop() { running = false; }	
	void setExternLoop( funcP externLoop ) { this->externLoop = externLoop; }

	Window( const Window& src );
	Window operator=( const Window& src );
};

#endif
