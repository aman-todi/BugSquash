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

	/**
	 * visit garbage bug
	 * @param bug garbage bug
	 */
	void VisitGarbageBug(GarbageBug* bug) override;

	/**
	 * visit null bug
	 * @param bug null bug
	 */
	void VisitNullBug(NullBug* bug) override;

	/**
	 * Visit redundancy bug
	 * @param bug redundancy bug in question
	 */
	void VisitRedundancyBug (RedundancyBug* bug) override;

	/**
	 * Vist Feature bug
	 * @param bug feature bug in question
	 */
	void VisitFeatureBug (FeatureBug* bug) override ;

	/**
	 * Visit a Spider bug
	 * @param bug  The bug being checked
	 */
	void VisitSpider (Spider* bug) override ;

};

#endif //PROJECT1_GAMELIB_LIVINGBUGSCOUNTER_H
