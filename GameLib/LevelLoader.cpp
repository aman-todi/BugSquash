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



LevelLoader::LevelLoader(Game *game,const std::wstring &fileName)
{

	// Load the XML file
	wxXmlDocument doc;


	doc.Load(fileName);
	// Get the root element
	wxXmlNode *bugSquash = doc.GetRoot();

	// Access the program element and its attributes
	wxXmlNode* program = bugSquash->GetChildren();

	while (program!=NULL)
	{
		// Access the bug elements and their attributes
		wxXmlNode *bugNode = program->GetChildren();

		// Create a vector to store the bugs
		std::vector<wxXmlNode*> bugs;

		while(bugNode != NULL)
		{
			// Check if the child is a "bug" element
			if(bugNode->GetName() == "bug" || bugNode->GetName() == "feature")
			{
				bugs.push_back(bugNode);
			}
			bugNode = bugNode->GetNext();
		}

		for(auto node : bugs)
		{
			wxString nodeName = node->GetName();

			if(nodeName == "feature")
			{
				shared_ptr <Bug> bug = make_shared<FeatureBug>(game);
				double x, y, speed;
				bool xa = node->GetAttribute("x").ToDouble(&x);
				bool ya = node->GetAttribute("y").ToDouble(&y);
				bool sp = node->GetAttribute("speed").ToDouble(&speed);
				bug->SetLocation(x,y);
				bug->SetSpeed(speed);
				game->Add(bug);
			}

			wxString bugType = node->GetAttribute("type");

			if(bugType == "garbage")
			{
				shared_ptr <Bug> bug = make_shared<GarbageBug>(game);
				double x, y, speed;
				bool xa = node->GetAttribute("x").ToDouble(&x);
				bool ya = node->GetAttribute("y").ToDouble(&y);
				bool sp = node->GetAttribute("speed").ToDouble(&speed);
				bug->SetLocation(x,y);
				bug->SetSpeed(speed);
				game->Add(bug);
			}
			else if(bugType == "null")
			{
				shared_ptr <Bug> bug = make_shared<NullBug>(game);
				double x, y, speed;
				bool xa = node->GetAttribute("x").ToDouble(&x);
				bool ya = node->GetAttribute("y").ToDouble(&y);
				bool sp = node->GetAttribute("speed").ToDouble(&speed);
				bug->SetLocation(x,y);
				bug->SetSpeed(speed);
				game->Add(bug);
			}
			else if(bugType == "redundancy")
			{
				shared_ptr <Bug> bug = make_shared<RedundancyBug>(game);
				double x, y, speed;
				bool xa = node->GetAttribute("x").ToDouble(&x);
				bool ya = node->GetAttribute("y").ToDouble(&y);
				bool sp = node->GetAttribute("speed").ToDouble(&speed);
				bug->SetLocation(x,y);
				bug->SetSpeed(speed);
				game->Add(bug);
			}
		}
		shared_ptr <Item> laptop = make_shared<Program>(game);
		double x, y;
		bool xa = program->GetAttribute("x").ToDouble(&x);
		bool ya = program->GetAttribute("y").ToDouble(&y);
		laptop->SetLocation(x,y);
		game->Add(laptop);
		program = program->GetNext();
	}
}
