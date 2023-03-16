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

/// How close the user has click
/// For the bug to splat
const double HitRadius = 50;

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
	//Need to do loction of program
	mAngleToRotate = atan2(500-GetY(),625-GetX());
	double speed = sqrt(mSpeedX*mSpeedX+mSpeedY*mSpeedY);
	double newX = GetX() + elapsed * speed * cos(mAngleToRotate);
	double newY = GetY() + elapsed * speed * sin(mAngleToRotate);
	SetLocation(newX,newY);

}

/**
 * Hit test x,y to see if they are clicking on this bug.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @return true if clicked on bug
 */
bool Bug::HitTest(int x, int y)
{
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < HitRadius;
}