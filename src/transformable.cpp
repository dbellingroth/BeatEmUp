//transformable.cpp

#include "transformable.h"


Transformable::Transformable() {
}

Transformable::~Transformable(){

}


void Transformable::transform() {

	glTranslated(getTranslate().x, getTranslate().y, 0);
	glTranslated(getRotationPoint().x, getRotationPoint().y, 0);
	if (getRotationAngle() != 0)
	glRotatef((float) this->rotationAngle, 0, 0, 1);
	glTranslated(-rotationPoint.x, -rotationPoint.y, 0);
	glScaled(this->scaleFactor.x, this->scaleFactor.y, 1);

}