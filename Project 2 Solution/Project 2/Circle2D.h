#pragma once
#include "Shape2D.h"

// A class derived from Shape2D that is a circle
class Circle2D : public Shape2D
{
public:
	// Constructor passes the location, color and name to the parent and copies radius
	Circle2D(const Point2D &location, const Color &color, const string &name, double radius);
	// Prints out all of the circle's parameters
	void const draw();
	// Changes the circle's radius to the parameter provided
	void changeRad(double newRad);

protected:
	double radius;
};

