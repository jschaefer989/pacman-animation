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
#include "CompoundShape2D.h"

// This function draws all of the individual shapes that make up the maze and the square cookies
void drawMaze(Scene &scene);

int main(int argc, char** argv)
{	
	// Create a scene with a given width and height
	Scene scene(765, 700);

	drawMaze(scene);

	// The following is code for drawing each individual compound shape using several Shape2D objects
	// with a provided Point2D object and Color object which are then added to the collective compound
	// shape. Each compound shape is labeled.

	///////////////CHERRIES////////////////////

	Point2D cherPt(30, 180);
	CompoundShape2D* cher = new CompoundShape2D(cherPt, COLOR_RED);
	scene.addShape(cher);

	Color si(COLOR_SIENNA);
	Point2D c3(27, 190);
	cher->addShape(new Rectangle2D(c3, si, 10, 20));

	Point2D c4(30, 200);
	cher->addShape(new Rectangle2D(c4, si, 10, 15));

	Point2D c5(35, 205);
	cher->addShape(new Rectangle2D(c5, si, 10, 10));

	Point2D c6(18, 195);
	cher->addShape(new Rectangle2D(c6, si, 10, 20));

	Point2D c7(22, 203);
	cher->addShape(new Rectangle2D(c7, si, 10, 10));

	Point2D c8(27, 204);
	cher->addShape(new Rectangle2D(c8, si, 10, 10));

	Point2D c1(20, 185);
	cher->addShape(new Circle2D(c1, COLOR_FIREBRICK, 25));

	cher->addShape(new Circle2D(cherPt, cher->getColor(), 25));

	Color w(COLOR_WHITE);
	Point2D c2(25, 185);
	cher->addShape(new Circle2D(c2, w, 5));

	/////////////STRAWBERRY//////////////////////
	Point2D strawPt(240, 190);
	CompoundShape2D* straw = new CompoundShape2D(strawPt, COLOR_RED);
	scene.addShape(straw);
	straw->addShape(new Circle2D(strawPt, straw->getColor(), 20));

	Point2D st1(220, 190);
	straw->addShape(new Circle2D(st1, straw->getColor(), 20));

	Point2D st2(220, 185);
	straw->addShape(new Rectangle2D(st2, straw->getColor(), 40, 30));

	Point2D st3(212, 185);
	Point2D st4(250, 145);
	Point2D st5(285, 185);
	straw->addShape(new Triangle2D(st3, straw->getColor(), st3, st4, st5));

	Point2D st6(220, 190);
	straw->addShape(new Rectangle2D(st6, COLOR_GREEN, 40, 10));

	Point2D st7(215, 195);
	straw->addShape(new Rectangle2D(st7, COLOR_GREEN, 60, 10));

	Point2D st8(227, 195);
	straw->addShape(new Rectangle2D(st8, COLOR_GREEN, 10, 25));

	Point2D st9(235, 175);
	straw->addShape(new Square2D(st9, COLOR_WHITE, 10));

	Point2D st10(225, 182);
	straw->addShape(new Square2D(st10, COLOR_WHITE, 10));

	Point2D st11(237, 185);
	straw->addShape(new Square2D(st11, COLOR_WHITE, 10));

	////////////////////ORANGE//////////////////////////////////////////////

	Point2D orangePt(25, 45);
	CompoundShape2D* orange = new CompoundShape2D(orangePt, COLOR_ORANGE);
	scene.addShape(orange);
	orange->addShape(new Circle2D(orangePt, orange->getColor(), 30));

	Point2D o1(22, 55);
	orange->addShape(new Rectangle2D(o1, COLOR_GREEN, 10, 20));

	Point2D o2(22, 63);
	orange->addShape(new Rectangle2D(o2, COLOR_GREEN, 30, 10));

	Point2D o3(15, 43);
	orange->addShape(new Rectangle2D(o3, COLOR_YELLOW, 10, 20));

	/////////////////PRETZEL/////////////////////////
	Point2D pretzelPt(217, 45);
	CompoundShape2D* pretzel = new CompoundShape2D(pretzelPt, COLOR_SIENNA);
	scene.addShape(pretzel);
	Color b(COLOR_SIENNA);
	pretzel->addShape(new Rectangle2D(pretzelPt, b, 15, 40));

	Point2D p1(250, 45);
	pretzel->addShape(new Rectangle2D(p1, b, 15, 40));

	Point2D p2(221, 65);
	pretzel->addShape(new Rectangle2D(p2, b, 20, 15));

	Point2D p3(244, 65);
	pretzel->addShape(new Rectangle2D(p3, b, 20, 15));

	Point2D p4(223, 40);
	pretzel->addShape(new Rectangle2D(p4, b, 57, 15));

	Point2D px(230, 37);
	pretzel->addShape(new Rectangle2D(px, b, 30, 15));

	Point2D p5(227, 60);
	pretzel->addShape(new Square2D(p5, b, 15));

	Point2D p6(231, 55);
	pretzel->addShape(new Square2D(p6, b, 15));

	Point2D p7(236, 50);
	pretzel->addShape(new Square2D(p7, b, 15));

	Point2D p8(240, 46);
	pretzel->addShape(new Square2D(p8, b, 15));

	Point2D p9(247, 37);
	pretzel->addShape(new Square2D(p9, b, 15));

	Point2D p10(240, 60);
	pretzel->addShape(new Square2D(p10, b, 15));

	Point2D p11(235, 55);
	pretzel->addShape(new Square2D(p11, b, 15));

	Point2D p12(227, 50);
	pretzel->addShape(new Square2D(p12, b, 15));

	Point2D p13(223, 45);
	pretzel->addShape(new Square2D(p13, b, 15));

	Point2D p14(213, 39);
	pretzel->addShape(new Square2D(p14, b, 15));

	Point2D s1(230, 65);
	Color s(COLOR_WHITE);
	pretzel->addShape(new Square2D(s1, s, 10));

	Point2D s2(245, 42);
	pretzel->addShape(new Square2D(s2, s, 10));

	Point2D s3(225, 43);
	pretzel->addShape(new Square2D(s3, s, 10));

	///////////GHOST1/////////////////////////////////////////////////////

	Point2D ghostPt(90, 150);
	CompoundShape2D* ghost = new CompoundShape2D(ghostPt, COLOR_ORCHID);
	scene.addShape(ghost);
	ghost->addShape(new Circle2D(ghostPt, ghost->getColor(), 45));

	Point2D pointA2(65, 127);
	Color hide(COLOR_BLACK);
	ghost->addShape(new Rectangle2D(pointA2, hide, 100, 45));

	Point2D pointA3(67, 140);
	ghost->addShape(new Rectangle2D(pointA3, COLOR_ORCHID, 92, 20));

	Point2D pointA4(68, 160);
	Point2D T1(65, 120);
	Point2D T2(100, 120);
	Point2D T3(82, 90);
	Color body(COLOR_ORCHID);
	ghost->addShape(new Triangle2D(pointA4, body, T1, T2, T3));

	Point2D pointA5(97, 160);
	ghost->addShape(new Triangle2D(pointA5, body, T1, T2, T3));

	Point2D pointA6(125, 160);
	ghost->addShape(new Triangle2D(pointA6, body, T1, T2, T3));

	Point2D pointA7(80, 153);
	Color eye(COLOR_WHITE);
	ghost->addShape(new Circle2D(pointA7, eye, 15));

	Point2D pointA8(100, 153);
	ghost->addShape(new Circle2D(pointA8, eye, 15));

	Point2D pointA9(76, 145);
	Color iris(COLOR_BLUE);
	ghost->addShape(new Rectangle2D(pointA9, COLOR_BLUE, 15, 15));

	Point2D pointA10(96, 145);
	ghost->addShape(new Rectangle2D(pointA10, COLOR_BLUE, 15, 15));

	/////////////GHOST2/////////////////////////////////////////////////////////////

	Point2D ghostPt2(90, 150);
	CompoundShape2D* ghost2 = new CompoundShape2D(ghostPt2, COLOR_CYAN);
	scene.addShape(ghost2);
	ghost2->addShape(new Circle2D(ghostPt2, COLOR_CYAN, 45));

	Point2D pointG2(65, 127);
	ghost2->addShape(new Rectangle2D(pointG2, hide, 100, 45));

	Color c(COLOR_CYAN);
	Point2D pointG3(67, 140);
	ghost2->addShape(new Rectangle2D(pointG3, c, 92, 20));

	Point2D pointG4(68, 160);
	Point2D T7(65, 120);
	Point2D T8(100, 120);
	Point2D T9(82, 90);
	ghost2->addShape(new Triangle2D(pointG4, c, T7, T8, T9));

	Point2D pointG5(97, 160);
	ghost2->addShape(new Triangle2D(pointG5, c, T1, T2, T3));

	Point2D pointG6(125, 160);
	ghost2->addShape(new Triangle2D(pointG6, c, T1, T2, T3));

	Point2D pointG7(80, 153);
	ghost2->addShape(new Circle2D(pointG7, eye, 15));

	Point2D pointG8(100, 153);
	ghost2->addShape(new Circle2D(pointG8, eye, 15));

	Point2D pointG9(76, 145);
	ghost2->addShape(new Rectangle2D(pointG9, iris, 15, 15));

	Point2D pointG10(96, 145);
	ghost2->addShape(new Rectangle2D(pointG10, iris, 15, 15));

	////////////////PACMAN///////////////////////////////////////////////////////////////////
	// There are seven pacman compound shapes below that are used to make pacman appear to rotate during the animation

	// This pacman will move right
	Point2D pacmanPt(20, 118);
	CompoundShape2D* pacman = new CompoundShape2D(pacmanPt, COLOR_YELLOW);			
	scene.addShape(pacman);	
	pacman->addShape(new Circle2D(pacman->getLocation(), pacman->getColor(), 30));
	Point2D triangle1(30, 134);
	Point2D triangle2(30, 106);
	Point2D triangle3(0, 120);
	pacman->addShape(new Triangle2D(Point2D(40, 116), Color COLOR_BLACK, triangle1, triangle2, triangle3));
	pacman->addShape(new Circle2D(Point2D(23, 126), Color  COLOR_BLACK, 5));	

	// This pacman will move up
	Point2D pacmanPtUp(60, 0);
	CompoundShape2D* pacmanUp = new CompoundShape2D(pacmanPtUp, COLOR_BLACK);
	scene.addShape(pacmanUp);
	pacmanUp->addShape(new Circle2D(pacmanUp->getLocation(), pacmanUp->getColor(), 30));
	Point2D triangle1Up(40, 45);
	Point2D triangle2Up(80, 45);
	Point2D triangle3Up(60, 0);
	pacmanUp->addShape(new Triangle2D(Point2D(60, 0), Color COLOR_BLACK, triangle1Up, triangle2Up, triangle3Up));
	pacmanUp->addShape(new Circle2D(Point2D(52, 4), Color  COLOR_BLACK, 5));

	// This pacman will move right
	Point2D pacmanPt2(60, 20);
	CompoundShape2D* pacman2 = new CompoundShape2D(pacmanPt2, COLOR_BLACK);
	scene.addShape(pacman2);
	pacman2->addShape(new Circle2D(pacman2->getLocation(), pacman2->getColor(), 30));
	Point2D triangle12(100, 38);
	Point2D triangle22(100, 3);
	Point2D triangle32(60, 20);
	pacman2->addShape(new Triangle2D(Point2D(60, 20), Color COLOR_BLACK, triangle12, triangle22, triangle32));
	pacman2->addShape(new Circle2D(Point2D(63, 28), Color  COLOR_BLACK, 5));

	// This pacman will move down
	Point2D pacmanPtDown(130, 20);
	CompoundShape2D* pacmanDown = new CompoundShape2D(pacmanPtDown, COLOR_BLACK);
	scene.addShape(pacmanDown);
	pacmanDown->addShape(new Circle2D(pacmanDown->getLocation(), pacmanDown->getColor(), 30));
	Point2D triangle1Down(150, -10);
	Point2D triangle2Down(110, -10);
	Point2D triangle3Down(130, 20);
	pacmanDown->addShape(new Triangle2D(Point2D(130, 20), Color COLOR_BLACK, triangle1Down, triangle2Down, triangle3Down));
	pacmanDown->addShape(new Circle2D(Point2D(138, 18), Color  COLOR_BLACK, 5));

	// This pacman will move right
	Point2D pacmanPt3(130, 20);
	CompoundShape2D* pacman3 = new CompoundShape2D(pacmanPt3, COLOR_BLACK);
	scene.addShape(pacman3);
	pacman3->addShape(new Circle2D(pacman3->getLocation(), pacman3->getColor(), 30));
	Point2D triangle13(170, 38);
	Point2D triangle23(170, 3);
	Point2D triangle33(130, 20);
	pacman3->addShape(new Triangle2D(Point2D(130, 20), Color COLOR_BLACK, triangle13, triangle23, triangle33));
	pacman3->addShape(new Circle2D(Point2D(133, 28), Color  COLOR_BLACK, 5));
	
	// This pacman will move up
	Point2D pacmanPtUp2(180, 20);
	CompoundShape2D* pacmanUp2 = new CompoundShape2D(pacmanPtUp2, COLOR_BLACK);
	scene.addShape(pacmanUp2);
	pacmanUp2->addShape(new Circle2D(pacmanUp2->getLocation(), pacmanUp2->getColor(), 30));
	Point2D triangle12Up(160, 50);
	Point2D triangle22Up(200, 50);
	Point2D triangle32Up(180, 20);
	pacmanUp2->addShape(new Triangle2D(Point2D(180, 20), Color COLOR_BLACK, triangle12Up, triangle22Up, triangle32Up));
	pacmanUp2->addShape(new Circle2D(Point2D(170, 23), Color  COLOR_BLACK, 5));

	// This pacman will move right
	Point2D pacmanPt4(250, 118);
	CompoundShape2D* pacman4 = new CompoundShape2D(pacmanPt4, COLOR_BLACK);
	scene.addShape(pacman4);
	pacman4->addShape(new Circle2D(pacman4->getLocation(), pacman4->getColor(), 30));
	Point2D triangle14(280, 134);
	Point2D triangle24(280, 106);
	Point2D triangle34(250, 118);
	pacman4->addShape(new Triangle2D(Point2D(250, 116), Color COLOR_BLACK, triangle14, triangle24, triangle34));
	pacman4->addShape(new Circle2D(Point2D(253, 126), Color  COLOR_BLACK, 5));	
	
	// The following function calls cause the animation to run
	scene.startEventLoop();
	scene.startAnimationTimer();		
	scene.stopAnimationTimer();

	return 0;
}

