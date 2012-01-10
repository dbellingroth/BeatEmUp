#include <iostream>
#include "sprite.h"
#include "tools.h"
#include <cmath>

Sprite::Sprite() {
	
	std::cout << "Bitte Bild-Pfad im Konstruktor angeben.\n";
	
}



Sprite::Sprite( const std::string image_path ) {

	SDL_Surface* image = loadImage( image_path );
	init( image );

}



Sprite::Sprite( SDL_Surface* image ) {

	init( image );

}
	


Sprite::~Sprite() {
	
}



void Sprite::init( SDL_Surface* image ) {

	putSize( image );
	
	//new surface with optimized size
	SDL_Surface* desk = SDL_CreateRGBSurface( 
		SDL_SWSURFACE, twidth, theight, image->format->BitsPerPixel, 
		image->format->Rmask, image->format->Gmask, image->format->Bmask, image->format->Amask ); 

	flipSurface( image, desk );

	textureID = getGLuint( desk );

	SDL_FreeSurface( image );
	SDL_FreeSurface( desk );
}


void Sprite::putSize( SDL_Surface* image ) {

	width = image->w;
	height = image->h;
	twidth = theight = Tools::nextPowerOfTwo( Tools::getMajor( image->w, image->h ));
	wfac = (float) width / twidth;
	hfac = (float) height / theight;
	
}




SDL_Surface* Sprite::loadImage( const std::string image_path ) {
//load image
	SDL_Surface* image = NULL;
	image = IMG_Load( image_path.c_str() );

	if ( !image ) std::cout << "Fehler: " << image_path << std::endl;
	else {
		if ( image->format->Amask == 0 ) {
			image = SDL_DisplayFormatAlpha( image );
		}
	}

	SDL_DisplayFormatAlpha( image );

	return image;
}





GLuint Sprite::getGLuint( SDL_Surface* surface ) {
	
	unsigned object(0);

	SDL_DisplayFormatAlpha( surface );

	glGenTextures( 1, &object );

	glBindTexture( GL_TEXTURE_2D, object );

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels );
	
	return object;
}


Uint32 Sprite::getPixel32( SDL_Surface* image, int x, int y ) { 
//Convert the pixels to 32 bit 
	Uint32 *pixels = (Uint32*) image->pixels; 
//Get the requested pixel 
	return pixels[ ( y * image->w ) + x ]; 
} 




void Sprite::putPixel32( SDL_Surface* image, int x, int y, Uint32 pixel ) { 
//Convert the pixels to 32 bit 
	Uint32* pixels = (Uint32*) image->pixels; 
//Set the pixel 
	pixels[ ( y * image->w ) + x ] = pixel; 
}


void Sprite::flipSurface( SDL_Surface* src, SDL_Surface* desk ) {
	flipSurface( src, desk, Vec2i( 0, 0 ), Vec2i( src->w, src->h ));
}


void Sprite::flipSurface( SDL_Surface* src, SDL_Surface* desk, Vec2i offset, Vec2i size ) { 

//If the source-surface must be locked 
	if( SDL_MUSTLOCK( src ) ) { 
		SDL_LockSurface( src );
	}

//Go through columns 
	for( int x = offset.x ; x < size.x ; x++ ) { 
	//Go through rows 
		for( int y = offset.y ; y < size.y ; y++ ) {
			putPixel32( desk, x, y, getPixel32( src, x, y ) ); 
		} 
	}

//Unlock source-surface
	if( SDL_MUSTLOCK( src ) ) {
		SDL_UnlockSurface( src ); 
	} 
	
//Copy color key 
	if( src->flags & SDL_SRCCOLORKEY ) { 
		SDL_SetColorKey( desk, SDL_RLEACCEL | SDL_SRCCOLORKEY, src->format->colorkey );
	} 

}



std::list<Sprite*> Sprite::getSubImages( const std::string image_path, int nx, int ny ) {

	std::list<Sprite*> sprites;

	SDL_Surface* image = loadImage( image_path );
	int width = image->w / nx;
	int height = image->h / ny;
	
	for ( int x = 0 ; x < nx ; x++ ) {
		for ( int y = 0 ; y < ny ; y++ ) {

			SDL_Surface* sub_surface = SDL_CreateRGBSurface( 
				SDL_SWSURFACE, width, height, image->format->BitsPerPixel, 
				image->format->Rmask, image->format->Gmask, image->format->Bmask, image->format->Amask ); 

			flipSurface( image, sub_surface, Vec2i( x*width, y*height ), Vec2i( width, height ));

			sprites.push_back( new Sprite( sub_surface ));
		}
	}
	
	return sprites;
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



