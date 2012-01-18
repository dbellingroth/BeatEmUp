//sprite.h

#ifndef _SPRITE_
#define _SPRITE_

#include <string>
#include <list>

#include "dep.h"
#include "SDL/SDL_image.h"
#include "transformable.h"
#include "drawable.h"
#include "vec2.h"


typedef Vec2<int> Vec2i;
class Sprite : public Transformable, public Drawable {

	private:
	GLuint textureID;
	int width, height, twidth, theight;
	float wfac, hfac;
	
	void init( SDL_Surface* surface );
	
	public:
	Sprite();
	Sprite( SDL_Surface* image );
	Sprite( const std::string image_path );

	virtual ~Sprite();

	
	void putSize( SDL_Surface* image );
	void draw();

	static std::list<Sprite> getSubImages( const std::string image_path, int x, int y );
	static Uint32 getPixel32( SDL_Surface* image, int x, int y );
	static void putPixel32( SDL_Surface* surface, int x, int y, Uint32 pixel );
	static void flipSurface( SDL_Surface* src, SDL_Surface* desk );
	static void flipSurface( SDL_Surface* src, SDL_Surface* desk, Vec2i offset, Vec2i size );
	static SDL_Surface* loadImage( const std::string image_path );
	static GLuint getGLuint( SDL_Surface* surface );

};

#endif
