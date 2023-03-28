/**
 * @file Virus.cpp
 * @author Aman Todi
 */

#include "pch.h"
#include "Virus.h"
#include "Scoreboard.h"

/// The Virus image
const std::wstring VirusImageName = L"images/virus.png";

/// Number of sprite images
const int VirusNumSpriteImages = 7;

/**
 * Virus Constructor
 * @param game Game this bug is a member of
 * @param program he program the bug is associated with
 * @param bug The inform associated with the bug
 */
Virus::Virus(Game *game, std::shared_ptr<Item> program, wxXmlNode* bug) : Bug(game, program, bug) {

	mBitmaps = game->GetItemBitmaps("virus");
	mSpeedX = GetSpeed();
}

/**
 * Draws the virus for level 3
 * @param gc The device context to draw on
 * @param timeInSec How long the game has been running for
 */
void Virus::Draw(std::shared_ptr<wxGraphicsContext> gc, double timeInSec)
{
	this->UpdateFrame(timeInSec);

	for (const auto& bitmapPair : mBitmaps)
	{
		if (bitmapPair.first == "SpriteSheet")
		{
			auto spriteSheet = bitmapPair.second->ConvertToImage();
			double wid = spriteSheet.GetWidth();
			double hit = spriteSheet.GetHeight()/VirusNumSpriteImages;
			auto currentBitmap = gc->CreateSubBitmap(gc->CreateBitmapFromImage(spriteSheet),
													 0,mCurrentFrameIndex*hit,wid,hit);

			gc->PushState();
			// Translate to the center of the image
			gc->Translate(GetX(), GetY());

			// Rotate the image by the specified angle
			gc->Rotate(this->GetAngleToRotate());

			gc->DrawBitmap(currentBitmap,
						   - wid / 2, (- hit / 2), wid, hit);
			gc->PopState();
		}
	}

}

/**
 * Update the Virus bug (override Update from Bug.cpp)
 * @param elapsed time elapsed since last class call
 * @param timeInSec time since the level began
 */
void Virus::Update(double elapsed, double timeInSec)
{
	if(timeInSec > GetStartTime())
	{
		SetLocation(GetX() + mSpeedX * elapsed,
					GetY() + mSpeedY * elapsed);

		/// Make Virus Perimeter the Program

		/// While moving in X direction
		if (mSpeedX > 0 && GetX() >= 900)
		{
			mSpeedX = 0;
			mSpeedY = GetSpeed();
			SetAngleToRotate(1.5708);
		}
		else if (mSpeedX < 0 && GetX() <= 350)
		{
			mSpeedX = 0;
			mSpeedY = -GetSpeed();
			SetAngleToRotate(4.7124);
		}

		/// While moving in Y direction
		if (mSpeedY > 0 && GetY() >= 715)
		{
			mSpeedX = -GetSpeed();
			mSpeedY = 0;
			SetAngleToRotate(3.1416);
		}
		else if (mSpeedY < 0 && GetY() <= 285)
		{
			mSpeedX = GetSpeed();
			mSpeedY = 0;
			SetAngleToRotate(0);
		}
	}
}

/**
 * Updates the value of current frame index
 * @param timeInSec How long the game has been running for
 */
void Virus::UpdateFrame(double timeInSec)
{
	if (GetTime() >= (3000/GetSpeed()) && timeInSec > this->GetStartTime())
	{
		mCurrentFrameIndex = (mCurrentFrameIndex + 1) % (VirusNumSpriteImages - 1);
		ResetTime();
	}
}
