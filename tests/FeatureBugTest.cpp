/**
 * @file FeatureBugTest.cpp
 * @author Auden Garrard
 */


#include <pch.h>
#include "gtest/gtest.h"
#include <FeatureBug.h>
#include <Game.h>


using namespace std;

TEST(FeatureBug,Construct)
{
	Game game;
	wxXmlNode program;
	wxXmlNode bug;
	FeatureBug featureBug(&game,&program,&bug);
}

TEST(FeatureBug,HitTest)
{
	Game game;
	wxXmlNode program;
	wxXmlNode bug;
	FeatureBug featureBug(&game,&program,&bug);

	featureBug.SetLocation(200,200);

	// Right in the middle
	ASSERT_TRUE(featureBug.HitTest(200,200));

	// Larger X
	ASSERT_FALSE(featureBug.HitTest(300,200));

	//Smaller X
	ASSERT_FALSE(featureBug.HitTest(150,200));

	//Smaller Y
	ASSERT_FALSE(featureBug.HitTest(300,150));

	//Lager Y
	ASSERT_FALSE(featureBug.HitTest(300,250));
}


TEST(FeatureBug,GetterAndSetter)
{
	Game game;
	wxXmlNode program;
	wxXmlNode bug;
	FeatureBug featureBug(&game,&program,&bug);

	// Sets the location
	featureBug.SetLocation(200,250);

	//
	// GetX and GetY
	//

	//Checks the X
	ASSERT_NEAR(featureBug.GetX(),200,.001);

	ASSERT_NEAR(featureBug.GetY(),250,.001);

	// Check again to make sure
	featureBug.SetLocation(300,500);

	ASSERT_NEAR(featureBug.GetX(),300,.001);

	ASSERT_NEAR(featureBug.GetY(),500,.001);

	//
	// GetWidth and GetHeight
	//

	cout << "GetWidth and Height " << endl;

	ASSERT_NEAR(featureBug.GetWidth(),100,.001);

	// This is saying the sprite sheet is till 600 pixel
	// that might be where are error could be coming from
	ASSERT_NEAR(featureBug.GetHeight(),700,.001);
}

TEST(FeatureBug,Update)
{
	Game game;
	wxXmlNode program;
	wxXmlNode bug;
	FeatureBug featureBug(&game,&program,&bug);
	//NullBug programLocation(&game);

	featureBug.SetLocation(50,50);
	featureBug.SetSpeed(5);
	//featureBug.SetProgramLocation(300,350);

	// Check for time update
	featureBug.Update(0, 0);
	ASSERT_NEAR(featureBug.GetX(),50,.0001);
	ASSERT_NEAR(featureBug.GetY(),50,.0001);

	featureBug.Update(2.0, 2);
	// These will need change once we are not hard coding the program
	ASSERT_NEAR(featureBug.GetX(),42.92,.01);
	ASSERT_NEAR(featureBug.GetY(),42.92,.01);

	featureBug.Update(2.0, 4);
	ASSERT_NEAR(featureBug.GetX(),35.86,.01);
	ASSERT_NEAR(featureBug.GetY(),35.86,.01);
}


