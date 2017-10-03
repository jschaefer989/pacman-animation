#pragma once
#include "Shape2D.h"

// A class derived from Shape2D that is a square
class Square2D : public Shape2D
{
public:
	// Constructor passes the location, color and name to the parent and copies side
	Square2D(const Point2D &location, const Color &color, const string &name, double side);
	// Prints out all of the square's parameters
	void const draw();
	// Changes the square's side to the parameter provided
	void changeSide(double newSide);
protected:
	double side;
};

