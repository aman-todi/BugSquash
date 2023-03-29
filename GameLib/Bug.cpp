/**
 * @file Bug.cpp
 * @author sriram
 */

#include "pch.h"
#include "Bug.h"
#include <random>
#include "Game.h"
#include "Scoreboard.h"

/// How close the user has click
/// For the bug to splat
const double HitRadius = 50;

/// The range of the program to consider at it
const double ProgramRange = 5;

/**
 * Constructor
 * @param game The game we are in
 * @param program The bug is associated with
 * @param bug The bugs information
 */
Bug::Bug(Game *game,std::shared_ptr<Item> program,wxXmlNode* bug) :
        Item(game)
{
    if (program != nullptr)
    {
		double bugX,bugY;
		mProgram = program;
		bool xConvert = bug->GetAttribute("x").ToDouble(&bugX);
		bool yConvert = bug->GetAttribute("y").ToDouble(&bugY);
		bool speedConvert = bug->GetAttribute("speed").ToDouble(&mSpeed);
		bool timeConvert = bug->GetAttribute("start").ToDouble(&mStartTime);

		SetLocation(bugX, bugY);

        //load the "code" if fat bug
        if (bug->GetChildren()!=nullptr) {
            mFatbug = true;
            auto code = bug->GetChildren();

            auto solData = code->GetAttribute("pass");
            auto cDataNode = code->GetChildren();
            if (cDataNode->GetType()==wxXML_CDATA_SECTION_NODE) {
                auto cData = cDataNode->GetContent();
                mCodeData = cData.ToStdWstring();
                mSolution = solData.ToStdWstring();
            }
        }
    }
    else
    {
        SetLocation(0, 0);
    }
}

/**
 * Handle updates in time of our bug
 *
 * This is called before we draw and allows us to
 * move our bug. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 * @param timeInSec How long the level been running for
 */
void Bug::Update(double elapsed, double timeInSec)
{
	if(timeInSec > GetStartTime())
	{
		mAngleToRotate = atan2(GetProgramY() - GetY(), GetProgramX() - GetX());
		double newX = GetX() + elapsed * mSpeed * cos(mAngleToRotate);
		double newY = GetY() + elapsed * mSpeed * sin(mAngleToRotate);
		SetLocation(newX, newY);
	}
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


/**
 * Check to see if the bug reached the program
 * @return True if the bug has reached the program, else false
 */
bool Bug::AtProgram()
{
    double distanceX = this->GetX() - GetProgramX();
    double distanceY = this->GetY() - GetProgramY();
    return sqrt(distanceX * distanceX + distanceY * distanceY) <= ProgramRange;
}



