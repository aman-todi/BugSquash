/**
 * @file BugScoreboardVisitor.cpp
 * @author Ethan Silver
 */

#include "pch.h"
#include "BugScoreboardVisitor.h"
#include "Scoreboard.h"

void BugScoreboardVisitor::VisitGarbageBug(GarbageBug* bug)
{
    IncMiss();
}

void BugScoreboardVisitor::VisitNullBug(NullBug* bug)
{
    IncMiss();
}

void BugScoreboardVisitor::VisitRedundancyBug(RedundancyBug* bug)
{
    IncMiss();
}

void BugScoreboardVisitor::VisitFeatureBug(FeatureBug* bug)
{
    // Do Nothing
}

void BugScoreboardVisitor::VisitSpider(Spider* bug)
{
    IncMiss();
}

void BugScoreboardVisitor::IncMiss()
{
    mScoreboard->IncMissed();
}
