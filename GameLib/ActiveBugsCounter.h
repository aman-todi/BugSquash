/**
 * @file ActiveBugsCounter.h
 * @author Aman Todi
 *
 *
 */

#ifndef PROJECT1_GAMELIB_LIVINGBUGSCOUNTER_H
#define PROJECT1_GAMELIB_LIVINGBUGSCOUNTER_H

#include <memory>

#include "ItemsVisitor.h"
#include "Bug.h"

class GarbageBug;
class FeatureBug;
class NullBug;
class RedundancyBug;
/**
 * `Sees how many bugs there are left in the game
 */
class ActiveBugsCounter : public ItemsVisitor {
private:
	/// Count the number of living bugs on the screen
	int mCount = 0;

public:

	/**
	 * Get the count of active bugs
	 * @return The number of bugs left
	 */
	int GetActiveBugs() { return mCount; }

	void VisitGarbageBug(GarbageBug* bug) override;

	void VisitNullBug(NullBug* bug) override;

	void VisitRedundancyBug (RedundancyBug* bug) override;

	void VisitFeatureBug (FeatureBug* bug) override ;

	void VisitSpider (Spider* bug) override ;

	virtual void VisitShapeShifterBug (ShapeShifterBug* bug) override;

};

#endif //PROJECT1_GAMELIB_LIVINGBUGSCOUNTER_H
