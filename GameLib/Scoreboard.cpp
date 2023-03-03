/**
 * @file Scoreboard.cpp
 * @author Ethan Silver
 */

#include "pch.h"
#include "Scoreboard.h"

Scoreboard::Scoreboard()
{
    mFixed = 0;
    mMissed = 0;
    mOops = 0;
}

void Scoreboard::KeepScore(int fix, int miss, int oop)
{
    mFixed += fix;
    mMissed += miss;
    mOops += oop;
}
