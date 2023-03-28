/**
 * @file BugVisitor.cpp
 * @author srira
 */

#include "pch.h"
#include "BugVisitor.h"
#include "GarbageBug.h"
#include "NullBug.h"
#include "RedundancyBug.h"
#include "RedundancySplitBug.h"
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
	mProgram = bug->GetProgram();
	if (mIsFatbug)
	{
		mCodeData = bug->GetCode();
		mSolution = bug->GetSol();
	}
    mIsRedundancy = false;
}

/**
 * Visit a Null bug
 * @param bug
 */
void BugVisitor::VisitNullBug(NullBug* bug)
{
	mIsFatbug = bug->IsFatbug();
	mBug = bug;
	mProgram = bug->GetProgram();
	if (mIsFatbug)
	{
		mCodeData = bug->GetCode();
		mSolution = bug->GetSol();
	}
    mIsRedundancy = false;
}

/**
 * Visit a Redundancy bug
 * @param bug
 */
void BugVisitor::VisitRedundancyBug(RedundancyBug* bug)
{
	mIsFatbug = bug->IsFatbug();
	mBug = bug;
	mProgram = bug->GetProgram();
	if (mIsFatbug)
	{
		mCodeData = bug->GetCode();
		mSolution = bug->GetSol();
	}
    mIsRedundancy = true;
    mOldSpeed = bug->GetOldSpeed();
}

/**
 * Visit a Feature bug
 * @param bug
 */
void BugVisitor::VisitFeatureBug(FeatureBug* bug)
{
	mIsFatbug = bug->IsFatbug();
	mBug = bug;
	mProgram = bug->GetProgram();
	if (mIsFatbug)

	{
		mCodeData = bug->GetCode();
		mSolution = bug->GetSol();
	}
    mIsRedundancy = false;
}

/**
 * Visit a Split Redundancy Bug
 * @param bug
 */
void BugVisitor::VisitRedundancySplitBug(RedundancySplitBug* bug)
{
    mIsRedundancy = false;
}