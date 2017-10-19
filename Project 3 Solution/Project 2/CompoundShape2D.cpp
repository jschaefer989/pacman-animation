#include "CompoundShape2D.h"
#include "Triangle2D.h"
#include <iostream>
#include <GL/GLUT.h>
using namespace std;

// A constructor that passes the location and color to Shape2D
CompoundShape2D::CompoundShape2D(const Point2D &location, const Color &color)
	: Shape2D(location, color)
{
}

// Destructor that deletes all objects in the Shape2D* vector and prints "Scene destroyed."
CompoundShape2D::~CompoundShape2D()
{
	for (unsigned int i = 0; i < shapes.size(); i++)
	{
		delete shapes[i];
	}
	cout << "Compound Shapes destroyed." << endl;
}

// This function calls the draw function of every object in the vector
void CompoundShape2D::draw() const
{
	// Set the current color
	color.tellOpenGL();
	glPushMatrix();
	// Set the origin of the shape
	glTranslatef(location.x, location.y, 0);
	for (unsigned int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->draw();
	}
	glEnd();
	glPopMatrix();	
}

// Add a new shape object to the vector
void CompoundShape2D::addShape(Shape2D* shape)
{
	shapes.push_back(shape);
}

// Removes a shape object from the vector at the given index
void CompoundShape2D::deleteShape(unsigned int index)
{
	// If the index is less than the vector's size, delete the shape object at the index
	// and remove the shape object from the vector at the index
	if (shapes.size() > index)
	{
		delete shapes[index];
		shapes.erase(shapes.begin() + index);
	}
	// If the index is outside of the vector's size, print the following
	else
	{
		cout << "There is no shape to delete at that index. " << endl;
	}
}

// A function to return the shape object as a pointer at the given index
Shape2D* CompoundShape2D::getShape(int index)
{
	return shapes[index];
}

// A function to move all of the shapes in the compound shape at once
void CompoundShape2D::move(double deltaX, double deltaY)
{
	// For each shape in the compound shape:
	for (int i = 0; i < shapes.size(); i++)
	{				
		// If the shape isn't a triangle, move the current location + the given parameters
		if (dynamic_cast<Triangle2D*>(shapes[i]) == NULL)
		{
			shapes[i]->move((shapes[i]->getLocation().x) + deltaX, (shapes[i]->getLocation().y) + deltaY);
		}
		// If it is a triangle, cast it to one, then move the current location + the given parameters
		else
		{
			Triangle2D* triangle = dynamic_cast<Triangle2D*>(shapes[i]);
			triangle->move((shapes[i]->getLocation().x) + (deltaX*2), (shapes[i]->getLocation().y) + (deltaY*2));
		}		
	}	
}

