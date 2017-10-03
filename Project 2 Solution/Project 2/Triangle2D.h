#pragma once
#include "Shape2D.h"

// A class derived from Shape2D that is a triangle
class Triangle2D : public Shape2D
{
public:
	// Constructor passes the location, color and name to the parent and copies point A, point B, and point C
	Triangle2D(const Point2D &location, const Color &color, const string &name, const Point2D &pointA, const Point2D &pointB, const Point2D &pointC);
	// Prints out all of the triangle's parameters
	void const draw();
	// Changes the triangle's point A to the parameter provided
	void changePointA(const Point2D &newPoint);
	// Changes the triangle's point B to the parameter provided
	void changePointB(const Point2D &newPoint);
	// Changes the triangle's point C to the parameter provided
	void changePointC(const Point2D &newPoint);

protected:
	// Point2D objects to act as the three corners of the triangle
	Point2D pointA;
	Point2D pointB;
	Point2D pointC;
};

