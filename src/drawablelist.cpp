

#include "drawablelist.h"



DrawableList::DrawableList() : it( dList.begin() ) {

}



DrawableList::~DrawableList() {

}


void DrawableList::add( Drawable* drawable ) {


	for ( it = dList.begin() ; it != dList.end() ; it++ ) {

		if ( drawable->getZIndex() < (*it)->getZIndex() )
			dList.insert( it, drawable );		
		
	}
	

	if ( it == dList.end() ) 
		dList.insert( it, drawable );
	
}


void DrawableList::remove( int index ) {

	it = dList.begin();
	for ( int i = 0 ; i < index ; i++, it++ )

	dList.erase( it );

}


void DrawableList::remove( Drawable* drawable ) {

	for ( it = dList.begin() ; ( (*it) != drawable && it != dList.end() ) ; it++ ) {

		if ( it != dList.end() )
		    dList.erase( it );

	}
	
}


bool DrawableList::contains( Drawable* drawable ) {

	for ( it = dList.begin() ; ( (*it) != drawable && it != dList.end() ) ; it++ )

	if ( it != dList.end() ) return true;
	else return false;

}


int DrawableList::size() {

	return dList.size();
	
}


void DrawableList::draw() {

	for ( it = dList.begin() ; it != dList.end() ; it++ )

		(*it)->draw();

}