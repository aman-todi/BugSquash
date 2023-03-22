/**
 * @file BugVisitor.cpp
 * @author srira
 */

#include "pch.h"
#include "BugVisitor.h"
#include "GarbageBug.h"
#include "NullBug.h"
#include "RedundancyBug.h"
#include "FeatureBug.h"
#include "Spider.h"


/**
 * Visit a Garbage bug
 * @param bug
 */
void BugVisitor::VisitGarbageBug(GarbageBug* bug)
{
	mIsFatbug = bug->IsFatbug();
	mBug = bug;
	if (mIsFatbug)
	{
		mCodeData = bug->GetCode();
		mSolution = bug->GetSol();
	}
}

/**
 * Visit a Null bug
 * @param bug
 */
void BugVisitor::VisitNullBug(NullBug* bug)
{
	mIsFatbug = bug->IsFatbug();
	mBug = bug;
	if (mIsFatbug)
	{
		mCodeData = bug->GetCode();
		mSolution = bug->GetSol();
	}
}

/**
 * Visit a Redundancy bug
 * @param bug
 */
void BugVisitor::VisitRedundancyBug(RedundancyBug* bug)
{
	mIsFatbug = bug->IsFatbug();
	mBug = bug;
	if (mIsFatbug)
	{
		mCodeData = bug->GetCode();
		mSolution = bug->GetSol();
	}
}

/**
 * Visit a Feature bug
 * @param bug
 */
void BugVisitor::VisitFeatureBug(FeatureBug* bug)
{
	mIsFatbug = bug->IsFatbug();
	mBug = bug;
	if (mIsFatbug)

	{
		mCodeData = bug->GetCode();
		mSolution = bug->GetSol();
	}
}
/**
 * Visit a Spider bug
 * @param bug  The bug being checked
 */
void BugVisitor::VisitSpider (Spider* bug)
{
	mIsFatbug = bug->IsFatbug();
	mBug = bug;
	if (mIsFatbug)
	{
		mCodeData = bug->GetCode();
		mSolution = bug->GetSol();
	}
}