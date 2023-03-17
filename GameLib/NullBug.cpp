/**
 * @file NullBug.cpp
 * @author srira
 */

#include "pch.h"
#include "NullBug.h"
#include "Game.h"

/// The bug sprite image
const std::wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";

/// The splat image
const std::wstring NullBugSplatImageName = L"images/scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 7;

/**
 * NullBug Constructor
 * @param game Game this bug is a member of
 */
NullBug::NullBug(Game *game) : Bug(game, NullBugSpriteImageName)
{

	mBugSplatBitmap = std::make_unique<wxBitmap>(NullBugSplatImageName,wxBITMAP_TYPE_ANY);
	wxImage spriteSheet(NullBugSpriteImageName, wxBITMAP_TYPE_ANY);

	// Get the height of each image
	double imageHeight = spriteSheet.GetHeight() / NullBugNumSpriteImages;

	for (int i = 0; i < NullBugNumSpriteImages; i++)
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
void NullBug::Draw(std::shared_ptr<wxGraphicsContext> gc)
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
					   int(GetY() - hit / 2), wid, hit);

		this->SetSpeed(0);
	}
}
/**
 * Updates the value of current frame index
 */
void NullBug::UpdateFrame()
{
	mCurrentFrameIndex = (mCurrentFrameIndex + 1) % (NullBugNumSpriteImages - 1);
}

