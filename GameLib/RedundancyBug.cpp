/**
 * @file RedundancyBug.cpp
 * @author sriram
 */

#include "pch.h"
#include "RedundancyBug.h"
#include "Game.h"
#include "Scoreboard.h"



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

/// The range of the program to consider at it
const double ProgramRange = 50;
/**
 * RedundancyBug Constructor
 * @param game Game this bug is a member of
 * @param program The program the bug is associated with
 * @param bug The inform associated with the bug
 */
RedundancyBug::RedundancyBug(Game *game,std::shared_ptr<Item> program,wxXmlNode* bug) : Bug(game, program, bug)
{
	mBitmaps = game->GetItemBitmaps("redundancy");
}

/**
 * Draws the bug if it is either splat or moving
 * @param gc The device context to draw on
 * @param timeInSec How long the game has been running for
 */
void RedundancyBug::Draw(std::shared_ptr<wxGraphicsContext> gc, double timeInSec)
{
	std::shared_ptr<wxBitmap> BugBase,BugTop,BugWingL,BugWingR;

	if (!GetSplat())
	{
		for (const auto& bitmapPair : mBitmaps)
		{
			if(bitmapPair.first == "Base")
			{
				BugBase = bitmapPair.second;
			}
			if(bitmapPair.first == "Top")
			{
				BugTop = bitmapPair.second;
			}
			if(bitmapPair.first == "RightWing")
			{
				BugWingR = bitmapPair.second;
			}
			if(bitmapPair.first == "LeftWing")
			{
				BugWingL = bitmapPair.second;
			}
		}
		auto BugBaseBitmap = gc->CreateBitmapFromImage(BugBase->ConvertToImage());
		auto BugTopBitmap = gc->CreateBitmapFromImage(BugTop->ConvertToImage());
		auto BugWingLBitmap = gc->CreateBitmapFromImage(BugWingL->ConvertToImage());
		auto BugWingRBitmap = gc->CreateBitmapFromImage(BugWingR->ConvertToImage());

		double wid = BugBase->GetWidth();
		double hit = BugBase->GetHeight();
		double widL = BugWingL->GetWidth();
		double widR = BugWingR->GetWidth();
		double hitL = BugWingL->GetHeight();
		double hitR = BugWingR->GetHeight();

		gc->PushState();
		// Translate to the center of the image
		gc->Translate(GetX(), GetY());

		// Rotate the image by the specified angle
		gc->Rotate(this->GetAngleToRotate());

		auto X = gc->GetTransform();

		// Draw Base
		gc->DrawBitmap(BugBaseBitmap,
					   - wid / 2, (- hit / 2), wid, hit);


		// Draw Wings
		this->UpdateFrame(gc);
		for(int i = 0; i < 4; i++)
		{
			gc->SetTransform(X);
			gc->Translate(-WingSetXOffset * i,0);
			gc->Rotate(mRotation);
			gc->DrawBitmap(BugWingLBitmap,
						   - widL / 2 , (- hitL / 2) - WingSetY, widL, hitL);

			gc->SetTransform(X);
			gc->Translate(-WingSetXOffset * i,0);
			gc->Rotate(-mRotation);
			gc->DrawBitmap(BugWingRBitmap,
						   - widR / 2 , (- hitL / 2) + WingSetY, widR, hitR);
		}

		gc->SetTransform(X);
		// Draw Top
		gc->DrawBitmap(BugTopBitmap,
					   - wid / 2, (- hit / 2), wid, hit);

		gc->PopState();
		mOldSpeed = this->GetSpeed();
	}
	else
	{
		for(const auto &bitmapPair : mBitmaps)
		{
			if(bitmapPair.first == "Splat")
			{
				auto bugSplat = bitmapPair.second->ConvertToImage();
				double wid = bugSplat.GetWidth();
				double hit = bugSplat.GetHeight();
				gc->DrawBitmap(bugSplat,
							   int(GetX() - wid / 2),
							   int(GetY() - hit / 2), wid, hit);
				this->SetSpeed(0);
			}
			break;
		}
	}
}

/**
 * Updates Rotation amount of Wings
 *  @param gc The images of bug
 */
void RedundancyBug::UpdateFrame(std::shared_ptr<wxGraphicsContext> gc)
{
	if (mRotation>WingRotateEnd) {
		mDecreasing = true;
	}
	else if (mRotation<WingRotateStart) {
		mDecreasing = false;
	}
	if (!mDecreasing) {
		mRotation += WingPeriod;
	}
	else {
		mRotation -= WingPeriod;
	}

}

//void RedundancyBug::OnTimer(wxTimerEvent &event)
//{
//
//}

void RedundancyBug::ClickedOn()
{
	SetSplat();
}
