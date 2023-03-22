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
/**
 * Visits all the bugs and checks if it is a FatBug
 */
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

	/**
	 * Get if it is a fat bug
	 * @return True if Fatbug, else false
	 */
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

	void VisitGarbageBug(GarbageBug* bug) override;


	void VisitNullBug(NullBug* bug) override;


	void VisitRedundancyBug (RedundancyBug* bug) override;


	void VisitFeatureBug (FeatureBug* bug) override ;

	/**
	 * Visit a Spider bug
	 * @param bug  The bug being checked
	 */
	void VisitSpider (Spider* bug) override ;
};

#endif //PROJECT1_GAMELIB_BUGVISITOR_H
