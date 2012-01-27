
#ifndef _DRAWABLE_LIST_
#define _DRAWABLE_LIST

#include "drawable.h"
#include <list>
using namespace std;

typedef list<Drawable*> DList;
class DrawableList {

	private:
	DList dList;
	DList::iterator it;
	
	public:
	DrawableList();
	virtual ~DrawableList();
		
	void add( Drawable* );
	void remove( int index );
	void remove( Drawable* );
	bool contains( Drawable* );
	int size();
	void draw();

};


#endif