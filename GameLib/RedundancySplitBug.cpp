/**
 * @file RedundancySplitBug.cpp
 * @author Blake
 */

#include "pch.h"
#include "RedundancySplitBug.h"
#include "Game.h"
#include "Scoreboard.h"

/// The bug base image
const std::wstring RedundancyBugImage = L"images/redundancy-fly-base.png";

/// The bug top image
const std::wstring RedundancyFlyTopImageName = L"images/redundancy-fly-top.png";

/// The left wing image
const std::wstring RedundancyFlyLeftWingImageName = L"images/redundancy-fly-lwing.png";

/// The right wing image
const std::wstring RedundancyFlyRightWingImageName = L"images/redundancy-fly-rwing.png";

/// The splat image
const std::wstring RedundancyFlySplatImageName = L"images/redundancy-fly-splat.png";

/// Wing flapping period in seconds
const double WingPeriod = 0.2;

/// Starting mRotation angle for wings in radians
const double WingRotateStart = 0.0;

/// End mRotation angle for wings in radians
const double WingRotateEnd = 1.5;

/// How many sets of wings does this bug have?
const int NumberOfSetsOfWings = 4;

/// Number of virtual pixels between each of the wing sets
const int WingSetXOffset = 12;

/// X position relative to center of bug for the first (back) wing set
const int FirstWingSetX = -36;

/// Y position relative to center of bug for the right wings. The negative
/// of this is the Y position for the left wings.
const int WingSetY = 5;

/// Number of sprite images
const int RedundancyNumSpriteImages = 1;

/// The range of the program to consider at it
const double ProgramRange = 50;

/**
 * RedundancySplitBug Constructor
 * @param game Game this bug is a member of
 */
RedundancySplitBug::RedundancySplitBug(Game *game) : RedundancyBug(game, nullptr, nullptr)
{

}


void RedundancySplitBug::ClickedOn()
{
        SetSplat();
        auto scoreboard = GetGame()->GetScoreboard();
        scoreboard->IncFixed();
}
