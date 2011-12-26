//transformable.cpp



void Transformable::transform() {

	glTranslated(translate.x, translate.y, 0);
	glTranslated(rotationPoint.x, rotationPoint.y, 0);
	if (rotationAngle != 0)
	glRotatef((float) rotationAngle, 0f, 0f, 1);
	glTranslated(-rotationPoint.x, -rotationPoint.y, 0);
	glScaled(scaleFactor.x, scaleFactor.y, 1);

}
