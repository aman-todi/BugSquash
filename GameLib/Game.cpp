/**
 * @file Game.cpp
 * @author sriram
 * @author ethan
 */

#include "pch.h"

#include "Game.h"
#include <wx/xml/xml.h>
#include <wx/graphics.h>
#include <algorithm>
#include <sstream>
#include "Bug.h"
#include "GarbageBug.h"
#include "NullBug.h"
#include "RedundancyBug.h"
#include "FeatureBug.h"
#include "Program.h"
#include "Scoreboard.h"
#include "LevelLoader.h"

using namespace std;

/// Game area in virtual pixels
const static double GameWidth = 1250;

/// Game area height in virtual pixels
const static double GameHeight = 1000;

/// Shrink Scaler
const static double ShrinkScale = .75;

/// Program image filename
const std::wstring ProgramImage = L"images/laptop.png";

/// Program name font size
const int ProgramNameFontSize = 22;

/// Score font size to use
const int ScoreSize = 85;

/// Lable for score font size to use
const int LabelSize = 40;

/// The font color to use
const wxColour FontColor = wxColour(0, 200, 200);

/// Left score X location. The right score is
/// the width minus this value.
const int LeftScoreX = 150;

/// Score Y location
const int ScoreY = 20;

/// Score label Y location
const int ScoreLabelY = 100;


/// The level0 XML
const std::wstring LevelZeroXMLFileName = L"data/level0.xml";

/// The level1 XML
const std::wstring LevelOneXMLFileName = L"data/level1.xml";

/// The level2 XML
const std::wstring LevelTwoXMLFileName = L"data/level2.xml";

/// The level3 XML
const std::wstring LevelThreeXMLFileName = L"data/level3.xml";

/**
 * Draw the game
 * @param graphics The graphic of the screen
 * @param width The width of the screen
 * @param height The height of the scree
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics ,int width, int height)
{

    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(GameWidth);
    auto scaleY = double(height) / double(GameHeight);
    mScale = std::min(scaleX, scaleY);

    if(mShrinked)
    {
        mScale *= ShrinkScale;
    }

    mXOffset = (width - GameWidth * mScale) / 2;
    mYOffset = (height - GameHeight * mScale) / 2;

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    //
    // A rectangle for the virtual area we are drawing on
    //

    wxBrush rectBrush(*wxWHITE);
    graphics->SetBrush(rectBrush);
    graphics->SetPen(*wxWHITE_PEN);
    graphics->DrawRectangle(0, 0, GameWidth, GameHeight);

    //  Draw Scoreboard
    mScoreboard->Draw(graphics);

	//This isn't being hit since there is no bug in mItems yet
	for(auto bug : mItems)
	{
		bug->Draw(graphics);
	}

    graphics->PopState();
}

/**
 * Game Constructor
 */
Game::Game()
{
    mScoreboard = std::make_shared<Scoreboard>();
	wxInitAllImageHandlers();

	LevelLoader level1(this,LevelOneXMLFileName);

}




/**
 * Add an bug to the game
 * @param bug New bug to add
 */
void Game::Add(std::shared_ptr<Item> bug)
{
	//Use Bug visitor to get list of bugs
	//bug->SetLocation(X, Y);
	mItems.push_back(bug);
}


/**
 * Test an x,y click location to see if it clicked
 * on some bug in the game.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::HitTest(int x, int y)
{

	//Use Bug visitor to get list of bugs
	for(auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if((*i)->HitTest(x, y))
		{
			return *i;
		}
	}
	return nullptr;
}


/**
 * Clear the game data.
 * Deletes all known items in the game.
 */
void Game::Clear()
{
	// TO DO...
	mItems.clear();

}


/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{
	vector<shared_ptr<Item>> bugToRemove;
	for (auto bug : mItems)
	{
		// Check to see if the bugs are at the program
		if(bug->AtProgram())
		{
			bugToRemove.push_back(bug);
			//This could be where add the missed and stuff
		}
		// Calling update on a null pointer
		bug->Update(elapsed);
	}

	// this for loop is used to remove all the bugs at the program
	for(auto bug: bugToRemove)
	{
		DeleteBug(bug);
	}
	// Destroy the vector
	bugToRemove.clear();
}

/**  Delete an bug from the game
*
* @param bug The item to delete.
*/
void Game::DeleteBug(std::shared_ptr<Item> bug)
{
	auto loc = find(std::begin(mItems), std::end(mItems), bug);
	if (loc != std::end(mItems))
	{
		mItems.erase(loc);
	}
}
/**
* Shrink The Game Window
*/
void Game::Shrink()
{
    mShrinked = !(mShrinked);
}

/**
 * Accept a visitor for the collection of items
 * @param visitor The visitor for the collection
 */
void Game::Accept(ItemsVisitor* visitor)
{
	for (auto item : mItems)
	{
		item->Accept(visitor);
	}
}

/**
 * Take the last touched Item and moves it to the end of the list
 * @param item Item an pointer to item in the aquarium
 */
void Game::UpdateList(std::shared_ptr<Item> item)
{
	//finds the location of item in the list
	auto loc = find(begin(mItems), end(mItems), item);
	//if item is not found then iterator will be at the end of the list so
	if (loc != end(mItems))
	{
		mItems.erase(loc);
	}
	//push the item back to the end of the list
	mItems.push_back(item);
}

/**
 * Update the animation timer in each bug (item)
 */
void Game::UpdateAnimationTime()
{
	for (auto item : mItems)
	{
		item->AddTime();
	}
}

 /**
  * Set the item to splat if single-clicked
  * @param x The X location which was clicked
  * @param y  The Y location which was clicked
  * @param doubleCLick checks if click is single or double
  * @return The Item that was clicked on
  */
std::shared_ptr<Item> Game::OnClick(double x, double y,bool doubleCLick)
{
	std::shared_ptr<Item> clicked = nullptr;

    double oX = (x - mXOffset) / mScale;
    double oY = (y - mYOffset) / mScale;

    clicked = this->HitTest(oX, oY);
	if (clicked != nullptr && !doubleCLick)
	{
		clicked->ClickedOn();
	}

	return clicked;
}
