/**
 * @file Bug.cpp
 * @author srira
 */

#include "pch.h"
#include "Bug.h"
#include <random>
#include "Game.h"

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 20;

/**
 * Constructor
 * @param game The game we are in
 * @param filename Filename for the image we use
 */
Bug::Bug(Game *game, const std::wstring &filename) :
        Item(game, filename)
{
    std::uniform_real_distribution<> distribution(MinSpeedX, MaxSpeedX);
    mSpeedX = distribution(game->GetRandom());
    mSpeedY = 0;
}

/**
 * Handle updates in time of our bug
 *
 * This is called before we draw and allows us to
 * move our bug. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void Bug::Update(double elapsed)
{
	//Need to do location of program
	auto angle = atan2(500-GetY(),625-GetX());
	double speed = sqrt(mSpeedX*mSpeedX+mSpeedY*mSpeedY);
	double newX = GetX() + elapsed * speed * cos(angle);
	double newY = GetY() + elapsed * speed * sin(angle);
	SetLocation(newX,newY);

}

/**
 * Test to see if we hit this bug with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Bug::HitTest(int x, int y)
{
	double wid = this->GetWidth();
	// this is calling something that is 600 pixel tall which makes the hit test
	// Much wider than needed
	double hit = this->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image
	// Subtracting the center makes x, y relative to the image center
	// Adding half the size makes x, y relative to the image top corner
	double testX = x - GetX() + wid / 2;
	double testY = y - GetY() + hit / 2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}

	// Test to see if x, y are in the drawn part of the image
	// If the location is transparent, we are not in the drawn
	// part of the image
	return !CheckTransparency(testX, testY);
}

///**
// * Hit test x,y to see if they are clicking on this bug.
// * @param x X location in pixels
// * @param y Y location in pixels
// * @return true if clicked on bug
// */
//bool Bug::HitTest(int x, int y)
//{
//	double dx = x - GetX();
//	double dy = y - GetY();
//
//	return sqrt(dx * dx + dy * dy) < 50;
//}