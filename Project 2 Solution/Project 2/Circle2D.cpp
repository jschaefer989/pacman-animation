#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
#include "Circle2D.h"
#include <GL/GLUT.h>

// Constructor passes the location, color and name to the parent and copies radius
Circle2D::Circle2D(const Point2D &location, const Color &color, const string &name, double radius) : Shape2D(location, color, name), radius(radius)
{
}

// Prints out all of the circle's parameters
void const Circle2D::draw()
{
	color.tellOpenGL();
	glPushMatrix();
	glTranslatef(location.x, location.y, 0);
	const double PI = 3.14159265359;
	const int NUM_OF_TRIANGLES = 1000;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(location.x, location.y);
	for (int i = 0; i < NUM_OF_TRIANGLES; i++)
	{
		glVertex2f(location.x+(radius*cos(i+(2.0*PI)/NUM_OF_TRIANGLES)), location.y+(radius*sin(i+(2.0f*PI) / NUM_OF_TRIANGLES)));
	}
	glEnd();
	glPopMatrix();
}

// Changes the circle's radius to the parameter provided
void Circle2D::changeRad(double newRad)
{
	this->radius = newRad;
}