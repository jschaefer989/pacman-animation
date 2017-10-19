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
	Shape2D(const Point2D &location, const Color &color);
	// A pure virtual function that will print out all member variables in the specific shapes
	virtual void draw() const = 0;
	// A function to move the shape's location
	void move(double deltaX, double deltaY);
	// Change the current color to the one provided
	void changeColor(const Color &newClr);
	// Getter for location
	Point2D getLocation();
	// Getter for color
	Color getColor();

protected:
	// A Point2D object to resemble the location
	Point2D location;
	// A string that holds the shape's name such as triangle
	string name;
	// A Color object to hold the color string
	Color color;
};
