//transformable.cpp


#include "transformable.h"

void Transformable::transform() {

	glTranslated(translate.x, translate.y, 0);
	glTranslated(rotationPoint.x, rotationPoint.y, 0);
	if (rotationAngle != 0)
	glRotatef((float) rotationAngle, 0, 0, 1);
	glTranslated(-rotationPoint.x, -rotationPoint.y, 0);
	glScaled(scaleFactor.x, scaleFactor.y, 1);

}
