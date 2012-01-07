#include <iostream>
#include "sprite.h"
#include <cmath>

Sprite::Sprite() {
	
	std::cout << "Bitte Bild-Pfad im Konstruktor angeben.\n";
	
}


Sprite::Sprite( const std::string image_path ) {

	textureID = loadImage( image_path );
	init();

}

Sprite::~Sprite() {
	
}



void Sprite::init() {

}


GLuint Sprite::loadImage( const std::string image_path ) {
//load image
	SDL_Surface* image = NULL;
	image = IMG_Load( image_path.c_str() );

	if ( !image ) std::cout << "Fehler: " << image_path << std::endl;
	else {
		if ( image->format->Amask == 0 ) {
			image = SDL_DisplayFormatAlpha( image );
		}
	}
	
//put size
	width = image->w;
	height = image->h;

//next power of to of the longest side
	int longest_edge = width > height ? width : height;
	twidth = theight = 	(int) pow(2,
				round((log(longest_edge) / log(2)) + 0.499999));

	SDL_DisplayFormatAlpha( image );
	SDL_Surface* quad_surface = flip_surface( image ); 

	
	wfac = (float) width / twidth;
	hfac = (float) height / theight;


	unsigned object(0);

	SDL_DisplayFormatAlpha( quad_surface );

	glGenTextures( 1, &object );

	glBindTexture( GL_TEXTURE_2D, object );

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, twidth, theight, 0, GL_RGBA, GL_UNSIGNED_BYTE, quad_surface->pixels );

//free surface
	SDL_FreeSurface( image );
	SDL_FreeSurface( quad_surface );

	
	return object;

}





void Sprite::draw() {

	glBindTexture( GL_TEXTURE_2D, textureID );
/*
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
*/
	

	glPushMatrix();
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



Uint32 Sprite::get_pixel32( SDL_Surface *image, int x, int y ) { 
//Convert the pixels to 32 bit 
	Uint32 *pixels = (Uint32*) image->pixels; 
//Get the requested pixel 
	return pixels[ ( y * image->w ) + x ]; 
} 


void Sprite::put_pixel32( SDL_Surface *image, int x, int y, Uint32 pixel ) { 
//Convert the pixels to 32 bit 
	Uint32* pixels = (Uint32*) image->pixels; 
//Set the pixel 
	pixels[ ( y * image->w ) + x ] = pixel; 
}


SDL_Surface* Sprite::flip_surface( SDL_Surface* image ) { 
//Pointer to the soon to be flipped surface 

	//SDL_SetAlpha( image, 4278190080 );

	SDL_Surface* quad_surface = NULL; 
	
	if( image->flags & SDL_SRCCOLORKEY ) {
	 	quad_surface = SDL_CreateRGBSurface( 
						SDL_SWSURFACE, this->twidth, this->theight, image->format->BitsPerPixel, 
						image->format->Rmask, image->format->Gmask, image->format->Bmask, 0 ); 
	} else {
		quad_surface = SDL_CreateRGBSurface( 
					SDL_SWSURFACE, this->twidth, this->theight, image->format->BitsPerPixel, 
					image->format->Rmask, image->format->Gmask, image->format->Bmask, image->format->Amask ); 
	}


//If the surface must be locked 
	if( SDL_MUSTLOCK( image ) ) { 
		SDL_LockSurface( image );
	}

//Go through columns 
	for( int x = 0 ; x < image->w; x++ ) { 
		//Go through rows 
		for( int y = 0 ; y < image->h; y++ ) {
			put_pixel32( quad_surface, x, y, get_pixel32( image, x, y ) ); 
		} 
	}


//Unlock surface
	if( SDL_MUSTLOCK( image ) ) {
		SDL_UnlockSurface( image ); 
	} 
	
//Copy color key 
	if( image->flags & SDL_SRCCOLORKEY ) { 
		SDL_SetColorKey( quad_surface, SDL_RLEACCEL | SDL_SRCCOLORKEY, image->format->colorkey ); 
	} 
	
	//Return flipped surface 
	return quad_surface; 
	
}
