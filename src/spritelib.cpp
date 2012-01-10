
#include "spritelib.h"


SpriteLib::SpriteLib() {

	sprites_it = sprites.begin();	

}



SpriteLib::~SpriteLib() {

}



Sprite* SpriteLib::getSprite( string sprite_name ) {

	
	if (( sprites_it = sprites.find( sprite_name )) != sprites.end() ) return &(sprites_it->second);
	else {
		sprites.insert( sprites.end(), SpriteMap::value_type( sprite_name, Sprite( sprite_name )));
		return getSprite( sprite_name );
	}
	
}



bool SpriteLib::deleteSprite( string sprite_name ) {

	if (( sprites_it = sprites.find( sprite_name )) != sprites.end() ) {
		sprites.erase( sprite_name );
		return true;
	}

	return false;
}



SpriteArray* SpriteLib::getSpriteArray( const string name, int nx, int ny ) {

	if (( spriteArrays_it = spriteArrays.find( name )) != spriteArrays.end() ) 
			return &(spriteArrays_it->second);
	else {
		spriteArrays.insert( spriteArrays.end(), 
		                    SpriteListMap::value_type( name, SpriteArray( name, nx, ny )));
		return getSpriteArray( name, nx, ny );
	}
	
}



bool SpriteLib::deleteSpriteArray( const string name ) {

	if (( spriteArrays_it = spriteArrays.find( name )) != spriteArrays.end() ) {
		sprites.erase( name );
		return true;
	}

	return false;

}



bool SpriteLib::deleteAll() {

	sprites.clear();
	spriteArrays.clear();

	if ( sprites.begin() == sprites.end() 
	    && spriteArrays.begin() == spriteArrays.end() ) return true;
	else return false;

}