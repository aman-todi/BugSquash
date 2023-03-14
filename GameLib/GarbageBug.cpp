/**
 * @file GarbageBug.cpp
 * @author srira
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

/**
 * GarbageBug Constructor
 * @param game Game this bug is a member of
 */
GarbageBug::GarbageBug(Game *game) : Bug(game, GarbageBugSpriteImageName)
{

	mBugBitmap = std::make_unique<wxBitmap>(GarbageBugSpriteImageName,wxBITMAP_TYPE_ANY);
	mBugSplatBitmap = std::make_unique<wxBitmap>(GarbageBugSplatImageName,wxBITMAP_TYPE_ANY);
	wxImage spriteSheet(GarbageBugSpriteImageName, wxBITMAP_TYPE_ANY);

	// Get the height of each image
	double imageHeight = spriteSheet.GetHeight() / GarbageBugNumSpriteImages;

	for (int i = 0; i < GarbageBugNumSpriteImages; i++)
	{
		auto image = spriteSheet.GetSubImage(wxRect(0, i * imageHeight, imageHeight, imageHeight));
		mSpriteSheetFrames.push_back(std::make_unique<wxBitmap>(image));
	}
	// Put the standing sprite at index 0
	std::reverse(mSpriteSheetFrames.begin(),mSpriteSheetFrames.end());
}

/**
 * Draws the GarbageBug or splat GarbageBug
 * @param dc Device context to draw on
 */
void GarbageBug::Draw(wxDC *dc)
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
void GarbageBug::UpdateFrame()
{
	mCurrentFrameIndex = (mCurrentFrameIndex + 1) % (GarbageBugNumSpriteImages - 1);
}

void GarbageBug::ClickedOn()
{
	mSplat = true;
}
