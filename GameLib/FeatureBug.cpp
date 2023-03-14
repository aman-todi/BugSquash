/**
 * @file FeatureBug.cpp
 * @author sriram
 */

#include "pch.h"
#include "FeatureBug.h"
#include "Game.h"

/// The feature sprite image
const std::wstring FeatureImageName = L"images/feature.png";

/// The splat image
const std::wstring FeatureSplatImageName = L"images/feature-splat.png";

/// Number of sprite images
const int FeatureNumSpriteImages = 7;

/**
 * FeatureBug Constructor
 * @param game Game this bug is a member of
 */
FeatureBug::FeatureBug(Game *game) : Bug(game, FeatureImageName)
{
	mBugBitmap = std::make_unique<wxBitmap>(FeatureImageName,wxBITMAP_TYPE_ANY);
	mBugSplatBitmap = std::make_unique<wxBitmap>(FeatureSplatImageName,wxBITMAP_TYPE_ANY);
	wxImage spriteSheet(FeatureImageName, wxBITMAP_TYPE_ANY);

	// Get the height of each image
	double imageHeight = spriteSheet.GetHeight() / FeatureNumSpriteImages;

	for (int i = 0; i < FeatureNumSpriteImages; i++)
	{
		auto image = spriteSheet.GetSubImage(wxRect(0, i * imageHeight, imageHeight, imageHeight));
		mSpriteSheetFrames.push_back(std::make_unique<wxBitmap>(image));
	}
	// Put the standing sprite at index 0
	std::reverse(mSpriteSheetFrames.begin(),mSpriteSheetFrames.end());
}

/**
 * Draws the bug if it is either splat or moving
 * @param dc The device context to draw on
 */
void FeatureBug::Draw(wxDC *dc)
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
void FeatureBug::UpdateFrame()
{
	mCurrentFrameIndex = (mCurrentFrameIndex + 1) % (FeatureNumSpriteImages - 1);
	/// changed 'FeatureBugNumSpriteImages - 1' to 'FeatureBugNumSpriteImages' so it gets to all 6 images - aman

}


