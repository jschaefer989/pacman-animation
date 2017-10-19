#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "Point2D.h"
#include "Triangle2D.h"
#include <GL/GLUT.h>

// Constructor passes the location and color to the parent and copies point A, point B, and point C
Triangle2D::Triangle2D(const Point2D &location, const Color &color, const Point2D &pointA, const Point2D &pointB, const Point2D &pointC) : Shape2D(location, color), pointA(pointA), pointB(pointB), pointC(pointC)
{
}

// Draws the triangle using openGL
void Triangle2D::draw() const
{
	// Set the current color
	color.tellOpenGL();
	glPushMatrix();
	// Set the origin of the shape
	glTranslatef(location.x, location.y, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(pointA.x, pointA.y);
	glVertex2f(pointB.x, pointB.y);
	glVertex2f(pointC.x, pointC.y);	
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