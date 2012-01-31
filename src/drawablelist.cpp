

#include "drawablelist.h"
#include <iostream>


DrawableList::DrawableList() : it( dList.begin() ) {

}



DrawableList::~DrawableList() {

}


void DrawableList::add( Drawable* drawable ) {

	//if ( !contains( drawable ))
		dList.push_back( drawable );

	//dList.sort( Drawable::compareZIndex );
}


void DrawableList::remove( int index ) {

	if ( index < dList.size() && dList.size() != 0 ) {
		
		it = dList.begin();
		for ( int i = 0 ; i < index ; ++i, it++ );

		dList.erase( it );

	}
	
}


void DrawableList::remove( Drawable* drawable ) {
/*
	if ( dList.size() ) {

		for ( it = dList.begin() ; ((*it) != drawable

	}*/
}


bool DrawableList::contains( Drawable* drawable ) {

	if ( dList.size() ) return false;
	else {
		for ( it = dList.begin() ; ((*it) != drawable && it != dList.end() ) ; it++ );

		if ( it != dList.end() ) return true;
		else return false;
	}
}


int DrawableList::size() {

	return dList.size();
	
}


void DrawableList::draw() {

	if ( dList.size() != 0 ) {
		for ( it = dList.begin() ; it != dList.end() ; it++ ) {

			(*it)->draw();

		}
	}
}