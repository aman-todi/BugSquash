/**
 * @file BugVisitor.h
 * @author srira
 *
 *
 */

#ifndef PROJECT1_GAMELIB_BUGVISITOR_H
#define PROJECT1_GAMELIB_BUGVISITOR_H

#include "ItemsVisitor.h"

class GarbageBug;
class FeatureBug;
class NullBug;
class RedundancyBug;
class SpiderBug;


class BugVisitor :public ItemsVisitor
{
private:

	///
	bool mIsFatbug = false;

public:

	///getter for bool
	bool Fatbug(){return mIsFatbug;}

	/**
	 * Visit a Garbage bug
	 * @param bug
	 */
	void VisitGarbageBug(GarbageBug* bug) override;

	/**
	 * Visit a Null bug
	 * @param bug
	 */
	void VisitNullBug(NullBug* bug) override;

	/**
	 * Visit a Redundancy bug
	 * @param bug
	 */
	void VisitRedundancyBug (RedundancyBug* bug) override;

	/**
	 * Visit a Feature bug
	 * @param bug
	 */
	void VisitFeatureBug (FeatureBug* bug) override ;



};

#endif //PROJECT1_GAMELIB_BUGVISITOR_H
