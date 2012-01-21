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

	Vec2() {}
	virtual ~Vec2() {}
	

  Vec2<T> operator+ ( const Vec2<T> op );
  Vec2<T> operator- ( const Vec2<T> op );

};

#endif
