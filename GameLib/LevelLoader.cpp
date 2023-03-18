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

		shared_ptr <Item> laptop = make_shared<Program>(game);
		double programX, programY;

		bool xConvert = program->GetAttribute("x").ToDouble(&programX);
		bool yConvert = program->GetAttribute("y").ToDouble(&programY);
		std::string name= program->GetAttribute("name").ToStdString();

		laptop->SetLocation(programX,programY);
		laptop->SetName(name);
		game->Add(laptop);

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

			shared_ptr <Bug> bug = make_shared<FeatureBug>(game);

			wxString bugType = node->GetAttribute("type");

			if(bugType == "garbage")
			{
				bug = make_shared<GarbageBug>(game);
			}
			else if(bugType == "null")
			{
				bug = make_shared<NullBug>(game);
			}
			else if(bugType == "redundancy")
			{
				bug = make_shared<RedundancyBug>(game);

			}
			double bugX, bugY, speed;
			bool xConvert = node->GetAttribute("x").ToDouble(&bugX);
			bool yConvert = node->GetAttribute("y").ToDouble(&bugY);
			bool speedConvert = node->GetAttribute("speed").ToDouble(&speed);
			bug->SetLocation(bugX,bugY);
			bug->SetSpeed(speed);
			bug->SetProgramLocation(programX,programY);
			game->Add(bug);

		}
		program = program->GetNext();
	}
}
