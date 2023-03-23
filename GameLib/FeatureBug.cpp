/**
 * @file FeatureBug.cpp
 * @author sriram
 */

#include "pch.h"
#include "FeatureBug.h"
#include "Game.h"
#include "Scoreboard.h"

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
 * @param program The program the bug is associated with
 * @param bug The inform associated with the bug
 */
FeatureBug::FeatureBug(Game *game,wxXmlNode* program,wxXmlNode* bug) : Bug(game, program, bug,FeatureImageName)
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
 * @param gc The graphic context to draw on
 */
void FeatureBug::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
	if (!GetSplat())
	{
		this->UpdateFrame();

		auto currentBugImage = mSpriteSheetFrames[mCurrentFrameIndex];
		 //Create a graphics context
		//auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));
		auto currentBugBitmap = gc->CreateBitmapFromImage(*currentBugImage);

		double multiplierImage = this->IsFatbug() ? 1.25 : 1.0;

		double wid = currentBugImage->GetWidth()*multiplierImage;
		double hit = currentBugImage->GetHeight()*multiplierImage;

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

void FeatureBug::ClickedOn()
{
    SetSplat();
    auto scoreboard = GetGame()->GetScoreboard();
    scoreboard->IncOops();
}

void FeatureBug::MissProgram()
{

}
