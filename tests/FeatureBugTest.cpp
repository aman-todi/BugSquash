/**
 * @file FeatureBugTest.cpp
 * @author Auden Garrard
 */
/**
 * @file GarbafeBugTest.cpp
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
	FeatureBug featureBug(&game);
}

TEST(FeatureBug,HitTest)
{
	Game game;
	FeatureBug featureBug(&game);

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
	FeatureBug featureBug(&game);

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
	ASSERT_NEAR(featureBug.GetHeight(),100,.001);
}

TEST(FeatureBug,Update)
{
	Game game;
	FeatureBug featureBug(&game);

	featureBug.SetLocation(50,50);

	// Check for time update
	featureBug.Update(0);
	ASSERT_NEAR(featureBug.GetX(),50,.1);
	ASSERT_NEAR(featureBug.GetY(),50,.1);

	featureBug.Update(2.0);
	// These will need change once we are not hard coding the program
	ASSERT_NEAR(featureBug.GetX(),104.6,.1);
	ASSERT_NEAR(featureBug.GetY(),92.75,.1);

	featureBug.Update(2.0);
	ASSERT_NEAR(featureBug.GetX(),159.27,.1);
	ASSERT_NEAR(featureBug.GetY(),135.51,.1);
}
///// Don't know how to get access to the draw/how to make a grapihc in this test case
//TEST(FeatureBug,Splat)
//{
//	Game game;
//	FeatureBug featureBug(&game);
//
//	featureBug.SetSpeed(50,50);
//
//	ASSERT_NEAR(featureBug.GetSpeed(),70.71,.001);
//
//	wxAutoBufferedPaintDC dc(this);
//
//	auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));
//
//	garbageBug.ClickedOn(gc);
//
//	ASSERT_NEAR(featureBug.GetSpeed(),0,.0001);
//
//
//}
//
//

