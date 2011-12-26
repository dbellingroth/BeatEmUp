//transformable.h


#ifndef _TRANSFORMABLE_
#define _TRANSFORMABLE_

#include "dep.h"
#include "vec2.h"

typedef Vec2<float> Vec2f;
class Transformable {

	protected:
	Vec2f translate;
	Vec2f rotationPoint;
	double rotationAngle;
	Vec2f scaleFactor;

	/**
	 * Transformiert die aktuelle Matrix so wie gewünscht. Vorher bitte
	 * glPushMatrix() und nachher glPopMatrix() aufrufen Diese Methode
	 * muss von allen Klassen, die von Transformable erben in ihrer Draw-Methode
	 * aufgerufen werden!
	 */
	void transform();


	public:
	Vec2f getTranslate() { return translate; }
	void setTranslate( Vec2f translate ) { this->translate = translate; }
	Vec2f getRotationPoint() { return rotationPoint; }
	void setRotationPoint( Vec2f rotationPoint ) { this->rotationPoint = rotationPoint; }
	double getRotationAngle() { return rotationAngle; }
	void setRotationAngle( double rotationAngle ) { this->rotationAngle = rotationAngle; }
	Vec2f getScaleFactor() { return scaleFactor; }
	void setScaleFactor( Vec2f scaleFactor ) { this->scaleFactor = scaleFactor; }

};


#endif
