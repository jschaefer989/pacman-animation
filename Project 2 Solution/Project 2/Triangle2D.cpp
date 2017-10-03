#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "Point2D.h"
#include "Triangle2D.h"
#include <GL/GLUT.h>

// Constructor passes the location, color and name to the parent and copies point A, point B, and point C
Triangle2D::Triangle2D(const Point2D &location, const Color &color, const string &name, const Point2D &pointA, const Point2D &pointB, const Point2D &pointC) : Shape2D(location, color, name), pointA(pointA), pointB(pointB), pointC(pointC)
{
}

// Prints out all of the triangle's parameters
void const Triangle2D::draw()
{
	color.tellOpenGL();
	glPushMatrix();
	glTranslatef(location.x, location.y, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(pointA.x + location.x, pointA.y + location.y);
	glVertex2f(pointB.x + location.x, pointB.y + location.y);
	glVertex2f(pointC.x + location.x, pointC.y + location.y);	
	glEnd();
	glPopMatrix();
}

// Changes the triangle's point A to the parameter provided
void Triangle2D::changePointA(const Point2D &newPoint)
{
	this->pointA = newPoint;
}

// Changes the triangle's point B to the parameter provided
void Triangle2D::changePointB(const Point2D &newPoint)
{
	this->pointB = newPoint;
}

// Changes the triangle's point C to the parameter provided
void Triangle2D::changePointC(const Point2D &newPoint)
{
	this->pointC = newPoint;
}