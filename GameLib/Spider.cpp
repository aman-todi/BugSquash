/**
 * @file Spider.cpp
 * @author Aman Todi
 */

#include "pch.h"
#include "Spider.h"
#include "Scoreboard.h"

/// The Spider image
const std::wstring SpiderImageName = L"images/spider.png";

/// Number of sprite images
const int SpiderNumSpriteImages = 7;

/**
 * Spider Constructor
 * @param game Game this bug is a member of
 * @param program he program the bug is associated with
 * @param bug The inform associated with the bug
 */
Spider::Spider(Game *game,std::shared_ptr<Item> program,wxXmlNode* bug) : Bug(game,program,bug) {

	mBitmaps = game->GetItemBitmaps("spider");
}

/**
 * Draws the spider for level 3
 * @param gc The device context to draw on
 * @param timeInSec How long the game has been running for
 */
void Spider::Draw(std::shared_ptr<wxGraphicsContext> gc, double timeInSec)
{

}

/**
 * Updates the value of current frame index
 * @param timeInSec How long the game has been running for
 */
void Spider::UpdateFrame(double timeInSec)
{
	if (GetTime() >= (3000/GetSpeed()) && timeInSec > this->GetStartTime())
	{
		mCurrentFrameIndex = (mCurrentFrameIndex + 1) % (SpiderNumSpriteImages - 1);
		ResetTime();
	}
}
