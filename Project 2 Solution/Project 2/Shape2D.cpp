#include "Shape2D.h"
#include <GL/GLUT.h>

// Constructor copies all parameters
Shape2D::Shape2D(const Point2D &location, const Color &color, const string &name) : location(location), color(color), name(name)
{
}

// A function to move the shape's location
void Shape2D::move(double deltaX, double deltaY)
{
	// Take the x value from the Point2D object and add it to deltaX that's provided
	location.x += deltaX;
	// Take the y value from the Point2D object and add it to deltaY that's provided
	location.y += deltaY;
}
