//transformable.cpp

#include "transformable.h"


Transformable::Transformable()
						//	: translate( Vec2f( 0, 0) ),
						//	  rotationPoint( Vec2f( 0, 0 ) ),
						//	  rotationAngle( 0 ),
						//	  scaleFactor( Vec2f( 1, 1 ) ) {
{
}

Transformable::~Transformable() {}

#include "transformable.h"

void Transformable::transform() {

	glTranslated(getTranslate().x, getTranslate().y, 0);
	glTranslated(getRotationPoint().x, getRotationPoint().y, 0);
	if (getRotationAngle() != 0)
	glRotatef((float) this->rotationAngle, 0, 0, 1);
	glTranslated(translate.x, translate.y, 0);
	glTranslated(rotationPoint.x, rotationPoint.y, 0);
	if (rotationAngle != 0)
	glRotatef((float) rotationAngle, 0, 0, 1);
	glTranslated(-rotationPoint.x, -rotationPoint.y, 0);
	glScaled(this->scaleFactor.x, this->scaleFactor.y, 1);

}
