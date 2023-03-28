/**
 * @file FeatureBugTest.cpp
 * @author Auden Garrard
 */


#include <pch.h>
#include "gtest/gtest.h"
#include <FeatureBug.h>
#include <Game.h>
#include <Program.h>

using namespace std;

TEST(FeatureBug,Construct)
{
	Game game;
	wxXmlNode bug;
	shared_ptr<Item> program = make_shared<Program>(&game,&bug);
	FeatureBug featureBug(&game,program,&bug);
}

TEST(FeatureBug,HitTest)
{
	Game game;
	wxXmlNode bug;
	shared_ptr<Item> program = make_shared<Program>(&game,&bug);
	FeatureBug featureBug(&game,program,&bug);

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
	wxXmlNode bug;
	shared_ptr<Item> program = make_shared<Program>(&game,&bug);
	FeatureBug featureBug(&game,program,&bug);

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

}

TEST(FeatureBug,Update)
{
	Game game;
	wxXmlNode bug;
	shared_ptr<Item> program = make_shared<Program>(&game,&bug);
	program->SetLocation(200,200);
	FeatureBug featureBug(&game,program,&bug);


	featureBug.SetLocation(50,50);
	featureBug.SetSpeed(5);
	//featureBug.SetProgramLocation(300,350);

	// Check for time update
	featureBug.Update(0, 0);
	ASSERT_NEAR(featureBug.GetX(),50,.0001);
	ASSERT_NEAR(featureBug.GetY(),50,.0001);

	featureBug.Update(2.0, 2);
	// These will need change once we are not hard coding the program
	ASSERT_NEAR(featureBug.GetX(),57.07,.01);
	ASSERT_NEAR(featureBug.GetY(),57.07,.01);

	featureBug.Update(2.0, 4);
	ASSERT_NEAR(featureBug.GetX(),64.14,.01);
	ASSERT_NEAR(featureBug.GetY(),64.14,.01);
}


