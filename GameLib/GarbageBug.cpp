/**
 * @file GarbageBug.cpp
 * @author sriram
 */

#include "pch.h"
#include "GarbageBug.h"
#include "Game.h"
#include "Scoreboard.h"


/// Number of sprite images
const int GarbageBugNumSpriteImages = 6;

/// The range of the program to consider at it
const double ProgramRange = 50;

/**
 * GarbageBug Constructor
 * @param game Game this bug is a member of
 * @param program he program the bug is associated with
 * @param bug The inform associated with the bug
 */
GarbageBug::GarbageBug(Game *game,std::shared_ptr<Item> program,wxXmlNode* bug) : Bug(game,program,bug)
{

	mBitmaps = game->GetItemBitmaps("garbage");
}

/**
 * Draws the GarbageBug or splat GarbageBug
 * @param gc Device context to draw on
 * @param timeInSec How long the game has been running for
 */
void GarbageBug::Draw(std::shared_ptr<wxGraphicsContext> gc, double timeInSec)
{

	if (!GetSplat())
	{
		this->UpdateFrame(timeInSec);

		for (const auto& bitmapPair : mBitmaps)
		{
			if (bitmapPair.first == "SpriteSheet")
			{
				auto spriteSheet = bitmapPair.second->ConvertToImage();
				double wid = spriteSheet.GetWidth();
				double hit = spriteSheet.GetHeight()/GarbageBugNumSpriteImages;
				auto currentBitmap = gc->CreateSubBitmap(gc->CreateBitmapFromImage(spriteSheet),
														 0,mCurrentFrameIndex*hit,wid,hit);

				gc->PushState();
				// Translate to the center of the image
				gc->Translate(GetX(), GetY());

				// Rotate the image by the specified angle
				gc->Rotate(this->GetAngleToRotate());

				double multiplierImage = this->IsFatbug() ? 1.25 : 1.0;
				wid,hit = wid*multiplierImage,hit*multiplierImage;
				gc->DrawBitmap(currentBitmap,
							   - wid / 2, (- hit / 2), wid, hit);
				gc->PopState();
			}
		}
	}
	else
	{
		for (const auto& bitmapPair : mBitmaps)
		{
			if (bitmapPair.first == "Splat")
			{
				auto bugSplatBitmap = bitmapPair.second->ConvertToImage();
				double wid = bugSplatBitmap.GetWidth();
				double hit = bugSplatBitmap.GetHeight();
				gc->DrawBitmap(bugSplatBitmap,
							   int(GetX() - wid / 2),
							   int(GetY() - hit / 2), wid, hit);
				this->SetSpeed(0);
			}
			break;
		}
	}
}

/**
 * Updates the value of current frame index
 * @param timeInSec How long the game has been running for
 */
void GarbageBug::UpdateFrame(double timeInSec)
{
	if (GetTime() >= (3000/GetSpeed()) && timeInSec > this->GetStartTime())
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
        GetGame()->GetScoreboard()->IncFixed();
	}
}