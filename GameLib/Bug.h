/**
 * @file Bug.h
 * @author sriram
 *
 *
 */

#ifndef GAME_GAME_GAMELIB_BUG_H
#define GAME_GAME_GAMELIB_BUG_H

#include "Item.h"
#include "regex"
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
	std::wstring mCodeData;

	/// The Solution (Loaded via XML)
	std::wstring mSolution;

	///checks if this bug is fatbug
	bool mFatbug = false;

    ///X position to set the bug to
    double bugX = 0;
	///Y position to set the bug to
	double bugY = 0;
public:
    /// Default constructor (disabled)
    Bug() = delete;

    /// Copy constructor (disabled)
    Bug(const Bug &) = delete;

	//void SetProgramLoc(double x, double y){mProgramX=x;mProgramY=y;}
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
	  * Getter for program x location
	  * @return The X location of the program
	  */
	 virtual double GetProgramX(){return mProgramX;}

	 /**
	  * Getter for program y location
	  * @return The Y location of the program
	  */
	 virtual double GetProgramY(){return mProgramY;}

    /**
     * Setter for program x location
     *	@param X The X location of the program
     */
    void SetProgramX(double X){mProgramX = X;}

    /**
     * Setter for program Y location
     * @param Y The Y location of the program
     */
    void SetProgramY(double Y){mProgramY = Y;}

	/**
	 * getter for angle to rotate
	 * @return angle to rotate the image
	 */
	virtual double GetAngleToRotate(){return mAngleToRotate;}

	/**
	 *  Check to see if code it associated with it
	 * @return True if code it associated else false
	 */
	virtual bool IsFatbug() {return mFatbug;}


	virtual bool HitTest(int x, int y) override;

	virtual void Update(double elapsed, double timeInSec) override;

	/**
	 * Get if the bug has been splat or not
	 * @return If the bug has been splat or not
	 */
    bool GetSplat() override {return mSplat;}

	/**
	 * Set if the bug has been clicked on
	 */
    void SetSplat() {mSplat = true;}

    bool AtProgram() override;

	/**
	 * Accept a visitor
	 * @param visitor The visitor we accept
	 */
	virtual void Accept(ItemsVisitor* visitor) override {};

	/**
	 * Gets the code for Fat Bug
	 * @return the code for Fat Bug
	 */
	std::wstring GetCode() {return mCodeData;}

	/**
	 * Get the solution to the fat bug
	 * @return The solution to the Fat Bug
	 */
	std::wstring GetSol() {return mSolution;}

protected:

	Bug(Game* game,wxXmlNode* program,wxXmlNode* bug,const std::wstring &filename);
};

#endif //GAME_GAME_GAMELIB_BUG_H
