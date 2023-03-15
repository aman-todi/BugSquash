/**
 * @file GameTest.cpp
 * @author Auden Garrard
 */


#include <pch.h>
//Test the regex
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>


#include "gtest/gtest.h"
//Bugs
#include <NullBug.h>
#include <FeatureBug.h>
#include <GarbageBug.h>
#include <RedundancyBug.h>


using namespace std;



class GameTest : public :: testing ::Test{
protected:
	//Put the function into this file

};
TEST_F(GameTest,Construct)
{
	Game game;
}

