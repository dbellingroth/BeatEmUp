#include "vec2.h"

template <class T>
Vec2<T> Vec2<T>::operator+(const Vec2<T> other) {
  Vec2<T> result = new Vec2<T>;
  result.x = this->x + other->x;
  result.y = this->y + other->y;
  return result;
}

template <class T>
Vec2<T> Vec2<T>::operator-(const Vec2<T> other) {
  Vec2<T> result = new Vec2<T>;
  result.x = this->x - other->x;
  result.y = this->y -  other->y;
  return result;
}