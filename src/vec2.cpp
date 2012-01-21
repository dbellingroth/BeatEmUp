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