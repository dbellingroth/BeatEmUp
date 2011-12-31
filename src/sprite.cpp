#include <iostream>
#include "sprite.h"


Sprite::Sprite() {
	
	string str = "hello.bmp";
	image = loadImage( str );
	init();

}

//Sprite::Sprite(string image_path) {

//	image = loadImage(image_path);
//	init();

//}


Sprite::~Sprite() {
}


void Sprite::init() {
	

}


GLuint Sprite::loadImage(string image_path) {

	GLuint texture;
		int w, h;
		SDL_Surface *image;
		SDL_Rect area;
		Uint32 saved_flags;
		Uint8  saved_alpha;
		SDL_Surface *surface = SDL_LoadBMP( "hello.bmp" );
	
		int longest_edge = surface->w > surface->h ? surface->w : surface->h;
		int sprite_edge = 1;
		while (sprite_edge < longest_edge) sprite_edge <<= 1;
	
		w = sprite_edge;
		h = sprite_edge;

		
		image = SDL_CreateRGBSurface(
				SDL_SWSURFACE,
				sprite_edge, sprite_edge,
				32,
#if SDL_BYTEORDER == SDL_LIL_ENDIAN // OpenGL RGBA masks
				0x000000FF,
				0x0000FF00,
				0x00FF0000,
				0xFF000000
#else
				0xFF000000,
				0x00FF0000,
				0x0000FF00,
				0x000000FF
#endif
				);
		if (!image) return 0;

		// Save the alpha blending attributes
		saved_flags = surface->flags&(SDL_SRCALPHA|SDL_RLEACCELOK);
		saved_alpha = surface->format->alpha;
		if ((saved_flags & SDL_SRCALPHA) == SDL_SRCALPHA)
			SDL_SetAlpha(surface, 0, 0);

		// Copy the surface into the GL texture image
		area.x = 0;
		area.y = 0;
		area.w = surface->w;
		area.h = surface->h;
		SDL_BlitSurface(surface, &area, image, &area);

		// Restore the alpha blending attributes
		if ((saved_flags & SDL_SRCALPHA) == SDL_SRCALPHA)
			SDL_SetAlpha(surface, saved_flags, saved_alpha);

		// Create an OpenGL texture for the image
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		// GL_NEAREST, GL_LINEAR
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGBA,
				 w, h,
				 0,
				 GL_RGBA,
				 GL_UNSIGNED_BYTE,
				 image->pixels
				 );
		SDL_FreeSurface(image); // No longer needed

		return texture;
	
}





void Sprite::draw() {

	glBindTexture( GL_TEXTURE_2D, textureID );
	
	glPushMatrix();
		transform();
		glBegin( GL_QUADS );
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