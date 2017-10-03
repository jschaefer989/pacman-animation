#pragma once
#include "Shape2D.h"

// A class derived from Shape2D that is a rectangle
class Rectangle2D :
	public Shape2D
{
public:
	// Constructor passes the location, color and name to the parent and copies length and height
	Rectangle2D(const Point2D &location, const Color &color, const string &name, double length, double height);
	// Prints out all of the rectangle's parameters
	void const draw();
	// Changes the rectangle's length to the parameter provided
	void changeLength(double newLength);
	// Changes the rectangle's height to the parameter provided
	void changeHeight(double newHeight);

protected:
	double length; 
	double height;
};

