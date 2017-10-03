#include <cstdlib>
#include <vector>
#include "GLUTScene.h"
#include "Shape2D.h"
#pragma once

class Scene : public GLUTScene
{
public:
	// Constructor copies the Shape2D* vector
	Scene(unsigned int width, unsigned int height, vector<Shape2D*> shapes);
	// Destructor that deletes all objects in the Shape2D* vector and prints "Scene destroyed."
	~Scene();
	// Add a new shape object to the vector
	void addShape(Shape2D* shape);
	// Removes a shape object from the vector at the given index
	void deleteShape(unsigned int index);
	// A function to return the shape object as a pointer at the given index
	Shape2D* getShape(int index);
	// This function calls the draw function of every object in the vector
	void draw() const;
	void nextFrame();
	
private:
	// A vector to hold Shape2D object pointers
	vector<Shape2D*> shapes;
};

