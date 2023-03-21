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
    s.IncFixed();
    s.IncMissed();
    s.IncOops();

	ASSERT_EQ(s.GetFixed(),1);
	ASSERT_EQ(s.GetMissed(),1);
	ASSERT_EQ(s.GetOops(),1);

	//Just changing Fix
    s.IncFixed();
    s.IncFixed();

	ASSERT_EQ(s.GetFixed(),3);
	ASSERT_EQ(s.GetMissed(),1);
	ASSERT_EQ(s.GetOops(),1);

	//Just changing Miss
    s.IncMissed();

	ASSERT_EQ(s.GetFixed(),3);
	ASSERT_EQ(s.GetMissed(),2);
	ASSERT_EQ(s.GetOops(),1);

	//Just changing Oops
    s.IncOops();
    s.IncOops();
    s.IncOops();

	ASSERT_EQ(s.GetFixed(),3);
	ASSERT_EQ(s.GetMissed(),2);
	ASSERT_EQ(s.GetOops(),4);

	// There need to add to the Setters as well

}
