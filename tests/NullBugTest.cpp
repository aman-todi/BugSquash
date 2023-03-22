/**
 * @file NullBugTest.cpp
 * @author Auden Garrard
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <NullBug.h>
#include <Game.h>
#include <Program.h>

using namespace std;

TEST(NullBug,Construct)
{
	Game game;
	wxXmlNode program;
	wxXmlNode bug;
	NullBug nullBug(&game,&program,&bug);
}

TEST(NullBug,HitTest)
{
	Game game;
	wxXmlNode program;
	wxXmlNode bug;
	NullBug nullBug(&game,&program,&bug);

	nullBug.SetLocation(200,200);

	// Right in the middle
	ASSERT_TRUE(nullBug.HitTest(200,200));

	// Larger X
	ASSERT_FALSE(nullBug.HitTest(300,200));

	//Smaller X
	ASSERT_FALSE(nullBug.HitTest(150,200));

	//Smaller Y
	ASSERT_FALSE(nullBug.HitTest(300,150));

	//Lager Y
	ASSERT_FALSE(nullBug.HitTest(300,250));
}

TEST(NULLBug,GetterAndSetter)
{
	Game game;
	wxXmlNode program;
	wxXmlNode bug;
	NullBug nullBug(&game,&program,&bug);

	// Sets the location
	nullBug.SetLocation(200,250);

	//
	// GetX and GetY
	//

	//Checks the X
	ASSERT_NEAR(nullBug.GetX(),200,.001);

	ASSERT_NEAR(nullBug.GetY(),250,.001);

	// Check again to make sure
	nullBug.SetLocation(300,500);

	ASSERT_NEAR(nullBug.GetX(),300,.001);

	ASSERT_NEAR(nullBug.GetY(),500,.001);

	//
	// GetWidth and GetHeight
	//

	cout << "GetWidth and Height " << endl;

	ASSERT_NEAR(nullBug.GetWidth(),100,.001);

	// This is saying the sprite sheet is till 600 pixel
	// that might be where are error could be coming from
	ASSERT_NEAR(nullBug.GetHeight(),700,.001);
}
TEST(NullBug,Update)
{
	Game game;
	wxXmlNode program;
	wxXmlNode bug;
	NullBug nullBug(&game,&program,&bug);
	//NullBug programLocation(&game);

	nullBug.SetLocation(50,50);
	nullBug.SetSpeed(5);
	//nullBug.SetProgramLocation(300,350);

	// Check for time update
	nullBug.Update(0);
	ASSERT_NEAR(nullBug.GetX(),50,.0001);
	ASSERT_NEAR(nullBug.GetY(),50,.0001);

	nullBug.Update(2.0);
	// These will need change once we are not hard coding the program
	ASSERT_NEAR(nullBug.GetX(),42.93,.01);
	ASSERT_NEAR(nullBug.GetY(),57.68,.01);

	nullBug.Update(2.0);
	ASSERT_NEAR(nullBug.GetX(),62.80,.01);
	ASSERT_NEAR(nullBug.GetY(),65.36,.01);
}