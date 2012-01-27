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
<<<<<<< HEAD
	virtual ~Vec2() {}	


=======
	virtual ~Vec2() {}
	

  Vec2<T> operator+ ( const Vec2<T> op );
  Vec2<T> operator- ( const Vec2<T> op );
>>>>>>> 03f06cc0148c0b91db3df2dcae7564f7dbdf3f96

};



template<typename T>
Vec2<T> operator+( const Vec2<T>& a, const Vec2<T>& b ) {

	Vec2<T> c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;

}

#endif
