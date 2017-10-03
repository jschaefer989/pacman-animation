#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "Rectangle2D.h"
#include <GL/GLUT.h>

// Constructor passes the location, color and name to the parent and copies length and height
Rectangle2D::Rectangle2D(const Point2D &location, const Color &color, const string &name, double length, double height) : Shape2D(location, color, name), length(length), height(height)
{
}

// Prints out all of the rectangle's parameters
void const Rectangle2D::draw()
{
	color.tellOpenGL();
	glPushMatrix();
	glTranslatef(location.x, location.y, 0);
	glBegin(GL_QUADS);
	glVertex2f(location.x, location.y);
	glVertex2f(location.x, location.y + height);
	glVertex2f(location.x + length, location.y + height);
	glVertex2f(location.x + length, location.y);
	glEnd();
	glPopMatrix();
}

// Changes the rectangle's length to the parameter provided
void Rectangle2D::changeLength(double newLength)
{
	this->length = newLength;
}

// Changes the rectangle's height to the parameter provided
void Rectangle2D::changeHeight(double newHeight)
{
	this->height = newHeight;
}