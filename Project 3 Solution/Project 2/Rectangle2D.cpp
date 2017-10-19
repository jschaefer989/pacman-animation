#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "Rectangle2D.h"
#include <GL/GLUT.h>

// Constructor passes the location and color to the parent and copies length and height
Rectangle2D::Rectangle2D(const Point2D &location, const Color &color, double length, double height) : Shape2D(location, color), length(length), height(height)
{
}

// Draws the rectangle using openGL
void Rectangle2D::draw() const
{
	// Set the current color
	color.tellOpenGL();
	glPushMatrix();
	// Set the origin 
	glTranslatef(location.x, location.y, 0);
	glBegin(GL_QUADS);
	// Create the rectangle by adding the length and height to the corresponding x or y coordinate
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