#include <iostream>
#include "sprite.h"
#include <cmath>

Sprite::Sprite() {
	
	image = loadImage( "src/test.png" );
	init();

}


Sprite::Sprite( const std::string image_path ) {

	image = loadImage( image_path );
	init();

}

Sprite::~Sprite() {
	
}



void Sprite::init() {

}


GLuint Sprite::loadImage( const std::string image_path ) {

	SDL_Surface* image = IMG_Load( image_path.c_str() );
	
	unsigned object(0);

	if ( image ) {
		SDL_DisplayFormatAlpha( image );

		glGenTextures( 1, &object );

		glBindTexture( GL_TEXTURE_2D, object );

		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels );

		//free surface
		SDL_FreeSurface( image );
	} else {
		std::cout << image_path << " failed\n";
	}
	std::cout << object << std::endl;
	
	return object;
	
}





void Sprite::draw() {

	glBindTexture( GL_TEXTURE_2D, textureID );
	
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
