/**
 * @file GameTest.cpp
 * @author Auden Garrard
 */


#include <pch.h>
//Test the regex
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>


#include "gtest/gtest.h"
//Bugs
#include <NullBug.h>
#include <FeatureBug.h>
#include <GarbageBug.h>
#include <RedundancyBug.h>


using namespace std;


class GameTest : public :: testing ::Test{
protected:
	/**
	* Create a path to a place to put temporary files
	*/
	wxString TempPath()
	{
		// Create a temporary filename we can use
		auto path = wxFileName::GetTempDir() + L"/game";
		if(!wxFileName::DirExists(path))
		{
			wxFileName::Mkdir(path);
		}

		return path;
	}

	/**
	* Read a file into a wstring and return it.
	* @param filename Name of the file to read
	* @return File contents
	*/
	wstring ReadFile(const wxString &filename)
	{
		ifstream t(filename.ToStdString());
		wstring str((istreambuf_iterator<char>(t)),
					istreambuf_iterator<char>());

		return str;
	}
	/**
	 * Check to make sure all the programs are being load in correct
	 * @param filename Name of the file to read
	 */
	void TestPrograms(wxString filename)
	{
		auto xml  = ReadFile(filename);

		//
		// Level One
		//

		//Check to make sure the right number of programs were load in
		ASSERT_TRUE(regex_search(xml,wregex(L"<bug-squash><program.*</bug-squash>")));

		// Checks the location
		ASSERT_TRUE(regex_search(xml,wregex(L"<program.* x=\"625\" y=\"500\"")));

		//Checks the name are correct
		ASSERT_TRUE(regex_search(xml,wregex(L"<program name=\"Bug Squash\"")));

		//
		// Level Two
		//

		//Check to make sure all there is 3 programs
		ASSERT_TRUE(regex_search(xml,wregex(L"<bug-squash><program.*<program.*<program.*</bug-squash>")));

		//Check the location of the program
		ASSERT_TRUE(regex_search(xml, wregex(L"<program.* x=\"300\" y=\"200\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<program.* x=\"600\" y=\"800\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<program.* x=\"850\" y=\"200\"")));

		//Check for the names
		ASSERT_TRUE(regex_search(xml,wregex(L"<program name=\"Receivables\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<program name=\"SIS\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<program name=\"Enrollment\"")));

		//
		// Level Three
		//
	}
	/**
	 * Makes sure all the bug froms level on are load in correct loction
	 * @param filename Name of the file read
	 */
	void LevelOneBugsLocation(wxString filename)
	{
		auto xml  = ReadFile(filename);

		// All these bugs got to the only program on the screen
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* x=\"500\" y=\"-100\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* x=\"1350\" y=\"100\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* x=\"-100\" y=\"500\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* x=\"1000\" y=\"-100\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<feature x=\"600\" y=\"1100\"")));

		cout << "First Fat Bug " << endl;
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* x=\"-100\" y=\"900\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* x=\"500\" y=\"1100\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<feature x=\"600\" y=\"-100\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* x=\"500\" y=\"1100\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.*  x=\"-100\" y=\"100\"")));

		cout << "Second Fat Bug" << endl;
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.*  x=\"1350\" y=\"1100\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.*  x=\"-100\" y=\"1200\"")));

		cout << "third Fat bug" << endl;
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.*  x=\"-100\" y=\"900\"")));
	}


};
TEST_F(GameTest,Construct)
{
	Game game;
}

TEST_F(GameTest,Load)
{
	auto path = TempPath();


}



