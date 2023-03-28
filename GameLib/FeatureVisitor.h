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
/**
 * Vist all the Feature bugs and see if the program is associated with it
 */
class FeatureVisitor : public ItemsVisitor
{
private:
	/// All the bug that the virus hits
	std::vector<FeatureBug*> mFeatureBugs;
	/// The program that the virus is assocated with
	shared_ptr<Item> mProgram;

public:
	virtual void VisitFeatureBug(FeatureBug* bug) override;

	std::vector<FeatureBug*> FetchFeatureBugs();

	shared_ptr<Item> FetchProgram();
};

#endif //PROJECT1_GAMELIB_FEATUREVISITOR_H
