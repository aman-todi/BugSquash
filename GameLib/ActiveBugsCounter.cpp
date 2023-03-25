/**
 * @file ActiveBugsCounter.cpp
 * @author Aman Todi
 */

#include "pch.h"
#include "ActiveBugsCounter.h"
#include "Bug.h"
#include "GarbageBug.h"
#include "NullBug.h"
#include "RedundancyBug.h"
#include "FeatureBug.h"
#include "Spider.h"
#include "ShapeShifterBug.h"

/**
 * visit garbage bug
 * @param bug garbage bug
 */
void ActiveBugsCounter::VisitGarbageBug(GarbageBug* bug)
{
	if (bug->GetSplat() == false) { mCount++; }
}

/**
 * visit null bug
 * @param bug null bug
 */
void ActiveBugsCounter::VisitNullBug(NullBug* bug)
{
	if (bug->GetSplat() == false) { mCount++; }
}

/**
 * Visit redundancy bug
 * @param bug redundancy bug in question
 */
void ActiveBugsCounter::VisitRedundancyBug(RedundancyBug* bug)
{
	if (bug->GetSplat() == false) { mCount++; }
}

/**
 * Vist Feature bug
 * @param bug feature bug in question
 */
void ActiveBugsCounter::VisitFeatureBug(FeatureBug* bug)
{
	if (bug->GetSplat() == false) { mCount++; }
}

/**
 * Visit a Spider bug
 * @param bug  The bug being checked
 */
void ActiveBugsCounter::VisitSpider(Spider* bug)
{
	// Do Nothing
}

/**
 * Visit a ShapeShifterBug
 * @param bug The bug being visited
 */
void ActiveBugsCounter::VisitShapeShifterBug(ShapeShifterBug* bug)
{
	if (bug->GetSplat() == false) { mCount++; }
}

