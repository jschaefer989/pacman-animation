#include "Point2D.h"
#include <string>
#include "Color.h"
using namespace std;
#pragma once

// An abstract shape class that more specific shapes will inherit from
class Shape2D
{
public:
	// Constructor copies all parameters
	Shape2D(const Point2D &location, const Color &color, const string &name);
	// A pure virtual function that will print out all member variables in the specific shapes
	virtual const void draw() = 0;
	// A function to move the shape's location
	void move(double deltaX, double deltaY);

protected:
	// A Point2D object to resemble the location
	Point2D location;
	// A string that holds the shape's name such as triangle
	string name;
	// A Color object to hold the color string
	Color color;
};
