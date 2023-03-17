/**
 * @file Bug.h
 * @author sriram
 *
 *
 */

#ifndef GAME_GAME_GAMELIB_BUG_H
#define GAME_GAME_GAMELIB_BUG_H

#include "Item.h"


class Game;
/**
 * Base Class for Bug
 */
class Bug : public Item {
private:
    /// Bug speed
    /// in pixels per second
    double mSpeed = 0;


	double mAngleToRotate = 0;


public:
    /// Default constructor (disabled)
    Bug() = delete;

    /// Copy constructor (disabled)
    Bug(const Bug &) = delete;

	/**
	 * Calculate the speed of the bug
	 * @return the speed of the bug
	 */
	double GetSpeed(){return sqrt(mSpeed);}

	/**
 	 * Set the speed of the bug
 	 * @param speedX, speedY speed of bug in X and Y directions
 	 */
	virtual void SetSpeed(double speed){ mSpeed=speed; }

    /// Assignment operator
    void operator=(const Game &) = delete;

	/**
	 * Draw this item
	 * @param dc Device context to draw on
	 */
	//virtual void Draw(wxDC *dc){}
	//virtual void Draw(wxDC *dc);

    // not sure if either of these did anything

	//virtual void XmlLoad(wxXmlNode *node);

	virtual bool HitTest(int x, int y) override;


	virtual void Update(double elapsed) override;
	// I think this should be virtual - aman
    //made not virtual, not sure if it did anything
	double GetAngleToRotate(){return mAngleToRotate;}

protected:
	Bug(Game* game,const std::wstring &filename);

};

#endif //GAME_GAME_GAMELIB_BUG_H
