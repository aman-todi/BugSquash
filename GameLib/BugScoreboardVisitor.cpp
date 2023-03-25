/**
 * @file BugScoreboardVisitor.cpp
 * @author Ethan Silver
 */

#include "pch.h"
#include "BugScoreboardVisitor.h"
#include "Scoreboard.h"

/**
 * visit garbage bug
 * @param bug garbage bug
 */
void BugScoreboardVisitor::VisitGarbageBug(GarbageBug* bug)
{
    IncMiss();
}

/**
 * visit null bug
 * @param bug null bug
 */
void BugScoreboardVisitor::VisitNullBug(NullBug* bug)
{
    IncMiss();
}

/**
 * Visit redundancy bug
 * @param bug redundancy bug in question
 */
void BugScoreboardVisitor::VisitRedundancyBug(RedundancyBug* bug)
{
    IncMiss();
}

/**
 * Vist Feature bug
 * @param bug feature bug in question
 */
void BugScoreboardVisitor::VisitFeatureBug(FeatureBug* bug)
{
    // Do Nothing
}

/**
 * Set Scoreboard Pointer to Game Scoreboard
 * @param sb
 */
void BugScoreboardVisitor::IncMiss()
{
    mScoreboard->IncMissed();
}
