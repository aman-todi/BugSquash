/**
 * @file GarbageBug.cpp
 * @author sriram
 */

#include "pch.h"
#include "GarbageBug.h"
#include "Game.h"

/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 6;

/// The range of the program to consider at it
const double ProgramRange = 50;
/**
 * GarbageBug Constructor
 * @param game Game this bug is a member of
 */
GarbageBug::GarbageBug(Game *game) : Bug(game, GarbageBugSpriteImageName)
{

	mBugSplatBitmap = std::make_shared<wxBitmap>(GarbageBugSplatImageName,wxBITMAP_TYPE_ANY);
	wxImage spriteSheet(GarbageBugSpriteImageName, wxBITMAP_TYPE_ANY);

	// Get the height of each image
	double imageHeight = spriteSheet.GetHeight() / GarbageBugNumSpriteImages;

	for (int i = 0; i < GarbageBugNumSpriteImages; i++)
	{
		auto image = spriteSheet.GetSubImage(wxRect(0, i * imageHeight, imageHeight, imageHeight));
		mSpriteSheetFrames.push_back(std::make_shared<wxImage>(image));
	}
	// Put the standing sprite at index 0
	std::reverse(mSpriteSheetFrames.begin(),mSpriteSheetFrames.end());
}

/**
 * Draws the GarbageBug or splat GarbageBug
 * @param gc Device context to draw on
 */
void GarbageBug::Draw(std::shared_ptr<wxGraphicsContext> gc)
{

	if (!GetSplat())
	{
		this->UpdateFrame();

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
		this->SetSpeed(0);
	}
}

/**
 * Updates the value of current frame index
 */
void GarbageBug::UpdateFrame()
{
	if (GetTime() >= (3000/GetSpeed()))
	{
		mCurrentFrameIndex = (mCurrentFrameIndex + 1) % (GarbageBugNumSpriteImages - 1);
		ResetTime();
	}
}

/**
 * Set the bug to splat
 */
void GarbageBug::ClickedOn()
{
	if (!this->IsFatbug())
	{
		SetSplat();
	}
}