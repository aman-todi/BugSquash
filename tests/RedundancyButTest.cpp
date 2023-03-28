/**
 * @file RedundancyButTest.cpp
 * @author Auden Garrard
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <RedundancyBug.h>
#include <Game.h>
#include <Program.h>

using namespace std;

TEST(RedundancyBug,Construct)
{
	Game game;
	shared_ptr<Item> program;
	wxXmlNode bug;
	RedundancyBug redundancyBug(&game,program,&bug);
}

TEST(RedundancyBug,HitTest)
{
	Game game;
	shared_ptr<Item> program;
	wxXmlNode bug;
	RedundancyBug redundancyBug(&game,program,&bug);

	redundancyBug.SetLocation(200,200);

	// Right in the middle
	ASSERT_TRUE(redundancyBug.HitTest(200,200));


	// Larger X
	ASSERT_FALSE(redundancyBug.HitTest(300,200));

	//Smaller X
	ASSERT_FALSE(redundancyBug.HitTest(150,200));

	//Smaller Y
	ASSERT_FALSE(redundancyBug.HitTest(300,150));

	//Lager Y
	ASSERT_FALSE(redundancyBug.HitTest(300,250));
}

TEST(RedundancyBug,GetterAndSetter)
{
	Game game;
	shared_ptr<Item> program;
	wxXmlNode bug;
	RedundancyBug redundancyBug(&game,program,&bug);

	// Sets the location
	redundancyBug.SetLocation(200,250);

	//
	// GetX and GetY
	//

	//Checks the X
	ASSERT_NEAR(redundancyBug.GetX(),200,.001);

	ASSERT_NEAR(redundancyBug.GetY(),250,.001);

	// Check again to make sure
	redundancyBug.SetLocation(300,500);

	ASSERT_NEAR(redundancyBug.GetX(),300,.001);

	ASSERT_NEAR(redundancyBug.GetY(),500,.001);


	//
	// See if the bug has been clicked on
	//
	ASSERT_FALSE(redundancyBug.GetSplat());

	redundancyBug.ClickedOn();

	ASSERT_TRUE(redundancyBug.GetSplat());
}

TEST(RedundancyBug,Update)
{
	Game game;
	wxXmlNode bug;
	shared_ptr<Item> program = make_shared<Program>(&game,&bug);
	program->SetLocation(200,200);
	RedundancyBug redundancyBug(&game,program,&bug);
	//NullBug programLocation(&game);

	redundancyBug.SetLocation(50,50);
	redundancyBug.SetSpeed(5);
	//featureBug.SetProgramLocation(300,350);

	// Check for time update
	redundancyBug.Update(0, 0);
	ASSERT_NEAR(redundancyBug.GetX(),50,.0001);
	ASSERT_NEAR(redundancyBug.GetY(),50,.0001);

	redundancyBug.Update(2.0, 2);
	// These will need change once we are not hard coding the program
	ASSERT_NEAR(redundancyBug.GetX(),57.07,.01);
	ASSERT_NEAR(redundancyBug.GetY(),57.07,.01);

	redundancyBug.Update(2.0, 4);
	ASSERT_NEAR(redundancyBug.GetX(),64.14,.01);
	ASSERT_NEAR(redundancyBug.GetY(),64.14,.01);
}
