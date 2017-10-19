#include <iostream>
using namespace std;

#include <GL/GLUT.h>
#include "Scene.h"
#include "Triangle2D.h"

// Constructor copies the Shape2D* vector
Scene::Scene(unsigned int width, unsigned int height)
	: GLUTScene(width, height)
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
}

// This is a function for advancing to the next frame and keeping track of the amount of frames
void Scene::nextFrame()
{
	frameCount++;
	animate(frameCount);
	cout << frameCount << endl;
}

// A function that does all of the color changing/moving to create animation
void Scene::animate(int frameCount)
{
	// For the first 120 frames:
	if (frameCount <= 120)
	{
		// Move the first ghost and first pacman right
		shapes[shapes.size()-7]->move(shapes[shapes.size()-7]->getLocation().x+1, shapes[shapes.size()-7]->getLocation().y);

		shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x+1, shapes[shapes.size() - 8]->getLocation().y);		

		// For the first 110 frames:
		if (frameCount <= 110)
		{
			// Move the second ghost up
			shapes[shapes.size() - 9]->move(shapes[shapes.size() - 9]->getLocation().x, shapes[shapes.size() - 9]->getLocation().y + 1);
		}

		// At frame 80:
		if (frameCount == 80)
		{
			// Delete the first cookie
			deleteShape(26);
		}	
	}
	// For frames 120-310:
	if (frameCount >= 120 && frameCount <= 310)
	{
		// At frame 120:
		if (frameCount == 120)
		{
			// Make the first pacman invisible
			Shape2D* pacmanPtr = shapes[shapes.size() - 7];
			CompoundShape2D* pacman = dynamic_cast<CompoundShape2D*>(pacmanPtr);			
			pacman->getShape(0)->changeColor(COLOR_BLACK);

			// Make the second pacman visible
			Shape2D* pacmanPtrUp = shapes[shapes.size() - 6];
			CompoundShape2D* pacmanUp = dynamic_cast<CompoundShape2D*>(pacmanPtrUp);
			pacmanUp->move(0, 178);
			pacmanUp->getShape(0)->changeColor(COLOR_YELLOW);
		}

		// Move the second pacman up
		shapes[shapes.size() - 6]->move(shapes[shapes.size() - 6]->getLocation().x, shapes[shapes.size() - 6]->getLocation().y + 1);

		// Move the first ghost down
		shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x, shapes[shapes.size() - 8]->getLocation().y-1);
		
		// Move the second ghost right
		shapes[shapes.size() - 9]->move(shapes[shapes.size() - 9]->getLocation().x+1, shapes[shapes.size() - 9]->getLocation().y);
		
		// At frame 158:
		if (frameCount == 158)
		{
			// Delete the second cookie
			deleteShape(26);
		}

		// At frame 260:
		if (frameCount == 260)
		{
			// Delete the third cookie
			deleteShape(26);
		}
	}

	// For frames 310-520:
	if (frameCount >= 310 && frameCount <= 520)
	{
		// At frame 310:
		if (frameCount == 310)
		{
			// Make the second pacman invisible
			Shape2D* pacmanPtr = shapes[shapes.size() - 6];
			CompoundShape2D* pacman = dynamic_cast<CompoundShape2D*>(pacmanPtr);			
			pacman->getShape(0)->changeColor(COLOR_BLACK);

			// Make the third pacman visible
			Shape2D* pacmanPtrUp = shapes[shapes.size() - 5];
			CompoundShape2D* pacmanUp = dynamic_cast<CompoundShape2D*>(pacmanPtrUp);
			pacmanUp->move(0, 250);
			pacmanUp->getShape(0)->changeColor(COLOR_YELLOW);
		}

		// Move the third pacman right
		shapes[shapes.size() - 5]->move(shapes[shapes.size() - 5]->getLocation().x+1, shapes[shapes.size() - 5]->getLocation().y);

		// For frames 310-420:
		if (frameCount <= 420)
		{
			// Move the first ghost down
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x, shapes[shapes.size() - 8]->getLocation().y - 1);
		}

		// For frames 310-430:
		if (frameCount <= 430)
		{
			// Move the second ghost right
			shapes[shapes.size() - 9]->move(shapes[shapes.size() - 9]->getLocation().x + 1, shapes[shapes.size() - 9]->getLocation().y);
		}

		// For frames 420-520:
		if (frameCount >= 420 && frameCount <= 520)
		{
			// Move the first ghost left
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x - 1, shapes[shapes.size() - 8]->getLocation().y);
		}

		// For frames 430-520:
		if (frameCount >= 430 && frameCount <= 520)
		{
			// Move the second ghost down
			shapes[shapes.size() - 9]->move(shapes[shapes.size() - 9]->getLocation().x, shapes[shapes.size() - 9]->getLocation().y - 1);
		}

		// At frame 365:
		if (frameCount == 365)
		{
			// Delete the fourth cookie
			deleteShape(26);
		}

		// At frame 465:
		if (frameCount == 465)
		{
			// Delete the fifth cookie
			deleteShape(26);
		}
	}

	// For frames 520-930:
	if (frameCount >= 520 && frameCount <= 930)
	{
		// At frame 520:
		if (frameCount == 520)
		{
			// Make the third pacman invisible
			Shape2D* pacmanPtr = shapes[shapes.size() - 5];
			CompoundShape2D* pacman = dynamic_cast<CompoundShape2D*>(pacmanPtr);
			pacman->getShape(0)->changeColor(COLOR_BLACK);

			// Make the fourth pacman visible
			Shape2D* pacmanPtrUp = shapes[shapes.size() - 4];
			CompoundShape2D* pacmanUp = dynamic_cast<CompoundShape2D*>(pacmanPtrUp);
			pacmanUp->move(0, 250);
			pacmanUp->getShape(0)->changeColor(COLOR_YELLOW);
		}

		// Move the fourth pacman down
		shapes[shapes.size() - 4]->move(shapes[shapes.size() - 4]->getLocation().x, shapes[shapes.size() - 4]->getLocation().y - 1);

		// For frames 520-620:
		if (frameCount <= 620)
		{
			// Move the first ghost left
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x-1, shapes[shapes.size() - 8]->getLocation().y);
		}

		// For frames 520-840
		if (frameCount <= 840)
		{
			// Move the second ghost down
			shapes[shapes.size() - 9]->move(shapes[shapes.size() - 9]->getLocation().x, shapes[shapes.size() - 9]->getLocation().y - 1);
		}

		// For frames 620-720:
		if (frameCount >= 620 && frameCount <= 720)
		{
			// Move the first ghost up
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x, shapes[shapes.size() - 8]->getLocation().y+1);
		}

		// For frames 720-820:
		if (frameCount >= 720 && frameCount <= 820)
		{
			// Move the first ghost down
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x, shapes[shapes.size() - 8]->getLocation().y - 1);
		}

		// For frames 820-930:
		if (frameCount >= 820 && frameCount <= 930)
		{
			// Move the first ghost right
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x+1, shapes[shapes.size() - 8]->getLocation().y);
		}

		// For frames 840-930:
		if (frameCount >= 840 && frameCount <= 930)
		{
			// Move the second ghost left
			shapes[shapes.size() - 9]->move(shapes[shapes.size() - 9]->getLocation().x-1, shapes[shapes.size() - 9]->getLocation().y);
		}

		// At frame 575:
		if (frameCount == 575)
		{
			// Delete the sixth cookie
			deleteShape(26);
		}

		// At frame 675:
		if (frameCount == 675)
		{
			// Delete the seventh cookie
			deleteShape(26);			
		}
		
		// At frame 775:
		if (frameCount == 775)
		{
			// Delete the eighth cookie
			deleteShape(26);
		}

		// At frame 875:
		if (frameCount == 875)
		{
			// Delete the ninth cookie
			deleteShape(26);
		}
	}

	// For frames 930-1120:
	if (frameCount >= 930 && frameCount <= 1120)
	{
		// At frame 930:
		if (frameCount == 930)
		{
			// Turn the fourth pacman invisible
			Shape2D* pacmanPtr = shapes[shapes.size() - 4];
			CompoundShape2D* pacman = dynamic_cast<CompoundShape2D*>(pacmanPtr);
			pacman->getShape(0)->changeColor(COLOR_BLACK);

			// Turn the fifth pacman visible
			Shape2D* pacmanPtrUp = shapes[shapes.size() - 3];
			CompoundShape2D* pacmanUp = dynamic_cast<CompoundShape2D*>(pacmanPtrUp);
			pacmanUp->move(0, 50);
			pacmanUp->getShape(0)->changeColor(COLOR_YELLOW);
		}

		// Move the fifth pacman right
		shapes[shapes.size() - 3]->move(shapes[shapes.size() - 3]->getLocation().x + 1, shapes[shapes.size() - 3]->getLocation().y);

		// For frames 930-940:
		if (frameCount >= 930 && frameCount <= 940)
		{
			// Move the first ghost right
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x + 1, shapes[shapes.size() - 8]->getLocation().y);
		}

		// For frames 940-1060:
		if (frameCount >= 940 && frameCount <= 1060)
		{
			// Move the first ghost left
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x - 1, shapes[shapes.size() - 8]->getLocation().y);
		}

		// For frames 1060-1120:
		if (frameCount >= 1060 && frameCount <= 1120)
		{
			// Move the first ghost up
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x, shapes[shapes.size() - 8]->getLocation().y+1);
		}

		// For frames 930-940:
		if (frameCount >= 930 && frameCount <= 940)
		{
			// Move the second ghost left
			shapes[shapes.size() - 9]->move(shapes[shapes.size() - 9]->getLocation().x - 1, shapes[shapes.size() - 9]->getLocation().y);
		}

		// At frame 940:
		if (frameCount == 940)
		{
			// Delete the second ghost
			deleteShape(shapes.size() - 9);
		}

		// At frame 975:
		if (frameCount == 975)
		{
			// Delete the tenth cookie
			deleteShape(26);
		}

		// At frame 1065:
		if (frameCount == 1065)
		{
			// Delete the eleventh cookie
			deleteShape(26);
		}
	}	

	// For frames 675-940:
	if (frameCount >= 675 && frameCount < 940)
	{		
		// Convert the ghost 1 Shape2D to CompoundShape2D
		Shape2D* ghost1Ptr = shapes[shapes.size() - 9];
		CompoundShape2D* ghost1 = dynamic_cast<CompoundShape2D*>(ghost1Ptr);

		// Get the current RGB values of ghost 1
		Color* curColor1 = new Color(ghost1->getShape(0)->getColor().getRed(), ghost1->getShape(0)->getColor().getGreen(), ghost1->getShape(0)->getColor().getBlue());				

		// Gradually decrease the red and green values to 1 using the current frame count
		int red1 = curColor1->getRed();
		int green1 = curColor1->getGreen();
		if (curColor1->getRed() - (frameCount - 675) > 0)
		{
			red1 -= (frameCount - 675);
		}
		if (curColor1->getGreen() - (frameCount - 675) > 0)
		{
			green1 -= (frameCount - 675);
		}			
		int blue1 = curColor1->getBlue();

		// Create a new color using the new RG values and change one piece of the ghost 1 to that color
		Color* newColor1 = new Color(red1, green1, blue1);
		ghost1->getShape(0)->changeColor(*newColor1);	

		// Repeat for all pieces of the ghost except the eyes:

		Color* curColor2 = new Color(ghost1->getShape(2)->getColor().getRed(), ghost1->getShape(2)->getColor().getGreen(), ghost1->getShape(2)->getColor().getBlue());
		int red2 = curColor2->getRed();
		int green2 = curColor2->getGreen();
		if (curColor2->getRed() - (frameCount - 675) > 0)
		{
			red2 -= (frameCount - 675);
		}
		if (curColor2->getGreen() - (frameCount - 675) > 0)
		{
			green2 -= (frameCount - 675);
		}
		int blue2 = curColor2->getBlue();
		Color* newColor2 = new Color(red2, green2, blue2);
		ghost1->getShape(2)->changeColor(*newColor2);



		Color* curColor3 = new Color(ghost1->getShape(3)->getColor().getRed(), ghost1->getShape(3)->getColor().getGreen(), ghost1->getShape(3)->getColor().getBlue());
		int red3 = curColor3->getRed();
		int green3 = curColor3->getGreen();
		if (curColor3->getRed() - (frameCount - 675) > 0)
		{
			red3 -= (frameCount - 675);
		}
		if (curColor3->getGreen() - (frameCount - 675) > 0)
		{
			green3 -= (frameCount - 675);
		}
		int blue3 = curColor3->getBlue();
		Color* newColor3 = new Color(red3, green3, blue3);
		ghost1->getShape(3)->changeColor(*newColor3);


		Color* curColor4 = new Color(ghost1->getShape(4)->getColor().getRed(), ghost1->getShape(4)->getColor().getGreen(), ghost1->getShape(4)->getColor().getBlue());
		int red4 = curColor4->getRed();
		int green4 = curColor4->getGreen();
		if (curColor4->getRed() - (frameCount - 675) > 0)
		{
			red4 -= (frameCount - 675);
		}
		if (curColor4->getGreen() - (frameCount - 675) > 0)
		{
			green4 -= (frameCount - 675);
		}
		int blue4 = curColor4->getBlue();
		Color* newColor4 = new Color(red4, green4, blue4);
		ghost1->getShape(4)->changeColor(*newColor4);



		Color* curColor5 = new Color(ghost1->getShape(5)->getColor().getRed(), ghost1->getShape(5)->getColor().getGreen(), ghost1->getShape(5)->getColor().getBlue());
		int red5 = curColor5->getRed();
		int green5 = curColor5->getGreen();
		if (curColor5->getRed() - (frameCount - 675) > 0)
		{
			red5 -= (frameCount - 675);
		}
		if (curColor5->getGreen() - (frameCount - 675) > 0)
		{
			green5 -= (frameCount - 675);
		}
		int blue5 = curColor5->getBlue();
		Color* newColor5 = new Color(red5, green5, blue5);
		ghost1->getShape(5)->changeColor(*newColor5);

		// Change the ghost's pupils to white
		ghost1->getShape(8)->changeColor(COLOR_WHITE);
		ghost1->getShape(9)->changeColor(COLOR_WHITE);						
	}

	// For frame 675:
	if (frameCount == 675)
	{
		// Move both ghost's pupils up into their eyes so they appear to be invisible
		Shape2D* ghost1Ptr = shapes[shapes.size() - 9];
		CompoundShape2D* ghost1 = dynamic_cast<CompoundShape2D*>(ghost1Ptr);
		ghost1->getShape(8)->move(ghost1->getShape(8)->getLocation().x, ghost1->getShape(8)->getLocation().y + 5);
		ghost1->getShape(9)->move(ghost1->getShape(9)->getLocation().x, ghost1->getShape(9)->getLocation().y + 5);

		Shape2D* ghost2Ptr = shapes[shapes.size() - 8];
		CompoundShape2D* ghost2 = dynamic_cast<CompoundShape2D*>(ghost2Ptr);
		ghost2->getShape(8)->move(ghost2->getShape(8)->getLocation().x, ghost2->getShape(8)->getLocation().y + 5);
		ghost2->getShape(9)->move(ghost2->getShape(9)->getLocation().x, ghost2->getShape(9)->getLocation().y + 5);
	}

	// For all frames after 675:
	if (frameCount >= 675)
	{
		// Convert the ghost 2 Shape2D to CompoundShape2D
		Shape2D* ghost2Ptr = shapes[shapes.size() - 8];
		CompoundShape2D* ghost2 = dynamic_cast<CompoundShape2D*>(ghost2Ptr);				

		// Get the current RGB values of ghost 2
		Color* curColor1 = new Color(ghost2->getShape(0)->getColor().getRed(), ghost2->getShape(0)->getColor().getGreen(), ghost2->getShape(0)->getColor().getBlue());

		// Gradually decrease the red and green values to 1 using the current frame count
		int red1 = curColor1->getRed();
		int green1 = curColor1->getGreen();
		if (curColor1->getRed() - (frameCount - 675) > 0)
		{
			red1 -= (frameCount - 675);
		}
		if (curColor1->getGreen() - (frameCount - 675) > 0)
		{
			green1 -= (frameCount - 675);
		}
		int blue1 = curColor1->getBlue();

		// Create a new color using the new RG values and change one piece of the ghost 2 to that color
		Color* newColor1 = new Color(red1, green1, blue1);
		ghost2->getShape(0)->changeColor(*newColor1);

		// Repeat for all pieces of the ghost except the eyes:

		Color* curColor2 = new Color(ghost2->getShape(2)->getColor().getRed(), ghost2->getShape(2)->getColor().getGreen(), ghost2->getShape(2)->getColor().getBlue());
		int red2 = curColor2->getRed();
		int green2 = curColor2->getGreen();
		if (curColor2->getRed() - (frameCount - 675) > 0)
		{
			red2 -= (frameCount - 675);
		}
		if (curColor2->getGreen() - (frameCount - 675) > 0)
		{
			green2 -= (frameCount - 675);
		}
		int blue2 = curColor2->getBlue();
		Color* newColor2 = new Color(red2, green2, blue2);
		ghost2->getShape(2)->changeColor(*newColor2);



		Color* curColor3 = new Color(ghost2->getShape(3)->getColor().getRed(), ghost2->getShape(3)->getColor().getGreen(), ghost2->getShape(3)->getColor().getBlue());
		int red3 = curColor3->getRed();
		int green3 = curColor3->getGreen();
		if (curColor3->getRed() - (frameCount - 675) > 0)
		{
			red3 -= (frameCount - 675);
		}
		if (curColor3->getGreen() - (frameCount - 675) > 0)
		{
			green3 -= (frameCount - 675);
		}
		int blue3 = curColor3->getBlue();
		Color* newColor3 = new Color(red3, green3, blue3);
		ghost2->getShape(3)->changeColor(*newColor3);


		Color* curColor4 = new Color(ghost2->getShape(4)->getColor().getRed(), ghost2->getShape(4)->getColor().getGreen(), ghost2->getShape(4)->getColor().getBlue());
		int red4 = curColor4->getRed();
		int green4 = curColor4->getGreen();
		if (curColor4->getRed() - (frameCount - 675) > 0)
		{
			red4 -= (frameCount - 675);
		}
		if (curColor4->getGreen() - (frameCount - 675) > 0)
		{
			green4 -= (frameCount - 675);
		}
		int blue4 = curColor4->getBlue();
		Color* newColor4 = new Color(red4, green4, blue4);
		ghost2->getShape(4)->changeColor(*newColor4);



		Color* curColor5 = new Color(ghost2->getShape(5)->getColor().getRed(), ghost2->getShape(5)->getColor().getGreen(), ghost2->getShape(5)->getColor().getBlue());
		int red5 = curColor5->getRed();
		int green5 = curColor5->getGreen();
		if (curColor5->getRed() - (frameCount - 675) > 0)
		{
			red5 -= (frameCount - 675);
		}
		if (curColor5->getGreen() - (frameCount - 675) > 0)
		{
			green5 -= (frameCount - 675);
		}
		int blue5 = curColor5->getBlue();
		Color* newColor5 = new Color(red5, green5, blue5);
		ghost2->getShape(5)->changeColor(*newColor5);

		// Change the ghost's pupils to white
		ghost2->getShape(8)->changeColor(COLOR_WHITE);
		ghost2->getShape(9)->changeColor(COLOR_WHITE);					
	}

	// For frames 1130-1320:
	if (frameCount >= 1130 && frameCount <= 1320)
	{
		// At frame 1130:
		if (frameCount == 1130)
		{
			// Make the fifth pacman invisible
			Shape2D* pacmanPtr = shapes[shapes.size() - 3];
			CompoundShape2D* pacman = dynamic_cast<CompoundShape2D*>(pacmanPtr);
			pacman->getShape(0)->changeColor(COLOR_BLACK);

			// Make the sixth pacman visible
			Shape2D* pacmanPtrUp = shapes[shapes.size() - 2];
			CompoundShape2D* pacmanUp = dynamic_cast<CompoundShape2D*>(pacmanPtrUp);
			pacmanUp->move(20, 50);
			pacmanUp->getShape(0)->changeColor(COLOR_YELLOW);
		}

		// Move the sixth pacman up
		shapes[shapes.size() - 2]->move(shapes[shapes.size() - 2]->getLocation().x, shapes[shapes.size() - 2]->getLocation().y+1);

		// For frames 1130-1150:
		if (frameCount >= 1130 && frameCount <= 1150)
		{
			// Move the ghost up
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x, shapes[shapes.size() - 8]->getLocation().y + 1);
		}

		// For frames 1150-1230:
		if (frameCount >= 1150 && frameCount <= 1230)
		{
			// Move the ghost down
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x, shapes[shapes.size() - 8]->getLocation().y - 1);
		}

		// For frames 1230-1320:
		if (frameCount >= 1230 && frameCount <= 1320)
		{
			// Move the ghost right
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x + 1, shapes[shapes.size() - 8]->getLocation().y);
		}

		// At frame 1175:
		if (frameCount == 1175)
		{
			// Delete the twelfth cookie
			deleteShape(26);
		}

		// At frame 1275:
		if (frameCount == 1275)
		{
			// Delete the thirteenth cookie
			deleteShape(26);
		}
	}

	// For frames 1320-1510:
	if (frameCount >= 1320 && frameCount <= 1510)
	{
		// At frame 1320:
		if (frameCount == 1320)
		{
			// Make the sixth pacman invisible
			Shape2D* pacmanPtr = shapes[shapes.size() - 2];
			CompoundShape2D* pacman = dynamic_cast<CompoundShape2D*>(pacmanPtr);
			pacman->getShape(0)->changeColor(COLOR_BLACK);

			// Make the seventh pacman visible
			Shape2D* pacmanPtrUp = shapes[shapes.size() - 1];
			CompoundShape2D* pacmanUp = dynamic_cast<CompoundShape2D*>(pacmanPtrUp);
			pacmanUp->move(-75, 0);
			pacmanUp->getShape(0)->changeColor(COLOR_YELLOW);
		}

		// Move the seventh pacman right
		shapes[shapes.size() - 1]->move(shapes[shapes.size() - 1]->getLocation().x + 1, shapes[shapes.size() - 1]->getLocation().y);

		// For frames 1320-1330:
		if (frameCount >= 1320 && frameCount <= 1330)
		{
			// Move the ghost right
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x + 1, shapes[shapes.size() - 8]->getLocation().y);
		}

		// For frames 1320-1510
		if (frameCount <= 1510)
		{
			// Move the ghost up
			shapes[shapes.size() - 8]->move(shapes[shapes.size() - 8]->getLocation().x, shapes[shapes.size() - 8]->getLocation().y + 1);								
		}
	}
}