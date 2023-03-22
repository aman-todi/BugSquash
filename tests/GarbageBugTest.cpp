/**
 * @file GarbafeBugTest.cpp
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

TEST(GarbageBug,Construct)
{
	Game game;
	wxXmlNode program;
	wxXmlNode bug;
	GarbageBug garbageBug(&game,&program,&bug);
}

TEST(GarbageBug,HitTest)
{
	Game game;
	wxXmlNode program;
	wxXmlNode bug;
	GarbageBug garbageBug(&game,&program,&bug);

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


TEST(GarbageBug,GetterAndSetter)
{
	Game game;
	wxXmlNode program;
	wxXmlNode bug;
	GarbageBug garbageBug(&game,&program,&bug);

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

	//
	// GetWidth and GetHeight
	//

	cout << "GetWidth and Height " << endl;

	ASSERT_NEAR(garbageBug.GetWidth(),100,.001);

	// This is saying the sprite sheet is till 600 pixel
	// that might be where are error could be coming from
	ASSERT_NEAR(garbageBug.GetHeight(),600,.001);
}

TEST(GarbageBug,Update)
{
	Game game;
	wxXmlNode program;
	wxXmlNode bug;
	GarbageBug garbageBug(&game,&program,&bug);
	//NullBug programLocation(&game);

	garbageBug.SetLocation(50,50);
	garbageBug.SetSpeed(5);
	//garbageBug.SetProgramLocation(300,350);

	// Check for time update
	garbageBug.Update(0);
	ASSERT_NEAR(garbageBug.GetX(),50,.0001);
	ASSERT_NEAR(garbageBug.GetY(),50,.0001);

	garbageBug.Update(2.0);
	// These will need change once we are not hard coding the program
	ASSERT_NEAR(garbageBug.GetX(),69.87,.1);
	ASSERT_NEAR(garbageBug.GetY(),57.68,.01);

	garbageBug.Update(2.0);
	ASSERT_NEAR(garbageBug.GetX(),62.80,.01);
	ASSERT_NEAR(garbageBug.GetY(),65.36,.01);
}


///// Don't know how to get access to the draw/how to make a grapihc in this test case
//TEST(GarbageBug,Splat)
//{
//	Game game;
//	GarbageBug garbageBug(&game);
//
//	garbageBug.SetSpeed(50,50);
//
//	ASSERT_NEAR(garbageBug.GetSpeed(),70.71,.001);
//
//	wxAutoBufferedPaintDC dc(this);
//
//	auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));
//
//	garbageBug.ClickedOn(gc);
//
//	ASSERT_NEAR(garbageBug.GetSpeed(),0,.0001);
//
//
//}
//
//

