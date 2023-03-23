/**
 * @file Spider.cpp
 * @author Aman Todi
 */

#include "pch.h"
#include "Spider.h"
#include "Game.h"

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
Spider::Spider(Game *game,wxXmlNode* program,wxXmlNode* bug) : Bug(game,program,bug,SpiderImageName) {

	wxImage spriteSheet(SpiderImageName, wxBITMAP_TYPE_ANY);

	// Get the height of each image
	double imageHeight = spriteSheet.GetHeight() / SpiderNumSpriteImages;

	for (int i = 0; i < SpiderNumSpriteImages; i++)
	{
		auto image = spriteSheet.GetSubImage(wxRect(0, i * imageHeight, imageHeight, imageHeight));
		mSpriteSheetFrames.push_back(std::make_shared<wxImage>(image));
	}
	// Put the standing sprite at index 0
	std::reverse(mSpriteSheetFrames.begin(),mSpriteSheetFrames.end());
}

/**
 * Draws the spider for level 3
 * @param gc The device context to draw on
 *
 */
void Spider::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
}
