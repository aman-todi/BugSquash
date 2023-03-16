/**
 * @file ScoreBoardTest.cpp
 * @author Auden Garrard
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Scoreboard.h>
#include <Game.h>

TEST(Scoreboard,Construct)
{
	Scoreboard scoreboard;
}

TEST(Scoreboard,GetterAndSetter)
{
	//
	// Checking Getter when on score is added
	//
	Scoreboard s;

	ASSERT_EQ(s.GetFixed(),0);
	ASSERT_EQ(s.GetMissed(),0);
	ASSERT_EQ(s.GetOops(),0);

	//
	// Checks to make sure keep score is working
	//
	s.KeepScore(5,6,7);

	ASSERT_EQ(s.GetFixed(),5);
	ASSERT_EQ(s.GetMissed(),6);
	ASSERT_EQ(s.GetOops(),7);

	//Just changing Fix
	s.KeepScore(5,0,0);

	ASSERT_EQ(s.GetFixed(),10);
	ASSERT_EQ(s.GetMissed(),6);
	ASSERT_EQ(s.GetOops(),7);

	//Just changing Miss
	s.KeepScore(0,5,0);

	ASSERT_EQ(s.GetFixed(),10);
	ASSERT_EQ(s.GetMissed(),11);
	ASSERT_EQ(s.GetOops(),7);

	//Just changing Miss
	s.KeepScore(0,0,1);

	ASSERT_EQ(s.GetFixed(),10);
	ASSERT_EQ(s.GetMissed(),11);
	ASSERT_EQ(s.GetOops(),8);

	// There need to add to the Setters as well

}
