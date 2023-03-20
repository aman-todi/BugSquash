/**
 * @file RedundancyBug.cpp
 * @author srira
 */

#include "pch.h"
#include "RedundancyBug.h"
#include "Game.h"


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

/// Starting rotation angle for wings in radians
const double WingRotateStart = 0.0;

/// End rotation angle for wings in radians
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

/// Number of sprite images
const int RedundancyNumSpriteImages = 1;

/**
 * RedundancyBug Constructor
 * @param game Game this bug is a member of
 */
RedundancyBug::RedundancyBug(Game *game) : Bug(game, RedundancyBugImage)
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
void RedundancyBug::Draw(std::shared_ptr<wxGraphicsContext> gc)
{

	if (!mSplat)
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

		double wid = BugBase->GetWidth();
		double hit = BugBase->GetHeight();
        double widL = BugWingL->GetWidth();
        double widR = BugWingR->GetWidth();
        double hitL = BugWingL->GetHeight();
        double hitR = BugWingR->GetHeight();

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
        for(int i = 0; i < 4; i++)
        {
            this->UpdateFrame(gc, true);
            gc->DrawBitmap(BugWingLBitmap,
                    - widL / 2 + FirstWingSetX + WingSetXOffset * i, (- hitL / 2) - WingSetY, widL, hitL);
            gc->SetTransform(X);

            this->UpdateFrame(gc, false);
            gc->DrawBitmap(BugWingRBitmap,
                    - wid / 2 + FirstWingSetX + WingSetXOffset * i, (- hit / 2) + WingSetY, widR, hitR);
            gc->SetTransform(X);
        }

        // Draw Top
        gc->DrawBitmap(BugTopBitmap,
                - wid / 2, (- hit / 2), wid, hit);

        gc->PopState();
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
 * Updates Rotation of Wings
 */
void RedundancyBug::UpdateFrame(std::shared_ptr<wxGraphicsContext> gc, bool isLeft)
{
	if (rotation>1.5) {
		decreasing = true;
	}
	else if (rotation<0) {
		decreasing = false;
	}
	if (!decreasing) {
		rotation += 0.02;
	}
	else {
		rotation -= 0.02;
	}


    if (isLeft)
    {
        gc->Rotate(rotation);
    }
    else
    {
        gc->Rotate(-rotation);
    }
}

void RedundancyBug::OnTimer(wxTimerEvent &event)
{

}

void RedundancyBug::ClickedOn()
{
	if (!this->IsFatbug())
	{
		mSplat=true;
	}
}


