/**
 * @file RedundancyBug.cpp
 * @author srira
 */

#include "pch.h"
#include "RedundancyBug.h"
#include "Game.h"
#include "Scoreboard.h"

/// The bug base image
const std::wstring RedundancyBugImage = L"images/redundancy-fly-base.png";

/// The bug top image
const std::wstring RedundancyFlyTopImageName = L"images/redundancy-fly-top.png";

/// The left wing image
const std::wstring RedundancyFlyLeftWingImageName = L"images/redundancy-fly-lwing.png";

/// The right wing image
const std::wstring RedundancyFlyRightWingImageName = L"images/redundancy-fly-rwing.png";

/// The splat image
const std::wstring RedundancyFlySplatImageName = L"images/redundancy-fly-splat.png";

/// Wing flapping period in seconds
const double WingPeriod = 0.2;

/// Starting mRotation angle for wings in radians
const double WingRotateStart = 0.0;

/// End mRotation angle for wings in radians
const double WingRotateEnd = 1.5;

/// How many sets of wings does this bug have?
const int NumberOfSetsOfWings = 4;

/// Number of virtual pixels between each of the wing sets
const int WingSetXOffset = 12;

/// X position relative to center of bug for the first (back) wing set
const int FirstWingSetX = -36;

/// Y position relative to center of bug for the right wings. The negative
/// of this is the Y position for the left wings.
const int WingSetY = 5;


/// The range of the program to consider at it
const double ProgramRange = 50;

/**
 * RedundancyBug Constructor
 * @param game Game this bug is a member of
 */
RedundancyBug::RedundancyBug(Game *game,wxXmlNode* program,wxXmlNode* bug) : Bug(game, program, bug,RedundancyBugImage)
{
    mBugSplatBitmap = std::make_unique<wxBitmap>(RedundancyFlySplatImageName,wxBITMAP_TYPE_ANY);
    wxImage FlyImageBase(RedundancyBugImage, wxBITMAP_TYPE_ANY);
    wxImage FlyImageTop(RedundancyFlyTopImageName, wxBITMAP_TYPE_ANY);
    wxImage FlyImageWingL(RedundancyFlyLeftWingImageName, wxBITMAP_TYPE_ANY);
    wxImage FlyImageWingR(RedundancyFlyRightWingImageName, wxBITMAP_TYPE_ANY);


    mBugPartsSpriteSheet.push_back(std::make_shared<wxImage>(FlyImageBase));
    mBugPartsSpriteSheet.push_back(std::make_shared<wxImage>(FlyImageTop));
    mBugPartsSpriteSheet.push_back(std::make_shared<wxImage>(FlyImageWingL));
    mBugPartsSpriteSheet.push_back(std::make_shared<wxImage>(FlyImageWingR));
}

/**
 * Draws the bug if it is either splat or moving
 * @param gc The device context to draw on
 */
void RedundancyBug::Draw(std::shared_ptr<wxGraphicsContext> gc, double timeInSec)
{

	if (!GetSplat())
	{
		auto BugBase = mBugPartsSpriteSheet[mCurrentFrameIndex];
        auto BugTop = mBugPartsSpriteSheet[mCurrentFrameIndex+1];
        auto BugWingL = mBugPartsSpriteSheet[mCurrentFrameIndex+2];
        auto BugWingR = mBugPartsSpriteSheet[mCurrentFrameIndex+3];

		//Create a graphics context
		//auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));
		auto BugBaseBitmap = gc->CreateBitmapFromImage(*BugBase);
        auto BugTopBitmap = gc->CreateBitmapFromImage(*BugTop);
        auto BugWingLBitmap = gc->CreateBitmapFromImage(*BugWingL);
        auto BugWingRBitmap = gc->CreateBitmapFromImage(*BugWingR);

        double multplierImage = this->IsFatbug() ? 1.25 : 1.0;
		double wid = BugBase->GetWidth()*multplierImage;
		double hit = BugBase->GetHeight()*multplierImage;
        double widL = BugWingL->GetWidth()*multplierImage;
        double widR = BugWingR->GetWidth()*multplierImage;
        double hitL = BugWingL->GetHeight()*multplierImage;
        double hitR = BugWingR->GetHeight()*multplierImage;

		gc->PushState();
		// Translate to the center of the image
		gc->Translate(GetX(), GetY());

		// Rotate the image by the specified angle
		gc->Rotate(this->GetAngleToRotate());

        auto X = gc->GetTransform();

        // Draw Base
		gc->DrawBitmap(BugBaseBitmap,
					   - wid / 2, (- hit / 2), wid, hit);



        // Draw Wings
        this->UpdateFrame(gc);
        for(int i = 0; i < 4; i++)
        {
            gc->SetTransform(X);
            gc->Translate(-WingSetXOffset * i,0);
            gc->Rotate(mRotation);
            gc->DrawBitmap(BugWingLBitmap,
                    - widL / 2 , (- hitL / 2) - WingSetY, widL, hitL);

            gc->SetTransform(X);
            gc->Translate(-WingSetXOffset * i,0);
            gc->Rotate(-mRotation);
            gc->DrawBitmap(BugWingRBitmap,
                    - widR / 2 , (- hitL / 2) + WingSetY, widR, hitR);
        }

        gc->SetTransform(X);
        // Draw Top
        gc->DrawBitmap(BugTopBitmap,
                - wid / 2, (- hit / 2), wid, hit);

        gc->PopState();
        mOldSpeed = this->GetSpeed();
	}
    else
    {
        double wid = mBugSplatBitmap->GetWidth();
        double hit = mBugSplatBitmap->GetHeight();
        gc->DrawBitmap(*mBugSplatBitmap,
                int(GetX() - wid / 2),
                int(GetY() - hit / 2),wid,hit);
        this->SetSpeed(0);
	}
}

/**
 * Updates Rotation amount of Wings
 *  @param gc The images of bug
 */
void RedundancyBug::UpdateFrame(std::shared_ptr<wxGraphicsContext> gc)
{
	if (mRotation>WingRotateEnd) {
		mDecreasing = true;
	}
	else if (mRotation<WingRotateStart) {
		mDecreasing = false;
	}
	if (!mDecreasing) {
		mRotation += WingPeriod;
	}
	else {
		mRotation -= WingPeriod;
	}

}

//void RedundancyBug::OnTimer(wxTimerEvent &event)
//{
//
//}

void RedundancyBug::ClickedOn()
{
	if (!this->IsFatbug())
	{
		SetSplat();
	}
}
