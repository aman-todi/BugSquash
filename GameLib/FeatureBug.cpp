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

/// The range of the program to consider at it
const double ProgramRange = 50;

/**
 * FeatureBug Constructor
 * @param game Game this bug is a member of
 */
FeatureBug::FeatureBug(Game *game) : Bug(game, FeatureImageName)
{

	mBugSplatBitmap = std::make_unique<wxBitmap>(FeatureSplatImageName,wxBITMAP_TYPE_ANY);
	wxImage spriteSheet(FeatureImageName, wxBITMAP_TYPE_ANY);

	// Get the height of each image
	double imageHeight = spriteSheet.GetHeight() / FeatureNumSpriteImages;

	for (int i = 0; i < FeatureNumSpriteImages; i++)
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
void FeatureBug::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
	if (!mSplat)
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
					   int(GetY() - hit / 2), wid, hit);
		this->SetSpeed(0);
	}
}

/**
 * Updates the value of current frame index
 */
void FeatureBug::UpdateFrame()
{
	if (GetTime() >= (3000/GetSpeed()))
	{
		mCurrentFrameIndex = (mCurrentFrameIndex + 1) % (FeatureNumSpriteImages - 1);
		ResetTime();
	}
}

/**
 * See if the bug is at the program
 */
bool FeatureBug::AtProgram()
{
	double distanceX = this->GetX() - GetProgramX();
	double distanceY = this->GetY() - GetProgramY();
	return sqrt(distanceX * distanceX + distanceY * distanceY) <= ProgramRange;
}
