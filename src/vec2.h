//vec2.h

#ifndef _VEC2_
#define _VEC2_

template <class T>
class Vec2 {

	public:
	T x;
	T y;


	Vec2( T _y, T _x ) : x(_x),
				     y(_y) {
	}

	Vec2() {}
	virtual ~Vec2() {}
	
	Vec2 operator+(Vec2 other);
	Vec2 operator-(Vec2 other);

};

#endif
