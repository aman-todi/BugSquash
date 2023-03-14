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
	mBugBitmap = std::make_unique<wxBitmap>(NullBugSpriteImageName,wxBITMAP_TYPE_ANY);
	mBugSplatBitmap = std::make_unique<wxBitmap>(NullBugSplatImageName,wxBITMAP_TYPE_ANY);
	wxImage spriteSheet(NullBugSpriteImageName, wxBITMAP_TYPE_ANY);

	// Get the height of each image
	double imageHeight = spriteSheet.GetHeight() / NullBugNumSpriteImages;

	for (int i = 0; i < NullBugNumSpriteImages; i++)
	{
		auto image = spriteSheet.GetSubImage(wxRect(0, i * imageHeight, imageHeight, imageHeight));
		mSpriteSheetFrames.push_back(std::make_unique<wxBitmap>(image));
	}
	// Put the standing sprite at index 0
	std::reverse(mSpriteSheetFrames.begin(),mSpriteSheetFrames.end());

}
///**
// * Sets Bug splat to True
// */
//void NullBug::ClickedOn()
//{
//	mSplat = true;
//}


/**
 * Draws the bug if it is either splat or moving
 * @param dc The device context to draw on
 */
void NullBug::Draw(wxDC *dc)
{
	if (!mSplat)
	{
		double wid = mBugBitmap->GetWidth();
		double hit = mBugBitmap->GetHeight();

		// Draw the bug image using the device context
		dc->DrawBitmap(*(mSpriteSheetFrames[mCurrentFrameIndex]), int(GetX() - wid / 2),
					   int(GetY() - hit / 2));
	}
	else
	{
		double wid = mBugSplatBitmap->GetWidth();
		double hit = mBugSplatBitmap->GetHeight();
		dc->DrawBitmap(*mBugSplatBitmap,
					   int(GetX() - wid / 2),
					   int(GetY() - hit / 2));
	}
}
/**
 * Updates the value of current frame index
 */
void NullBug::UpdateFrame()
{
	mCurrentFrameIndex = (mCurrentFrameIndex + 1) % (NullBugNumSpriteImages - 1);
}

