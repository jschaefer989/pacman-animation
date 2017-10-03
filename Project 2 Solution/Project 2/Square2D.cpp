#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "Square2D.h"
#include <GL/GLUT.h>

// Constructor passes the location, color and name to the parent and copies side
Square2D::Square2D(const Point2D &location, const Color &color, const string &name, double side) : Shape2D(location, color, name), side(side)
{
}

// Prints out all of the square's parameters
void const Square2D::draw()
{
	color.tellOpenGL();
	glPushMatrix();
	glTranslatef(location.x, location.y, 0);
	glBegin(GL_QUADS);
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
