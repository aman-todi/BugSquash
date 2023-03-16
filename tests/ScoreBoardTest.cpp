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

	// There need to add to the Setters as well

}

