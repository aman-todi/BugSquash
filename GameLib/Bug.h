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

	///code associated with this bug
	std::shared_ptr<Code> mCode=nullptr;

    /// Has the bug been clicked on
    bool mSplat = false;

	///start time

	double mStartTime = 0;
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
 	 * Set the speed of the bug
 	 * @param speedX, speedY speed of bug in X and Y directions
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
	 * checks if bug has code associated with it
	 */
	virtual bool IsFatbug(){return mCode!=nullptr;}

	virtual std::wstring GetCode() override {return mCode->GetCode();}

	virtual bool HitTest(int x, int y) override;

	virtual void Update(double elapsed) override;

	virtual void SetCode(std::wstring codeData, std::wstring solData);


    bool GetSplat() {return mSplat;}

    void SetSplat() {mSplat = true;}

    bool AtProgram() override;

    void MissProgram();

protected:

	Bug(Game* game,wxXmlNode* program,wxXmlNode* bug,const std::wstring &filename);
};

#endif //GAME_GAME_GAMELIB_BUG_H
