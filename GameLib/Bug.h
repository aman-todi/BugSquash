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
    /// Bug speed in the X direction
    /// in pixels per second
    double mSpeedX = 0;

    /// Bug speed in the Y direction
    /// in pixels per second
    double mSpeedY = 0;

	///angle to rotation
	double angle_rotation = 0;


public:
    /// Default constructor (disabled)
    Bug() = delete;

    /// Copy constructor (disabled)
    Bug(const Bug &) = delete;

	/**
	 * Calculate the speed of the bug
	 * @return the speed of the bug
	 */
	double GetSpeed(){return sqrt(mSpeedX*mSpeedX+mSpeedY*mSpeedY);}

	/**
 	 * Set the speed of the bug
 	 * @param speedX, speedY speed of bug in X and Y directions
 	 */
	void SetSpeed(double speedX, double speedY){ mSpeedX = speedX; mSpeedY = speedY; }

    /// Assignment operator
    void operator=(const Game &) = delete;

	/**
	 * Draw this item
	 * @param dc Device context to draw on
	 */
	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics){}

	double GetAngleToRotate(){return angle_rotation;}
	//virtual void Draw(wxDC *dc);

    // not sure if either of these did anything

	//virtual void XmlLoad(wxXmlNode *node);

//	/**  Test this item to see if it has been clicked on
//    * @param x X location on the city to test
//    * @param y Y location on the city to test
//    * @return true if clicked on */
	//virtual bool HitTest(int x, int y);


	virtual void Update(double elapsed);
	// I think this should be virtual - aman
    //made not virtual, not sure if it did anything

	/**
	 * Accept a visitor
	 * @param visitor The visitor we accept
	 */
	virtual void Accept(ItemsVisitor* visitor) = 0;




protected:
    Bug(Game* game, const std::wstring& filename);

};

#endif //GAME_GAME_GAMELIB_BUG_H
