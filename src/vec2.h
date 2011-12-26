//vec2.h

#ifndef _VEC2_
#define _VEC2_

template <class T>
class Vec2 {

	public:
	T first;
	T second;

	Vec2( T _first, T _second ) : first(_first),
				     second(_second) {
	}

	Vec2( ) {
		first = NULL;
		second = NULL;
	}

	virtual ~Vec2( ) {}

};

#endif
