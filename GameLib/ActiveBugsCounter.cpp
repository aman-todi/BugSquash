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

void ActiveBugsCounter::VisitGarbageBug(GarbageBug* bug)
{
	if (bug->GetSplat() == false) { mCount++; }
}

void ActiveBugsCounter::VisitNullBug(NullBug* bug)
{
	if (bug->GetSplat() == false) { mCount++; }
}

void ActiveBugsCounter::VisitRedundancyBug(RedundancyBug* bug)
{
	if (bug->GetSplat() == false) { mCount++; }
}

void ActiveBugsCounter::VisitFeatureBug(FeatureBug* bug)
{
	if (bug->GetSplat() == false) { mCount++; }
}

void ActiveBugsCounter::VisitSpider(Spider* bug)
{
	// Do Nothing
}

void ActiveBugsCounter::VisitShapeShifterBug(ShapeShifterBug* bug)
{
	if (bug->GetSplat() == false) { mCount++; }
}

