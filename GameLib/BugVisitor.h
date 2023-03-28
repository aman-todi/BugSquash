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
class RedundancySplitBug;
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

	///program, bug associated with
	std::shared_ptr<Item> mProgram;

    /// Bugs old speed before set to 0
    double mOldSpeed = 0;

	/// A pointer to the bug
	Bug* mBug = nullptr;

    /// Name of bug visited.
    std::string visited = "none";

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
	 * Grabs the program
	 * @return The program
	 */
	std::shared_ptr<Item> GetProgram(){return mProgram;}

    /**
	* getter for mOldSpeed
	* @return solution
	*/
    double GetOldSpeed(){return mOldSpeed;}


	/**
	 * sets the mSplat for bug
	 */
	void SetSplat(){mBug->SetSplat();}


    /**
	* getter for visited
	* @return string of bug visited
	*/
    std::string GetBugType(){return visited;}

	void VisitGarbageBug(GarbageBug* bug) override;


	void VisitNullBug(NullBug* bug) override;


	void VisitRedundancyBug (RedundancyBug* bug) override;


	void VisitFeatureBug (FeatureBug* bug) override ;

    void VisitRedundancySplitBug (RedundancySplitBug* bug) override;

};

#endif //PROJECT1_GAMELIB_BUGVISITOR_H
