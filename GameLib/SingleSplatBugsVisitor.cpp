/**
 * @file SingleSplatBugsVisitor.cpp
 * @author Aman Todi
 */

#include "pch.h"
#include "SingleSplatBugsVisitor.h"
#include "GarbageBug.h"
#include "NullBug.h"
#include "FeatureBug.h"

SingleSplatBugsVisitor::SingleSplatBugsVisitor(std::shared_ptr<Item> bug)
{
	mBug = bug;
}

void SingleSplatBugsVisitor::VisitGarbageBug(GarbageBug* bug)
{
	if (bug == mBug.get()){
		bug->SetSpeed(0,0);
		bug->SetSplat();
	}
}

void SingleSplatBugsVisitor::VisitNullBug(NullBug* bug)
{
	if (bug == mBug.get()){
		bug->SetSpeed(0,0);
		bug->SetSplat();
	}
}

void SingleSplatBugsVisitor::VisitFeatureBug(FeatureBug* bug)
{
	if (bug == mBug.get()){
		bug->SetSpeed(0,0);
		bug->SetSplat();
	}
}

void SingleSplatBugsVisitor::VisitRedundancyBug(RedundancyBug* bug)
{
	// find a way to make bug split into multiple tiny ones and call splat on all
	// may need to make the tiny bugs derived and add the new bugs to be visited by this visitor
}