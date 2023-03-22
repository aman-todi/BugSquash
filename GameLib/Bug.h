/**
 * @file Bug.h
 * @author sriram
 *
 *
 */

#ifndef GAME_GAME_GAMELIB_BUG_H
#define GAME_GAME_GAMELIB_BUG_H

#include "Item.h"
#include "Code.h"

class Game;
/**
 * Base Class for Bug
 */
class Bug : public Item {
private:
    /// Bug speed
    /// in pixels per second
    double mSpeed = 0;

	///X location of program associated with bug
	double mProgramX = 0;

	///Y location of program associated with bug
	double mProgramY = 0;

	///Angle to rotate
	double mAngleToRotate = 0;

    /// Has the bug been clicked on
    bool mSplat = false;

	///start time
	double mStartTime = 0;

	/// The current string value of the code
	std::string mCodeData;

	/// The Solution (Loaded via XML)
	std::string mSolution;

	///checks if this bug is fatbug
	bool mFatbug = false;
public:
    /// Default constructor (disabled)
    Bug() = delete;

    /// Copy constructor (disabled)
    Bug(const Bug &) = delete;

	/**
	 * Calculate the speed of the bug
	 * @return the speed of the bug
	 */
	double GetSpeed(){return mSpeed;}

	/**
	 * Get the start time for the bug
	 * @return the time the bug starts
	 */
	double GetStartTime(){return mStartTime;}
	/**
 	 * Set the speed of the bug
 	 * @param speed The speed of bug in X and Y directions
 	 */
	virtual void SetSpeed(double speed) { mSpeed=speed; }

    /// Assignment operator
    void operator=(const Game &) = delete;

	 /**
	  * getter for program x location
	  * @return
	  */
	 virtual double GetProgramX(){return mProgramX;}

	 /**
	  * getter for program y location
	  * @return
	  */
	 virtual double GetProgramY(){return mProgramY;}

	/**
	 * getter for angle to rotate
	 * @return angle to rotate the image
	 */
	virtual double GetAngleToRotate(){return mAngleToRotate;}

	/**
	 *  Check to see if code it associated with it
	 * @return True if code it associated else false
	 */
	virtual bool IsFatbug() override{return mFatbug;}


	virtual bool HitTest(int x, int y) override;

	virtual void Update(double elapsed) override;

	/**
	 * Get if the bug has been splat or not
	 * @return If the bug has been splat or not
	 */
    bool GetSplat() {return mSplat;}

	/**
	 * Set if the bug has been clicked on
	 */
    void SetSplat() {mSplat = true;}

    bool AtProgram() override;

    void MissProgram();

	/**
	 * Accept a visitor
	 * @param visitor The visitor we accept
	 */
	virtual void Accept(ItemsVisitor* visitor) {};

	/**
	 * Gets the code for Fat Bug
	 * @return the code for Fat Bug
	 */
	std::string GetCode() override{return mCodeData;}

	/**
	 * Get the solution to the fat bug
	 * @return The solution to the Fat Bug
	 */
	std::string GetSol() {return mSolution;}

protected:

	Bug(Game* game,wxXmlNode* program,wxXmlNode* bug,const std::wstring &filename);
};

#endif //GAME_GAME_GAMELIB_BUG_H
