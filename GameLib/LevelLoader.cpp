/**
 * @file LevelLoader.cpp
 * @author sriram
 */

#include "pch.h"
#include <wx/xml/xml.h>
#include "LevelLoader.h"
#include "Bug.h"
#include "Item.h"
#include "GarbageBug.h"
#include "NullBug.h"
#include "RedundancyBug.h"
#include "FeatureBug.h"
#include "Program.h"
#include "Scoreboard.h"
#include "Spider.h"

/// The feature sprite image
const std::wstring FeatureBugImageName = L"images/feature.png";

/// The splat image
const std::wstring FeatureBugSplatImageName = L"images/feature-splat.png";

/// The bug base image
const std::wstring RedundancyBugImage = L"images/redundancy-fly-base.png";

/// The bug top image
const std::wstring RedundancyFlyTopImageName = L"images/redundancy-fly-top.png";

/// The left wing image
const std::wstring RedundancyFlyLeftWingImageName = L"images/redundancy-fly-lwing.png";

/// The right wing image
const std::wstring RedundancyFlyRightWingImageName = L"images/redundancy-fly-rwing.png";

/// The splat image
const std::wstring RedundancyFlySplatImageName = L"images/redundancy-fly-splat.png";

/// The Spider image
const std::wstring SpiderBugImageName = L"images/spider.png";

/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// The bug sprite image
const std::wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";

/// The splat image
const std::wstring NullBugSplatImageName = L"images/scarlet-gray-splat.png";

/// Program image filename
const std::wstring ProgramImage = L"images/laptop.png";

using namespace std;

/**
 * Loads the level
 * @param game The game being loaded too
 * @param fileName The file being loaded in
 */

