/**
 * @file FeatureVisitor.cpp
 * @author Aman Todi
 */

#include "pch.h"
#include "FeatureVisitor.h"

/**
 * Visit a Feature bug
 * @param bug The bug being visited
 */
void FeatureVisitor::VisitFeatureBug(FeatureBug* bug)
{
	mFeatureBugs.push_back(bug);
	mProgram = bug->GetProgram();
}

std::vector<FeatureBug*> FeatureVisitor::FetchFeatureBugs()
{
	return mFeatureBugs;
}


shared_ptr<Item> FeatureVisitor::FetchProgram()
{
	return mProgram;
}