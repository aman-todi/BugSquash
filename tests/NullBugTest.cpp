/**
 * @file NullBugTest.cpp
 * @author Auden Garrard
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <NullBug.h>
#include <Game.h>

using namespace std;

TEST(NullBug,Construct)
{
	Game game;
	NullBug nullBug(&game);
}

TEST(NullBug,HitTest)
{
	Game game;
	NullBug nullBug(&game);

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
	NullBug nullBug(&game);

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
	ASSERT_NEAR(nullBug.GetHeight(),100,.001);
}