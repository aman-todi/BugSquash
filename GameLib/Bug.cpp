/**
 * @file Bug.cpp
 * @author srira
 */

#include "pch.h"
#include "Bug.h"
#include <random>
#include "Game.h"
#include "Scoreboard.h"

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 20;

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
 * @param filename Filename for the image we use
 */
Bug::Bug(Game *game,wxXmlNode* program,wxXmlNode* bug, const std::wstring &filename) :
        Item(game, filename)
{

	double bugX, bugY;
	bool xConvert = bug->GetAttribute("x").ToDouble(&bugX);
	bool yConvert = bug->GetAttribute("y").ToDouble(&bugY);
	bool speedConvert = bug->GetAttribute("speed").ToDouble(&mSpeed);
	bool timeConvert = bug->GetAttribute("start").ToDouble(&mStartTime);
	bool programXConvert = program->GetAttribute("x").ToDouble(&mProgramX);
	bool programYConvert = program->GetAttribute("y").ToDouble(&mProgramY);
	SetLocation(bugX,bugY);

	//load the "code" if fatbug
	if(bug->GetChildren()!=nullptr)
	{
		mFatbug = true;
		auto code = bug->GetChildren();

		auto solData = code->GetAttribute("pass");
		auto cDataNode = code->GetChildren();
		if (cDataNode->GetType()==wxXML_CDATA_SECTION_NODE)
		{
			auto cData = cDataNode->GetContent();
			mCodeData = cData.ToStdString();
			mSolution = solData.ToStdString();
		}
	}
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
	mAngleToRotate = atan2(mProgramY-GetY(),mProgramX-GetX());
	double newX = GetX() + elapsed * mSpeed * cos(mAngleToRotate);
	double newY = GetY() + elapsed * mSpeed * sin(mAngleToRotate);
	SetLocation(newX,newY);
    MissProgram();
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
/**
 * If the Bug has reached the program
 * increase the Miss score
 */
void Bug::MissProgram()
{
    if (AtProgram()) {
        auto scoreboard = GetGame()->GetScoreboard();
        scoreboard->IncMissed();
    }
}



