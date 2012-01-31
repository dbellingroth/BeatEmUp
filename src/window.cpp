//window.cpp
#include "window.h"
#include <iostream>

Window::Window(int _width, int _height, int _bpp, bool _fullscreen) :
		width(_width), height(_height), desired_fps(120), bpp(_bpp), fullscreen(
				_fullscreen) {

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_WM_SetCaption(caption.c_str(), NULL);

	initGL();

}

Window::~Window() {

	SDL_Quit();

}

void Window::initGL() {

	//Set OpenGl memory usage
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//Set size, bpp and OpenGl usage
	//http://sdl.beuc.net/sdl.wiki/SDL_SetVideoMode
	SDL_SetVideoMode(width, height, 32, SDL_OPENGL);

	//the clear Color
	glClearColor(0, 0, 0, 1); //RED, GREEN, BLUE; ALPHA

	//What portion of the screen we will display
	glViewport(0, 0, width, height);

	//Shader-Model - Use this!
	glShadeModel(GL_SMOOTH);

	//2D rendering
	glMatrixMode(GL_PROJECTION);

	//"Save" it
	glLoadIdentity();

	//disable depth checking
	glDisable(GL_DEPTH_TEST);

	//enable blending for displaying textures
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_TEXTURE_2D);

	glOrtho(0, width, height, 0, 1, -1);

}

bool Window::createDisplay(Principal* principal) {

	this->principal = principal;

	running = true;

	if (glGetError() == GL_NO_ERROR)
		loop();
	else
		std::cout << glGetError() << std::endl;

}

void Window::loop() {

	while (running) {

		handleInput();

		if (principal)
			principal->update(1);

		render();

		SDL_Delay(60);

	}

}

void Window::handleInput() {

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			running = false;
		if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
			running = false;
		if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_r)
			glClearColor(1, 0, 0, 1); //RED, GREEN, BLUE; ALPHA

		if (principal)
			principal->input(event);
	}

}

void Window::render() {

	glClear(GL_COLOR_BUFFER_BIT); // Aktuellen Bildpuffer löschen

	glMatrixMode(GL_MODELVIEW); // Die Transformationsmatrix
	glLoadIdentity(); // zurücksetzen...

	glColor4f(1, 1, 1, 1);
	///////////HIER///////////////////

	if (principal)
		principal->draw();

	///////////ZEICHNEN///////////////

	SDL_GL_SwapBuffers(); // Bildpuffer vertauschen

}