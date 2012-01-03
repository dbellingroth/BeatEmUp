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
	GLuint loadImage( const std::string image_path );
	
	public:
	Sprite();
	Sprite( const std::string image_path );

	virtual ~Sprite();

	void draw();

};

#endif
