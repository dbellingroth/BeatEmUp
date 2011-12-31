//vec2.h

#ifndef _VEC2_
#define _VEC2_

template <class T>
class Vec2 {

	public:
	T x;
	T y;

	Vec2( T _x, T _y ) : x(_x),
				     y(_y) {
	}

	Vec2( ) {
		x = NULL;
		y = NULL;
	}

	virtual ~Vec2( ) {}

};

#endif
