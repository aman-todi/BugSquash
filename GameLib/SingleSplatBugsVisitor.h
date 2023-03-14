/**
 * @file SingleSplatBugsVisitor.h
 * @author Aman Todi
 *
 *
 */

#ifndef PROJECT1_GAMELIB_SINGLESPLATBUGSVISITOR_H
#define PROJECT1_GAMELIB_SINGLESPLATBUGSVISITOR_H

#include "ItemsVisitor.h"

class SingleSplatBugsVisitor : public ItemsVisitor
{
private:

public:
	/**
	 * Visit a Garbage bug
	 * @param bug
	 */
	virtual void VisitGarbageBug(GarbageBug* bug) override;

	/**
	 * Visit a Null bug
	 * @param bug
	 */
	virtual void VisitNullBug(NullBug* bug) override;

	/**
	 * Visit a Feature bug
	 * @param bug
	 */
	virtual void VisitFeatureBug(FeatureBug* bug) override;

	/**
	 * Visit a Redundancy bug
	 * @param bug
	 */
	 virtual void VisitRedundancyBug(RedundancyBug* bug) override;

};

#endif //PROJECT1_GAMELIB_SINGLESPLATBUGSVISITOR_H
