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
class Spider;


class BugVisitor :public ItemsVisitor
{
private:

	///checks if bug is fatbug
	bool mIsFatbug = false;

	/// The current string value of the code
	std::string mCodeData;

	/// The Solution (Loaded via XML)
	std::string mSolution;

public:

	///getter for bool
	bool Fatbug(){return mIsFatbug;}

	/**
	 * getter for code
	 * @return code
	 */
	 std::string GetCode(){return mCodeData;}

	/**
	* getter for solution
	* @return solution
	*/
	std::string GetSolution(){return mSolution;}

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

	/**
	 * visit spider
	 */
	void VisitSpider (Spider* bug) override ;
};

#endif //PROJECT1_GAMELIB_BUGVISITOR_H
