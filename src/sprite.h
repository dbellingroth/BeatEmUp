//sprite.h

#ifndef _SPRITE_
#define _SPRITE_



#include "dep.h"
#include <string>
#include "transformable.h"
using namespace std;

class Sprite : public Transformable {

	private:
	bool visible;
	int zIndex;
	int textureID;
	GLuint image;
	static int idCounter;
	int width, height, twidth, theight;
	float wfac, hfac;
	
	void init();
	
	public:
	Sprite();
	Sprite(string image_path);

	void draw();

};

#endif
