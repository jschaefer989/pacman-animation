#include "Shape2D.h"
#include <GL/GLUT.h>

// Constructor copies all parameters
Shape2D::Shape2D(const Point2D &location, const Color &color) : location(location), color(color)
{
}

// A function to move the shape's location
void Shape2D::move(double deltaX, double deltaY)
{
	// Take the x value from the Point2D object and add it to deltaX that's provided
	location.x = deltaX;
	// Take the y value from the Point2D object and add it to deltaY that's provided
	location.y = deltaY;
}

// Change the current color to the one provided
void Shape2D::changeColor(const Color &newClr)
{
	this->color = newClr;
}

// Getter for location
Point2D Shape2D::getLocation()
{
	return this->location;
}

// Getter for color
Color Shape2D::getColor()
{
	return this->color;
}