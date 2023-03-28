/**
 * @file BugScoreboardVisitor.cpp
 * @author Ethan Silver
 */

#include "pch.h"
#include "BugScoreboardVisitor.h"


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
 * Visit ShapeShifter bug
 * @param bug shape shifter bug in question
 */
void BugScoreboardVisitor::VisitShapeShifterBug (ShapeShifterBug* bug)
{
	// Do something special here
}

/**
 * Set Scoreboard Pointer to Game Scoreboard
 */
void BugScoreboardVisitor::IncMiss()
{
    mScoreboard->IncMissed();
}
