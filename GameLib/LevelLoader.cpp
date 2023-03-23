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
	std::vector<std::shared_ptr<Item> > bugItems;

	while (program!=NULL)
	{
		// Access the bug elements and their attributes
		wxXmlNode *bugNode = program->GetChildren();

		mNumPrograms++;
		shared_ptr <Item> laptop = make_shared<Program>(game,program);

		game->Add(laptop);

		// Create a vector to store the bugs
		std::vector<wxXmlNode*> bugs;

		while(bugNode != NULL)
		{
			// Check if the child is a "bug" element
			if(bugNode->GetName() == "bug" || bugNode->GetName() == "feature")
			{
				bugs.push_back(bugNode);
				mNumBugs++;
			}
			bugNode = bugNode->GetNext();
		}

		for(auto node : bugs)
		{
			wxString bugType = node->GetAttribute("type");

			if(bugType == "garbage")
			{
				shared_ptr <Bug> bug = make_shared<GarbageBug>(game,program,node);
				bugItems.push_back(bug);
			}
			else if(bugType == "null")
			{
				shared_ptr <Bug> bug = make_shared<NullBug>(game,program,node);
				bugItems.push_back(bug);
			}
			else if(bugType == "redundancy")
			{
				shared_ptr <Bug> bug = make_shared<RedundancyBug>(game,program,node);
				bugItems.push_back(bug);
			}
			else
			{
				shared_ptr <Bug> bug = make_shared<FeatureBug>(game,program,node);
				bugItems.push_back(bug);
			}

		}
		program = program->GetNext();
	}
	for (auto bug: bugItems)
	{
		game->Add(bug);
	}
}
