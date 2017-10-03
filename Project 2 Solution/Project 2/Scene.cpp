#include <iostream>
using namespace std;

#include <GL/GLUT.h>
#include "Scene.h"

// Constructor copies the Shape2D* vector
Scene::Scene(unsigned int width, unsigned int height, vector<Shape2D*> shapes)
	: GLUTScene(width, height), shapes(shapes)
{
}

// Destructor that deletes all objects in the Shape2D* vector and prints "Scene destroyed."
Scene::~Scene()
{
	for (unsigned int i = 0; i < shapes.size(); i++)
	{
		delete shapes[i];
	}
	cout << "Scene destroyed." << endl;
}

// Add a new shape object to the vector
void Scene::addShape(Shape2D* shape)
{
	shapes.push_back(shape);
}

// Removes a shape object from the vector at the given index
void Scene::deleteShape(unsigned int index)
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
Shape2D* Scene::getShape(int index)
{
	return shapes[index];
}

// This function calls the draw function of every object in the vector
void Scene::draw() const
{
	for (unsigned int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->draw();
	}
	cout << endl;
}

void Scene::nextFrame()
{
	for (unsigned int i = 0; i < timeoutMillis; i++)
	{
		draw();
	}
}