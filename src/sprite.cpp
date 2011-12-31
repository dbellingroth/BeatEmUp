
#include "sprite.h"


Sprite::Sprite() {

	init();

}

Sprite::Sprite(string image_path) {

	image = loadImage(image_path);
	init();

}


int Sprite::init() {
	

}


GLuint Sprite::loadImage(string image_path) {

	// Bild laden
	SDL_Surface *Bild = SDL_LoadBMP((char*)image_path.c_str());
	
	SDL_Surface *Konv = SDL_CreateRGBSurface(SDL_SWSURFACE, Bild->w, Bild->h, 32, 
                              #if SDL_BYTEORDER == SDL_BIG_ENDIAN
                                       0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
                              #else
                                       0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
                              #endif
	SDL_BlitSurface(Bild, 0, Konv, 0);
	// Textur erstellen
	GLuint textur;
	glGenTextures(1, &textur);
	glBindTexture(GL_TEXTURE_2D, textur);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);    // zum Strecken und Stauchen den Filter GL_LINEAR ...
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    // ... benutzen (sparsamer: GL_NEAREST)
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Konv->w, Konv->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, Konv->pixels); 
	//Bereinigen und Zurückgeben
	SDL_FreeSurface(Bild);
	SDL_FreeSurface(Konv);
	return textur;

}





void Sprite::draw() {

	glBindTexture(GL_TEXTURE_2D, textureID);
	
	glPushMatrix();
		transform();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex2f(0, 0);
		glTexCoord2f(wfac, 0);
		glVertex2f(width, 0);
		glTexCoord2f(wfac, hfac);
		glVertex2f(width, height);
		glTexCoord2f(0, hfac);
		glVertex2f(0, height);
		glEnd();
	glPopMatrix();

}
