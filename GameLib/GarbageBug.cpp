/**
 * @file GarbageBug.cpp
 * @author srira
 */

#include "pch.h"
#include "GarbageBug.h"
#include "Game.h"
#include <functional>

/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;

/**
 * GarbageBug Constructor
 * @param game Game this bug is a member of
 */
GarbageBug::GarbageBug(Game *game) : Bug(game, GarbageBugSpriteImageName)
{
//	mTimer.Start(3/GetSpeed()); // 3 seconds
//	Connect(mTimer.GetId(), wxEVT_TIMER,wxTimerEventHandler(GarbageBug::OnTimer));
//
//
//	mBugBitmap = std::make_unique<wxBitmap>(GarbageBugSpriteImageName,wxBITMAP_TYPE_ANY);
//	mBugSplatBitmap = std::make_unique<wxBitmap>(GarbageBugSplatImageName,wxBITMAP_TYPE_ANY);
//
//	wxGraphicsRenderer* renderer = wxGraphicsRenderer::GetDefaultRenderer();
//
//	wxImage image = mBugBitmap->ConvertToImage();
//	wxGraphicsBitmap spriteSheet = renderer->CreateBitmapFromImage(image);
//
//	// Extract each frame from the wxGraphicsBitmap object and store it in the array
//	int frameWidth = mBugBitmap->GetWidth() / GarbageBugNumSpriteImages;
//
//	for (int i = 0; i < GarbageBugNumSpriteImages; i++)
//	{
//		wxGraphicsBitmap frameBitmap = renderer->CreateSubBitmap(spriteSheet, i * frameWidth,
//																 0, frameWidth, frameWidth);
//		mSpriteSheetFrames.push_back(frameBitmap);
//	}

}

void GarbageBug::Draw(wxDC *dc)
{
	if (!splat)
	{
		double wid = mBugBitmap->GetWidth();
		double hit = mBugBitmap->GetHeight();

		// Get the current frame to draw and update the index for the next frame
		wxGraphicsBitmap currentFrame = mSpriteSheetFrames[mCurrentFrameIndex];
		//mCurrentFrameIndex = (mCurrentFrameIndex + 1) % GarbageBugNumSpriteImages;


		// Draw the bug image using the device context
		dc->DrawBitmap(currentFrame.ConvertToImage(), int(GetX() - wid / 2),
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


void GarbageBug::OnTimer(wxTimerEvent& event)
{
//	// change the current frame to the next one
//	mCurrentFrameIndex = (mCurrentFrameIndex + 1) % GarbageBugNumSpriteImages;
//	// redraw the bug with the new frame
//	Refresh();
}

