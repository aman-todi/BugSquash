/**
 * @file LoadLevelOne.cpp
 * @author sriram
 */

#include "LoadLevelOne.h"

/// The level1 XML file
const std::wstring LevelOneXMLFileName = L"data/level1.xml";

LoadLevelOne::LoadLevelOne(Game *game)
{

	// Create a new XML document
	wxXmlDocument doc;
	// Get the root element
    doc.Load(LevelOneXMLFileName);
	wxXmlNode* root = doc.GetRoot();

	// Access the program element and its attributes
	wxXmlNode* program = root->GetChildren();
	wxString program_name = program->GetAttribute("name");
	wxString program_x = program->GetAttribute("x");
	wxString program_y = program->GetAttribute("y");

	// Access the bug elements and their attributes
	wxXmlNode* bugs = program->GetNext();
	for (wxXmlNode* bug = bugs->GetChildren(); bug; bug = bug->GetNext()) {
		wxString bug_type = bug->GetAttribute("type");
		wxString bug_x = bug->GetAttribute("x");
		wxString bug_y = bug->GetAttribute("y");
		wxString bug_speed = bug->GetAttribute("speed");
		wxString bug_start = bug->GetAttribute("start");

		// Access the code snippet for bugs with associated code
		wxXmlNode* code = bug->GetChildren();
		if (code && code->GetType() == wxXML_TEXT_NODE) {
			wxString code_pass = code->GetAttribute("pass");
			wxString code_text = code->GetContent();
		}
	}

	// Access the feature element and its attributes
	wxXmlNode* feature = bugs->GetNext();
	wxString feature_x = feature->GetAttribute("x");
	wxString feature_y = feature->GetAttribute("y");
	wxString feature_speed = feature->GetAttribute("speed");
	wxString feature_start = feature->GetAttribute("start");

}
