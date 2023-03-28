/**
 * @file SpiderTest.cpp
 * @author Auden Garrard
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Virus.h>
#include <Game.h>
#include <Program.h>

using namespace std;

TEST(Spider,Construct)
{
	Game game;
	wxXmlNode bug;
	shared_ptr<Item> program = make_shared<Program>(&game,&bug);
	Virus spider(&game, program, &bug);
}

TEST(Spider,HitTest)
{
	Game game;
	wxXmlNode bug;
	shared_ptr<Item> program = make_shared<Program>(&game,&bug);
	Virus spider(&game, program, &bug);

	spider.SetLocation(200,200);

	// Right in the middle
	ASSERT_TRUE(spider.HitTest(200,200));


	// Larger X
	ASSERT_FALSE(spider.HitTest(300,200));

	//Smaller X
	ASSERT_FALSE(spider.HitTest(150,200));

	//Smaller Y
	ASSERT_FALSE(spider.HitTest(300,150));

	//Lager Y
	ASSERT_FALSE(spider.HitTest(300,250));
}

TEST(Spider,GetterAndSetter)
{
	Game game;
	wxXmlNode bug;
	shared_ptr<Item> program = make_shared<Program>(&game,&bug);
	Virus spider(&game, program, &bug);

	// Sets the location
	spider.SetLocation(200,250);

	//
	// GetX and GetY
	//

	//Checks the X
	ASSERT_NEAR(spider.GetX(),200,.001);

	ASSERT_NEAR(spider.GetY(),250,.001);

	// Check again to make sure
	spider.SetLocation(300,500);

	ASSERT_NEAR(spider.GetX(),300,.001);

	ASSERT_NEAR(spider.GetY(),500,.001);


	//
	// See if the bug has been clicked on
	//
	ASSERT_FALSE(spider.GetSplat());

	spider.ClickedOn();

	ASSERT_FALSE(spider.GetSplat());
}

TEST(Spider,Update)
{
	Game game;
	wxXmlNode bug;
	shared_ptr<Item> program = make_shared<Program>(&game,&bug);
	program->SetLocation(200,200);
	Virus spider(&game, program, &bug);
	//NullBug programLocation(&game);

	spider.SetLocation(50,50);
	spider.SetSpeed(5);
	//featureBug.SetProgramLocation(300,350);

	// Check for time update
	spider.Update(0, 0);
	ASSERT_NEAR(spider.GetX(),50,.0001);
	ASSERT_NEAR(spider.GetY(),50,.0001);

	spider.Update(2.0, 2);
	// These will need change once we are not hard coding the program
	ASSERT_NEAR(spider.GetX(),50,.01);
	ASSERT_NEAR(spider.GetY(),50,.01);

	spider.Update(2.0, 4);
	ASSERT_NEAR(spider.GetX(),50,.01);
	ASSERT_NEAR(spider.GetY(),50,.01);
}