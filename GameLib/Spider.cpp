/**
 * @file Spider.cpp
 * @author Aman Todi
 */

#include "pch.h"
#include "Spider.h"
#include "Game.h"

/// The Spider image
const std::wstring SpiderImageName = L"images/spider.png";

/**
 * Spider Constructor
 * @param game Game this bug is a member of
 */
Spider::Spider(Game *game,wxXmlNode* program,wxXmlNode* bug) : Bug(game,program,bug,SpiderImageName) {}

/**
 * Draws the spider for level 3
 * @param gc The device context to draw on
 */
void Spider::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
}
