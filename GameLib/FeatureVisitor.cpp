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

/**
 * All the bugs the at the virus hits
 * @return The vector of feature bug that the virus has hit
 */
std::vector<FeatureBug*> FeatureVisitor::FetchFeatureBugs()
{
	return mFeatureBugs;
}

/**
 * Grabs the bug that the program is doing
 * @return The program that the virus go with
 */
std::shared_ptr<Item> FeatureVisitor::FetchProgram()
{
	return mProgram;
}