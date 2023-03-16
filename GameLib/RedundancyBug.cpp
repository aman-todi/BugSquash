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
    wxImage spriteSheet(RedundancyBugImage, wxBITMAP_TYPE_ANY);

    // Get the height of each image
    double imageHeight = spriteSheet.GetHeight() / RedundancyNumSpriteImages;

    for (int i = 0; i < RedundancyNumSpriteImages; i++)
    {
        auto image = spriteSheet.GetSubImage(wxRect(0, i * imageHeight, imageHeight, imageHeight));
        mSpriteSheetFrames.push_back(std::make_shared<wxImage>(image));
    }
    // Put the standing sprite at index 0
    std::reverse(mSpriteSheetFrames.begin(),mSpriteSheetFrames.end());
}

/**
 * Draws the bug if it is either splat or moving
 * @param dc The device context to draw on
 */
void RedundancyBug::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
	if (!mSplat)
	{
		auto currentBugImage = mSpriteSheetFrames[mCurrentFrameIndex];
		//Create a graphics context
		//auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));
		auto currentBugBitmap = gc->CreateBitmapFromImage(*currentBugImage);

		double wid = currentBugImage->GetWidth();
		double hit = currentBugImage->GetHeight();

		gc->PushState();
		// Translate to the center of the image
		gc->Translate(GetX(), GetY());

		// Rotate the image by the specified angle
		gc->Rotate(this->GetAngleToRotate());

		gc->DrawBitmap(currentBugBitmap,
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
	}
}

/**
 * Updates the value of current frame index
 */
void RedundancyBug::UpdateFrame()
{
    mCurrentFrameIndex = (mCurrentFrameIndex + 1) % (RedundancyNumSpriteImages - 1);

}