LevelLoader::LevelLoader(Game *game,const std::wstring &fileName)
{
    // Reset Scoreboard
    game->GetScoreboard()->ResetScore();

	// Load the XML file
	wxXmlDocument doc;

	doc.Load(fileName);
	// Get the root element
	wxXmlNode *bugSquash = doc.GetRoot();

    auto levelName = bugSquash->GetAttribute(L"level");
    game->SetLevelName(levelName);

	// Access the program element and its attributes
	wxXmlNode* program = bugSquash->GetChildren();

	// All the bugs in game
	vector<shared_ptr<Item> > bugItems;

	while (program!=NULL)
	{
		// Access the bug elements and their attributes
		wxXmlNode *bugNode = program->GetChildren();

		if (game->GetItemBitmaps("program").empty())
		{
			auto programBitmap = make_shared<wxBitmap>(ProgramImage,
															wxBITMAP_TYPE_ANY);
			vector<pair<wxString, shared_ptr<wxBitmap>>> bitmaps;
			bitmaps.push_back(std::make_pair("program",programBitmap));
			game->AddItemBitmap("program",bitmaps);
		}

		mNumPrograms++;
		shared_ptr <Item> laptop = make_shared<Program>(game,program);

		game->AddItem(laptop);

		// Create a vector to store the bugs
		vector<wxXmlNode*> bugs;

		while(bugNode != NULL)
		{
			// Check if the child is a "bug" element
			if(bugNode->GetName() == "bug" || bugNode->GetName() == "feature" || bugNode->GetName() == "spider")
			{
				bugs.push_back(bugNode);
				mNumBugs++;
			}
			bugNode = bugNode->GetNext();
		}

		for(auto node : bugs)
		{
			auto bugType = node->GetAttribute("type");

			if(bugType == "garbage")
			{
				if (game->GetItemBitmaps(bugType).empty())

				{
					auto splatBitmap = make_shared<wxBitmap>(GarbageBugSplatImageName,
																  wxBITMAP_TYPE_ANY);
					auto spriteBitmap = make_shared<wxBitmap>(GarbageBugSpriteImageName
																,wxBITMAP_TYPE_ANY);
					vector<pair<wxString, shared_ptr<wxBitmap>>> bitmaps;
					bitmaps.push_back(std::make_pair("Splat",splatBitmap));
					bitmaps.push_back(std::make_pair("SpriteSheet",spriteBitmap));
					game->AddItemBitmap(bugType,bitmaps);
				}

				shared_ptr <Bug> bug = make_shared<GarbageBug>(game,laptop,node);
				bugItems.push_back(bug);
			}

			else if(bugType == "null")
			{

				if (game->GetItemBitmaps(bugType).empty())
				{
					auto splatBitmap = make_shared<wxBitmap>(NullBugSplatImageName,
																  wxBITMAP_TYPE_ANY);
					auto spriteBitmap = make_shared<wxBitmap>(NullBugSpriteImageName
						,wxBITMAP_TYPE_ANY);
					vector<std::pair<wxString, std::shared_ptr<wxBitmap>>> bitmaps;
					bitmaps.push_back(std::make_pair("Splat",splatBitmap));
					bitmaps.push_back(std::make_pair("SpriteSheet",spriteBitmap));
					game->AddItemBitmap(bugType,bitmaps);
				}

				shared_ptr <Bug> bug = make_shared<NullBug>(game,laptop,node);
				bugItems.push_back(bug);
			}
			else if(bugType == "redundancy")
			{

				if (game->GetItemBitmaps(bugType).empty())
				{
					auto splatBitmap = make_shared<wxBitmap>(RedundancyFlySplatImageName,
																  wxBITMAP_TYPE_ANY);
					auto baseBitmap = make_shared<wxBitmap>(RedundancyBugImage
						,wxBITMAP_TYPE_ANY);
					auto topBitmap = make_shared<wxBitmap>(RedundancyFlyTopImageName
						,wxBITMAP_TYPE_ANY);

					auto rightWingBitmap = make_shared<wxBitmap>(RedundancyFlyRightWingImageName
						,wxBITMAP_TYPE_ANY);

					auto leftWingBitmap = make_shared<wxBitmap>(RedundancyFlyLeftWingImageName
						,wxBITMAP_TYPE_ANY);

					vector<std::pair<wxString, shared_ptr<wxBitmap>>> bitmaps;

					bitmaps.push_back(std::make_pair("Splat",splatBitmap));
					bitmaps.push_back(std::make_pair("Base",baseBitmap));
					bitmaps.push_back(std::make_pair("Top",topBitmap));
					bitmaps.push_back(std::make_pair("RightWing",rightWingBitmap));
					bitmaps.push_back(std::make_pair("LeftWing",leftWingBitmap));

					game->AddItemBitmap(bugType,bitmaps);
				}

				shared_ptr <Bug> bug = make_shared<RedundancyBug>(game,laptop,node);
				bugItems.push_back(bug);
			}
			else if(bugType == "spider")
			{
				if (game->GetItemBitmaps(bugType).empty())
				{
					auto spriteBitmap = make_shared<wxBitmap>(SpiderBugImageName
						,wxBITMAP_TYPE_ANY);

					vector<std::pair<wxString, shared_ptr<wxBitmap>>> bitmaps;
					bitmaps.push_back(std::make_pair("SpriteSheet",spriteBitmap));

					game->AddItemBitmap(bugType,bitmaps);
				}
				shared_ptr <Bug> bug = make_shared<Spider>(game,laptop,node);
				bugItems.push_back(bug);
			}
			else{
				if (game->GetItemBitmaps(bugType).empty())
				{
					auto splatBitmap = make_shared<wxBitmap>(FeatureBugSplatImageName,
															 wxBITMAP_TYPE_ANY);
					auto spriteBitmap = make_shared<wxBitmap>(FeatureBugImageName
						,wxBITMAP_TYPE_ANY);

					vector<std::pair<wxString, shared_ptr<wxBitmap>>> bitmaps;
					bitmaps.push_back(std::make_pair("Splat",splatBitmap));
					bitmaps.push_back(std::make_pair("SpriteSheet",spriteBitmap));

					game->AddItemBitmap("feature",bitmaps);
				}
				shared_ptr <Bug> bug = make_shared<FeatureBug>(game,laptop,node);
				bugItems.push_back(bug);
			}

		}
		program = program->GetNext();
	}
	for (auto bug: bugItems)
	{
		game->AddItem(bug);
	}
}
