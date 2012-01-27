<<<<<<< HEAD

#include "vec2.h"

=======
#include "vec2.h"

template <class T>
Vec2<T> Vec2<T>::operator+( const  Vec2<T> op ) {
  Vec2<T> result;
  result.x = this->x + op.x;
  result.y = this->y +  op.y;
  return result;
}

template <class T>
Vec2<T> Vec2<T>::operator-( const Vec2<T> op ) {
  Vec2<T> result;
  result.x = this->x - op.x;
  result.y = this->y -  op.y;
  return result;
}
>>>>>>> 03f06cc0148c0b91db3df2dcae7564f7dbdf3f96
