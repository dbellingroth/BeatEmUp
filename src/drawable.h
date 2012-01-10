
#ifndef _DRAWABLE_
#define _DRAWABLE_


class Drawable {

	private:
	float zIndex;
	bool visible;

	
	public:
	Drawable() : zIndex( 0 ), visible( true ) {}
	virtual ~Drawable() {}
	
	void setZIndex( float index ) { zIndex = index; };
	float getZIndex() { return zIndex; } 
	bool isVisible() { return visible; }
	void setVisibility( bool visible ) { this->visible = visible; }
	virtual void draw() = 0;

};



#endif