#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <GL/GLUT.h>
using namespace std;

#include "Circle2D.h"
#include "Color.h"
#include "Point2D.h"
#include "Rectangle2D.h"
#include "Scene.h"
#include "Shape2D.h"
#include "Square2D.h"
#include "Triangle2D.h"

int main(int argc, char** argv)
{
	vector<Shape2D*> shapes;
	Scene scene(800, 600, shapes);

	Point2D pointA(10, 10);
	Color colorA(COLOR_LIMEGREEN);
	scene.addShape(new Square2D(pointA, colorA, "Square", 230));

	Point2D pointB(110, 200);
	Color colorB(COLOR_CORNFLOWERBLUE);
	scene.addShape(new Rectangle2D(pointB, colorB, "Rectangle", 230, 120));

	Point2D location(50, 50);
	Point2D pointC1(250, 200);
	Point2D pointC2(280, 240);
	Point2D pointC3(320, 210);
	Color colorC(COLOR_MINTCREAM);
	scene.addShape(new Triangle2D(location, colorC, "Triangle", pointC1, pointC2, pointC3));

	Point2D pointD(50, 200);
	Color colorD(COLOR_DARKBLUE);
	scene.addShape(new Circle2D(pointD, colorD, "Circle", 80));

	scene.nextFrame();

	scene.startEventLoop();

	return 0;
}