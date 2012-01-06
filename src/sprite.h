//sprite.h

#ifndef _SPRITE_
#define _SPRITE_


#include "dep.h"
#include "SDL/SDL_image.h"
#include <string>
#include "transformable.h"


class Sprite : public Transformable {

	private:
	bool visible;
	int zIndex;
	GLuint textureID;
	static int idCounter;
	int width, height, twidth, theight;
	float wfac, hfac;
	
	void init();
	Uint32 get_pixel32( SDL_Surface *image, int x, int y );
	void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel );
	SDL_Surface* flip_surface( SDL_Surface* image );
	GLuint loadImage( const std::string image_path );
	
	public:
	Sprite();
	Sprite( const std::string image_path );

	virtual ~Sprite();

	void draw();

};

#endif