// This function draws all of the individual shapes that make up the maze and the square cookies
void drawMaze(Scene &scene)
{
	Point2D point1(0, 150);
	Color border(COLOR_DARKBLUE);
	scene.addShape(new Rectangle2D(point1, border, 120, 3));

	Point2D point2(0, 200);
	scene.addShape(new Rectangle2D(point2, border, 120, 3));

	Point2D point3(60, 151.5);
	scene.addShape(new Rectangle2D(point3, border, 3, -103));

	Point2D point4(60, 200);
	scene.addShape(new Rectangle2D(point4, border, 3, 103));

	Point2D point5(10, 100);
	scene.addShape(new Rectangle2D(point5, border, 100, 3));

	Point2D point6(10, 100);
	scene.addShape(new Rectangle2D(point6, border, 3, -107));

	Point2D point7(10, 250);
	scene.addShape(new Rectangle2D(point7, border, 3, 110));

	Point2D point8(10, 250);
	scene.addShape(new Rectangle2D(point8, border, 100, 3));

	Point2D point9(10, 46.5);
	scene.addShape(new Rectangle2D(point9, border, 725, 3));

	Point2D point10(372, 46.5);
	scene.addShape(new Rectangle2D(point10, border, 3, 110));

	Point2D point11(372, 100);
	scene.addShape(new Rectangle2D(point11, border, -103, 3));

	Point2D point12(319, 100);
	scene.addShape(new Rectangle2D(point12, border, 3, 103));

	Point2D point13(319, 150);
	scene.addShape(new Rectangle2D(point13, border, 120, 3));

	Point2D point14(319, 200);
	scene.addShape(new Rectangle2D(point14, border, 120, 3));

	Point2D point15(319, 200);
	scene.addShape(new Rectangle2D(point15, border, 3, 103));

	Point2D point16(372, 250);
	scene.addShape(new Rectangle2D(point16, border, -103, 3));

	Point2D point17(372, 250);
	scene.addShape(new Rectangle2D(point17, border, 3, 110));

	Point2D point18(10, 305);
	scene.addShape(new Rectangle2D(point18, border, 727, 3));

	Point2D point19(125, 250);
	scene.addShape(new Rectangle2D(point19, border, 80, 3));

	Point2D point20(125, 100);
	scene.addShape(new Rectangle2D(point20, border, 80, 3));

	Point2D point21(225, 250);
	scene.addShape(new Rectangle2D(point21, border, 80, 3));

	Point2D point22(225, 100);
	scene.addShape(new Rectangle2D(point22, border, 80, 3));

	Point2D point23(125, 100);
	scene.addShape(new Rectangle2D(point23, border, 3, 300));

	Point2D point24(165, 100);
	scene.addShape(new Rectangle2D(point24, border, 3, 303));

	Point2D point25(225, 100);
	scene.addShape(new Rectangle2D(point25, border, 3, 300));

	Point2D point26(265, 100);
	scene.addShape(new Rectangle2D(point26, border, 3, 303));



	Point2D pointA(85, 170);
	Color cookie(COLOR_WHITE);
	const double COOKIE_SIZE = 30;
	scene.addShape(new Square2D(pointA, cookie, COOKIE_SIZE));

	Point2D pointB(85, 220);
	scene.addShape(new Square2D(pointB, cookie, COOKIE_SIZE));

	Point2D pointC(85, 270);
	scene.addShape(new Square2D(pointC, cookie, COOKIE_SIZE));

	Point2D pointS(140, 270);
	scene.addShape(new Square2D(pointS, cookie, COOKIE_SIZE));

	Point2D pointH(190, 270);
	scene.addShape(new Square2D(pointH, cookie, COOKIE_SIZE));

	Point2D pointG(190, 220);
	scene.addShape(new Square2D(pointG, cookie, COOKIE_SIZE));

	Point2D pointF(185, 160);
	scene.addShape(new Square2D(pointF, cookie, 50));

	Point2D pointI(190, 120);
	scene.addShape(new Square2D(pointI, cookie, COOKIE_SIZE));

	Point2D pointJ(190, 70);
	scene.addShape(new Square2D(pointJ, cookie, COOKIE_SIZE));

	Point2D pointP(240, 70);
	scene.addShape(new Square2D(pointP, cookie, COOKIE_SIZE));

	Point2D pointO(285, 70);
	scene.addShape(new Square2D(pointO, cookie, COOKIE_SIZE));

	Point2D pointN(285, 120);
	scene.addShape(new Square2D(pointN, cookie, COOKIE_SIZE));

	Point2D pointK(285, 170);
	scene.addShape(new Square2D(pointK, cookie, COOKIE_SIZE));

	Point2D pointD(85, 120);	
	scene.addShape(new Square2D(pointD, cookie, COOKIE_SIZE));

	Point2D pointE(85, 70);
	scene.addShape(new Square2D(pointE, cookie, COOKIE_SIZE));		

	Point2D pointL(285, 220);
	scene.addShape(new Square2D(pointL, cookie, COOKIE_SIZE));

	Point2D pointM(285, 270);
	scene.addShape(new Square2D(pointM, cookie, COOKIE_SIZE));

	Point2D pointQ(140, 70);
	scene.addShape(new Square2D(pointQ, cookie, COOKIE_SIZE));

	Point2D pointR(240, 270);
	scene.addShape(new Square2D(pointR, cookie, COOKIE_SIZE));
}