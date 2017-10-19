#pragma once
#include "Shape2D.h"

// A class derived from Shape2D that is a square
class Square2D : public Shape2D
{
public:
	// Constructor passes the location and color to the parent and copies side
	Square2D(const Point2D &location, const Color &color, double side);
	// Draws the square using openGL
	void draw() const;
	// Changes the square's side to the parameter provided
	void changeSide(double newSide);
protected:
	double side;
};

