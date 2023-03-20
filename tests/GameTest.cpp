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
#include <LevelLoader.h>
#include <Program.h>

/// The level 0 XML
const std::wstring LevelZeroXMLFileName = L"data/level0.xml";
/// The level 1 XML
const std::wstring LevelOneXMLFileName = L"data/level1.xml";
/// The level 2 XML
const std::wstring LevelTwoXMLFileName = L"data/level2.xml";

using namespace std;


class GameTest : public ::testing::Test{
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
	 * Test to ensure an level .xml file is empty
	 * @param filename The name to the file
	 */
	void TestEmpty(wxString filename)
	{
		cout << "Temp file: " << filename << endl;

		auto xml = ReadFile(filename);

		ASSERT_TRUE(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
		ASSERT_TRUE(regex_search(xml, wregex(L"</bug-squash>")));

	}
	/**
	 *  Populate the game with Three NullBugs
	 * @param game The game to populate the fish to
	 */
	void AddThreeNullBug(Game *game)
	{

		auto bug1 = make_shared<NullBug>(game);
		game->Add(bug1);
		bug1->SetLocation(500,500);


		auto bug2 = make_shared<NullBug>(game);
		game->Add(bug2);
		bug2->SetLocation(750,700);

		auto bug3 = make_shared<NullBug>(game);
		game->Add(bug3);
		bug3->SetLocation(300,800);

	}

    /**
     * Add Level One Bugs
     * @param game the game instance
     */
    void AddLevelOneItems(Game *game) {
        auto program = make_shared<Program>(game);
        program->SetName("Bug Squash");
        game->Add(program);

        auto bug1 = make_shared<GarbageBug>(game);
        bug1->SetLocation(500, -100);
        bug1->SetSpeed(120);
        game->Add(bug1);

        auto bug2 = make_shared<GarbageBug>(game);
        bug2->SetLocation(1350, -100);
        bug2->SetSpeed(150);
        game->Add(bug2);

        auto bug3 = make_shared<NullBug>(game);
        bug3->SetLocation(-100, 500);
        bug3->SetSpeed(150);
        game->Add(bug3);
    }

	/**
	 * Populates the game with one of each bug (missing the fact bugs)
	 * @param game The game to populate the fish to
	 */
	void AddAllTypesOfBugs(Game *game)
	{
		auto nullBug = make_shared<NullBug>(game);
		game->Add(nullBug);
		nullBug->SetLocation(500,500);

		auto garbageBug = make_shared<GarbageBug>(game);
		game->Add(garbageBug);
		garbageBug->SetLocation(600,250);

		auto featureBug = make_shared<FeatureBug>(game);
		game->Add(featureBug);
		featureBug->SetLocation(400,250);

		auto redundancyBug = make_shared<RedundancyBug>(game);
		game->Add(redundancyBug);
		redundancyBug->SetLocation(200,750);
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

	/**
	 * Check to make Level one speed and Start time
	 * was load in correctly
	 * @param filename Name of the file read
	 */
	 void LevelOneBugsSpeedAndStartTime(wxString filename)
	{
		 auto xml = ReadFile(filename);

		 //
		 // Possible need a wild card on the Feature bugs
		 //

		// All these bugs got to the only program on the screen
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* speed=\"120\" start=\"0\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* speed=\"150\" start=\"3\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* speed=\"150\" start=\"5\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* speed=\"120\" start=\"8\"")));
		// This one might need a wildcard in it
		ASSERT_TRUE(regex_search(xml,wregex(L"<feature speed=\"120\" start=\"10\"")));

		cout << "First Fat Bug " << endl;
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* speed=\"60\" start=\"10\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* speed=\"150\" start=\"12\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<feature speed=\"120\" start=\"13\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* speed=\"120\" start=\"15\"")));
		cout << "Second Fat Bug" << endl;
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.* speed=\"150\" start=\"18\"")));
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.*  speed=\"120\" start=\"20\"")));

		cout << "third Fat bug" << endl;
		ASSERT_TRUE(regex_search(xml,wregex(L"<Bug type.*  speed=\"60\" start=\"23\"")));
	}

};

TEST_F(GameTest,Construct)
{
	Game game;
}

//TEST_F(GameTest,ADD)
//{
//	Game game;
//
//}

//TEST_F(GameTest,OnLeftDown)
//{
//	Game game;
//
//	AddThreeNullBug(&game);
//
//	shared_ptr<Item> nullBug = game.OnLeftDown(500,500);
//
////	ASSERT_NEAR(nullBug->GetY(),500,.01);
////	ASSERT_NEAR(nullBug->GetX(),500,.01);
//
//}


//TEST_F(GameTest,LevelLoader)
//{
//	auto path = TempPath();
//
//	Game game1, gameSol;
//
//    LevelLoader levelLoad(&gameSol, LevelZeroXMLFileName);
//
//    auto program = make_shared<Program>(&game1);
//    program->SetName("Bug Squash");
//    program->SetLocation(625, 500);
//
//    game1.Add(program);
//    AddLevelOneItems(&game1);
//
//	//
//	// Compare the manual added Program to
//	// The load in program
//	//
//    auto programSol = gameSol.HitTest(625, 500);
//    ASSERT_EQ(programSol->GetX(), program->GetX());
//    ASSERT_EQ(program->GetY(), programSol->GetY());
//    //ASSERT_EQ(program->GetName(), programSol->GetName());
//
//	//
//	// Compare the manual added bugs to
//	// The load in bugs
//	//
//    auto itm1 = game1.HitTest(500, -100);
//    auto itm1Sol = gameSol.HitTest(500, -100);
//
//    ASSERT_EQ(itm1->GetX(), itm1Sol->GetX());
//    ASSERT_EQ(itm1->GetY(), itm1Sol->GetY());
//
//    auto itm2 = game1.HitTest(1350, 100);
//    auto itm2Sol = game1.HitTest(1350, 100);
//
//    ASSERT_EQ(itm2->GetX(), itm2Sol->GetX());
//    ASSERT_EQ(itm2->GetY(), itm2Sol->GetY());
//
//    auto itm3 = game1.HitTest(-100, 500);
//    auto itm3Sol = game1.HitTest(-100, 500);
//
//    ASSERT_EQ(itm3->GetX(), itm3Sol->GetX());
//    ASSERT_EQ(itm3->GetY(), itm3Sol->GetY());
//}

TEST_F(GameTest,LevelLoader2)
{
	//
	// Check to see if level Zero is load in correct
	//
	Game game0;
	LevelLoader levelZero(&game0, LevelZeroXMLFileName);

	ASSERT_EQ(levelZero.GetNumBugs(),3);
	ASSERT_EQ(levelZero.GetNumPrograms(),1);

	//
	// Check to see if level One is load in correct
	//
	Game game1;
	LevelLoader levelOne(&game1,LevelOneXMLFileName);

	ASSERT_EQ(levelOne.GetNumPrograms(),1);
	ASSERT_EQ(levelOne.GetNumBugs(),12);

	//
	// Check to see if level two is load in correct
	//
	Game game2;
	LevelLoader levelTwo(&game2,LevelTwoXMLFileName);

	ASSERT_EQ(levelTwo.GetNumBugs(),24);
	ASSERT_EQ(levelTwo.GetNumPrograms(),3);
}



