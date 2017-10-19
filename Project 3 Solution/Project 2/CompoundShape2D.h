#pragma once
#include <cstdlib>
#include <vector>
#include <iostream>
#include "GLUTScene.h"
#include "Shape2D.h"

using namespace std;
class CompoundShape2D :
	public Shape2D
{
public:
	// A constructor that passes the location and color to Shape2D
	CompoundShape2D(const Point2D &location, const Color &color);
	// Destructor that deletes all objects in the Shape2D* vector and prints "Scene destroyed."
	~CompoundShape2D();
	// This function calls the draw function of every object in the vector
	void draw() const;
	// Add a new shape object to the vector
	void addShape(Shape2D* shape);
	// Removes a shape object from the vector at the given index
	void deleteShape(unsigned int index);
	// A function to return the shape object as a pointer at the given index
	Shape2D* getShape(int index);
	// A function to move all of the shapes in the compound shape at once
	void move(double deltaX, double deltaY);

private:
	// A vector to hold Shape2D object pointers
	vector<Shape2D*> shapes;
};

