//window.h
#include "dep.h"
#include <string>
#include <iostream>
#include "sprite.h"
#include "gameobject.h"
#include "inputlistener.h"
#include "game.h"

#ifndef _WINDOW_
#define _WINDOW_

enum WINDOW_MODE {
	WINDOW, FULLSCREEN
};

typedef Game Principal;
class Window {

private:
	int width;
	int height;
	int bpp;
	int delta;
	long desired_fps, fps, lastFPS, lastFrame;
	std::string caption;
	WINDOW_MODE w_mode;
	bool mouse_cursor, fullscreen;
	bool running;

	void initGL();
	void loop();
	void handleInput();
	void render();

	SDL_Event event;
	Principal* principal;

public:
	Window(int width, int height, int bpp, bool fullscreen);
	Window(const Window& src);
	Window operator=(const Window& src);
	virtual ~Window();

	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
	int getBPP() {
		return bpp;
	}
	std::string getCaption() {
		return caption;
	}
	void setCaption(std::string caption) {
		this->caption = caption;
	}
	void setMouseCursor(bool mouse_cursor) {
		this->mouse_cursor = mouse_cursor;
	}
	void stop() {
		running = false;
	}

	bool createDisplay(Principal* principal);

};

#endif
