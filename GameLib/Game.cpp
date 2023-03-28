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
#include "BugVisitor.h"
#include "NullBug.h"
#include "RedundancySplitBug.h"
#include "FeatureBug.h"
#include "Scoreboard.h"
#include "LevelLoader.h"
#include "BugScoreboardVisitor.h"
#include "VirusVisitor.h"
#include "Virus.h"
#include "FeatureVisitor.h"

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

/// Label for score font size to use
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
 * @param timeInSec How long the game has been running for int seconds
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics ,int width, int height,double timeInSec)
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

	for(auto bug : mItems)
	{
		bug->Draw(graphics, timeInSec);
	}

    //  Draw Scoreboard
    mScoreboard->Draw(graphics);

    graphics->PopState();
}

/**
 * Game Constructor
 */
Game::Game()
{
    mScoreboard = std::make_shared<Scoreboard>();

	LevelLoader level1(this,LevelOneXMLFileName);

}


/**
 * Add a bug to the game
 * @param bug New bug to add
 */
void Game::AddItem(std::shared_ptr<Item> bug)
{
	mItems.push_back(bug);
}

shared_ptr<Bug> Game::AddRed(std::shared_ptr<Item> bug, double randNum)
{
    double X = bug->GetX();
    double Y = bug->GetY();


    BugVisitor visitor;
    bug->Accept(&visitor);
    auto program = visitor.GetProgram();
    double speed = visitor.GetOldSpeed();


    shared_ptr <Bug> RedBug = make_shared<RedundancySplitBug>(this);

    RedBug->SetProgram(program);

    /// Fixing random distance (a^2 + b^2 = c^2 distance)
    if (randNum < 0)
    {
        randNum = -(sqrt((randNum * randNum) / 2));
    }
    else
    {
        randNum = sqrt((randNum * randNum) / 2);
    }

    RedBug->SetLocation(X+randNum,Y+randNum);
    RedBug->SetSpeed(speed);

    mItems.push_back(RedBug);
    return RedBug;
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
		if((*i)->HitTest(x, y) && !(*i)->GetSplat())
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
	mItems.clear();
}


/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 * @param timeInSec The time the level been running
 */
void Game::Update(double elapsed, double timeInSec)
{
	vector<shared_ptr<Item>> bugToRemove;

    BugScoreboardVisitor visitor;
    visitor.SetScoreboard(GetScoreboard());


	/// check if bugs are at the program
	for (auto bug : mItems)
	{
		// Check to see if the bugs are at the program
		if(bug->AtProgram())
		{
            bug->Accept(&visitor);
			bugToRemove.push_back(bug);
		}
		// Calling update on a null pointer
		bug->Update(elapsed, timeInSec);
	}

	/// this for loop is used to remove all the bugs at the program
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
/**
 * Finds the Bitmap that relates to that type of the bug
 *
 * @param itemType The image the looking for
 * @return The vector that is holding the Bitmap images
 */
std::vector<std::pair<wxString, std::shared_ptr<wxBitmap>>> Game::GetItemBitmaps(wxString itemType)
{
	auto it = mItemBitmaps.find(itemType);
	// Return the vector for bugType.
	if (it != mItemBitmaps.end())
	{
		return it->second;
	}
	else
	{
		return {};
	}
}

/**
 * adds the bitmaps data to game
 * @param itemType type of item
 * @param bitmaps all the bitmaps associated with it
 */
void Game::AddItemBitmap(wxString itemType, std::vector<std::pair<wxString, std::shared_ptr<wxBitmap>>> bitmaps)
{
	mItemBitmaps[itemType] = bitmaps;
}

/**
 * Play level 3
 */
void Game::PlayVirus()
{
	// Find the virus
	VirusVisitor visitVirus;
	this->Accept(&visitVirus);
	Virus* virus = visitVirus.FetchVirus();

	// Find the feature bugs
	FeatureVisitor visitFeatureBugs;
	this->Accept(&visitFeatureBugs);
	std::vector<FeatureBug*> featureBugs = visitFeatureBugs.FetchFeatureBugs();

	double virusX = virus->GetX();
	double virusY = virus->GetY();

	if ( !featureBugs.empty()){
		for (auto featureBug : featureBugs)
		{
			double featureX = featureBug->GetX();
			double featureY = featureBug->GetY();
			double distance = sqrt(pow((virusX-featureX),2)+pow((virusY-featureY),2));
			// Check if any of the feature bugs are in the same location as the virus
			if (distance<= 80)
			{
				for (auto item: mItems){
					if (item.get() == featureBug){
						// Virus infiltrates Feature bug and converts it to a Null bug
						auto node = new wxXmlNode(wxXML_ELEMENT_NODE, L"bug");
						node->AddAttribute(L"type", "null");
						node->AddAttribute(L"x", wxString::FromDouble(featureX));
						node->AddAttribute(L"y", wxString::FromDouble(featureY));
						double speed = rand() % 80 + 100;
						node->AddAttribute(L"speed", wxString::FromDouble(speed));
						node->AddAttribute(L"start", wxString::FromDouble(0));
						shared_ptr <Bug> bug = make_shared<NullBug>(this,visitFeatureBugs.FetchProgram(),
																	node);
						DeleteBug(item);
						mItems.push_back(bug);
					}
				}
			}
	    }
	}
}
