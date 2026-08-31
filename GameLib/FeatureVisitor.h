/**
 * @file FeatureVisitor.h
 * @author Aman Todi
 *
 *
 */

#ifndef BUGSQUASH_GAMELIB_FEATUREVISITOR_H
#define BUGSQUASH_GAMELIB_FEATUREVISITOR_H

#include "ItemsVisitor.h"
#include "FeatureBug.h"
#include "Program.h"
/**
 * Visit all the Feature bugs and see if the program is associated with it
 */
class FeatureVisitor : public ItemsVisitor
{
private:
	/// All the bug that the virus hits
	std::vector<FeatureBug*> mFeatureBugs;
	/// The program that the virus is associated with
	std::shared_ptr<Item> mProgram;

public:
	virtual void VisitFeatureBug(FeatureBug* bug) override;

	std::vector<FeatureBug*> FetchFeatureBugs();

	std::shared_ptr<Item> FetchProgram();
};

#endif //BUGSQUASH_GAMELIB_FEATUREVISITOR_H
