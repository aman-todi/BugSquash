/**
 * @file FeatureVisitor.h
 * @author Aman Todi
 *
 *
 */

#ifndef PROJECT1_GAMELIB_FEATUREVISITOR_H
#define PROJECT1_GAMELIB_FEATUREVISITOR_H

#include "ItemsVisitor.h"
#include "FeatureBug.h"
#include "Program.h"

class FeatureVisitor : public ItemsVisitor
{
private:
	std::vector<FeatureBug*> mFeatureBugs;
	shared_ptr<Item> mProgram;

public:
	virtual void VisitFeatureBug(FeatureBug* bug) override;

	std::vector<FeatureBug*> FetchFeatureBugs();

	shared_ptr<Item> FetchProgram();
};

#endif //PROJECT1_GAMELIB_FEATUREVISITOR_H
