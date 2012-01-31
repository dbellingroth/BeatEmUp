//transformable.cpp

#include "transformable.h"

Transformable::Transformable() :
		translate(Vec2f(0, 0)), rotationPoint(Vec2f(0, 0)), rotationAngle(0), scaleFactor(
				Vec2f(1, 1)) {

}

void Transformable::transform() {

	//Verschieben
	glTranslated(translate.x, translate.y, 0);

	//Drehen
	glTranslated(rotationPoint.x, rotationPoint.y, 0);
	if (rotationAngle)
		glRotatef((float) this->rotationAngle, 0, 0, 1);

	//Skalieren
	glScaled(scaleFactor.x, scaleFactor.y, 1);

}