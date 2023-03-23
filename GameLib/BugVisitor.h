/**
 * @file BugVisitor.h
 * @author srira
 *
 *
 */

#ifndef PROJECT1_GAMELIB_BUGVISITOR_H
#define PROJECT1_GAMELIB_BUGVISITOR_H

#include "ItemsVisitor.h"
#include "Bug.h"

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
	std::wstring mCodeData;

	/// The Solution (Loaded via XML)
	std::wstring mSolution;

    /// Program X location
    double mProgX = 0 ;

    /// Program Y location
    double mProgY = 0;

    /// Bugs old speed before set to 0
    double mOldSpeed = 0;

	/// A pointer to the bug
	Bug* mBug = nullptr;

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
	 std::wstring GetCode(){return mCodeData;}

	/**
	* getter for solution
	* @return solution
	*/
	std::wstring GetSolution(){return mSolution;}

    /**
	* getter for mprogX
	* @return solution
	*/
    double GetProgX(){return mProgX;}

    /**
	* getter for mprogY
	* @return solution
	*/
    double GetProgY(){return mProgY;}

    /**
	* getter for mOldSpeed
	* @return solution
	*/
    double GetOldSpeed(){return mOldSpeed;}


	/**
	 * sets the mSplat for bug
	 */
	void SetSplat(){mBug->SetSplat();}

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
