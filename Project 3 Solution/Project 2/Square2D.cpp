#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "Square2D.h"
#include <GL/GLUT.h>

// Constructor passes the location and color to the parent and copies side
Square2D::Square2D(const Point2D &location, const Color &color, double side) : Shape2D(location, color), side(side)
{
}

// Draws the square using openGL
void Square2D::draw() const
{
	// Set the current color
	color.tellOpenGL();
	glPushMatrix();
	// Set the origin of the shape
	glTranslatef(location.x, location.y, 0);
	glBegin(GL_QUADS);
	// Draw the square using the side parameter and the corresponding x and y coordinates 
	glVertex2f(location.x, location.y);
	glVertex2f(location.x, location.y + side);
	glVertex2f(location.x + side, location.y + side);
	glVertex2f(location.x + side, location.y);
	glEnd();
	glPopMatrix();
}

// Changes the square's side to the parameter provided
void Square2D::changeSide(double newSide)
{
	this->side = newSide;
}
