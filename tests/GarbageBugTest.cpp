/**
 * @file GarbageBugTest.cpp
 * @author Auden Garrard
 */



#include <pch.h>
#include "gtest/gtest.h"
#include <GarbageBug.h>
#include <Game.h>

#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

using namespace std;

/**
 * Test Garbage Bug Constructor
 */
TEST(GarbageBug,Construct)
{
	Game game;
	shared_ptr<Item> program;
	wxXmlNode bug;
	GarbageBug garbageBug(&game,program,&bug);
}

/**
 * Garbage Bug Hit Test
 */
TEST(GarbageBug,HitTest)
{
	Game game;
	shared_ptr<Item> program;
	wxXmlNode bug;
	GarbageBug garbageBug(&game,program,&bug);

	garbageBug.SetLocation(200,200);

	// Right in the middle
	ASSERT_TRUE(garbageBug.HitTest(200,200));

	// Larger X
	ASSERT_FALSE(garbageBug.HitTest(300,200));

	// Smaller X
	ASSERT_FALSE(garbageBug.HitTest(150,200));

	// Smaller Y
	ASSERT_FALSE(garbageBug.HitTest(300,150));

	// Lager Y
	ASSERT_FALSE(garbageBug.HitTest(300,250));
}

/**
 * Test getter and setter
 */
TEST(GarbageBug,GetterAndSetter)
{
	Game game;
	shared_ptr<Item> program;
	wxXmlNode bug;
	GarbageBug garbageBug(&game,program,&bug);

	// Sets the location
	garbageBug.SetLocation(200,250);

	//
	// GetX and GetY
	//

	//Checks the X
	ASSERT_NEAR(garbageBug.GetX(),200,.001);

	ASSERT_NEAR(garbageBug.GetY(),250,.001);

	// Check again to make sure
	garbageBug.SetLocation(300,500);

	ASSERT_NEAR(garbageBug.GetX(),300,.001);

	ASSERT_NEAR(garbageBug.GetY(),500,.001);

}

/**
 * Test Garbage Bug Update
 */
TEST(GarbageBug,Update)
{
	Game game;
	wxXmlNode bug;
	shared_ptr<Item> program = make_shared<Program>(&game,&bug);
	program->SetLocation(200,200);
	GarbageBug garbageBug(&game,program,&bug);
	//NullBug programLocation(&game);

	garbageBug.SetLocation(50,50);
	garbageBug.SetSpeed(5);
	//garbageBug.SetProgramLocation(300,350);

	// Check for time update
	garbageBug.Update(0, 0);
	ASSERT_NEAR(garbageBug.GetX(),50,.0001);
	ASSERT_NEAR(garbageBug.GetY(),50,.0001);

	garbageBug.Update(2.0, 2);
	// These will need change once we are not hard coding the program
	ASSERT_NEAR(garbageBug.GetX(),57.07,.1);
	ASSERT_NEAR(garbageBug.GetY(),57.07,.01);

	garbageBug.Update(2.0, 4);
	ASSERT_NEAR(garbageBug.GetX(),64.14,.01);
	ASSERT_NEAR(garbageBug.GetY(),64.14,.01);
}

