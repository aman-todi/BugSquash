/**
 * @file RedundancyBug.h
 * @author srira
 *
 *
 */

#ifndef GAME_GAME_GAMELIB_REDUNDANCYBUG_H
#define GAME_GAME_GAMELIB_REDUNDANCYBUG_H

#include "Bug.h"
#include "Game.h"
/**
 * Class for a bug type RedundancyBug
 */
class RedundancyBug: public Bug
{
private:
	///bitmap information
	std::vector<std::pair<wxString, std::shared_ptr<wxBitmap>>> mBitmaps;

    /// Angle currently rotating at
    double mRotation = 0;
    /// Bool if the wings are decreasing or increasing in angle
    bool mDecreasing = false;
    /// Speed of bug before being set to 0
    double mOldSpeed = 0;



	/// index of the current frame to draw
	int mCurrentFrameIndex = 0;

public:


	/// Default constructor (disabled)
	RedundancyBug() = delete;

	/// Copy constructor (disabled)
	RedundancyBug(const RedundancyBug &) = delete;

	/// Assignment operator
	void operator=(const RedundancyBug &) = delete;

    RedundancyBug(Game *game,std::shared_ptr<Item> program,wxXmlNode* bug);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, double timeInSec) override;

    //void OnTimer(wxTimerEvent &event);

    void UpdateFrame(std::shared_ptr<wxGraphicsContext> gc);

    /**
 	 * Set the bug to splat
	 */
    void ClickedOn() override;

	/**
	* Accept a visitor
	* @param visitor The visitor we accept
	*/
	virtual void Accept(ItemsVisitor* visitor) override { visitor->VisitRedundancyBug(this); }

    /**
	* Getter for the old speed
	* @return mOldSpeed The original speed
	*/
    double GetOldSpeed(){return mOldSpeed;}
};

#endif //GAME_GAME_GAMELIB_REDUNDANCYBUG_H
