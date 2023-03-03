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
//
//	wxGraphicsRenderer* renderer = wxGraphicsRenderer::GetDefaultRenderer();
//
//	wxImage image = mBugBitmap->ConvertToImage();
//	wxGraphicsBitmap spriteSheet = renderer->CreateBitmapFromImage(image);
//
//	// Extract each frame from the wxGraphicsBitmap object and store it in the array
//	double frameWidth = mBugBitmap->GetHeight() / GarbageBugNumSpriteImages;
//
//	for (int i = 0; i < GarbageBugNumSpriteImages; i++)
//	{
//		wxGraphicsBitmap frameBitmap = renderer->CreateSubBitmap(spriteSheet, 0,
//																 i * frameWidth, frameWidth, frameWidth);
//		mSpriteSheetFrames.push_back(frameBitmap);
//	}
	wxImage spriteSheet(GarbageBugSpriteImageName, wxBITMAP_TYPE_PNG);

	// Get the height of each image
	int imageHeight = spriteSheet.GetHeight() / GarbageBugNumSpriteImages;

	for (int i = 0; i < GarbageBugNumSpriteImages; i++)
	{
		auto image = spriteSheet.GetSubImage(wxRect(0, i * imageHeight, imageHeight, imageHeight));
		mSpriteSheetFrames.push_back(std::make_unique<wxBitmap>(image));
	}
}

void GarbageBug::Draw(wxDC *dc)
{
	if (!splat)
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
	mCurrentFrameIndex = (mCurrentFrameIndex + 1) % (GarbageBugNumSpriteImages-1);
}
