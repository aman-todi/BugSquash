/**
 * @file NullBug.h
 * @author srira
 *
 *
 */

#ifndef GAME_GAME_GAMELIB_NULLBUG_H
#define GAME_GAME_GAMELIB_NULLBUG_H

#include "Bug.h"
#include "Game.h"
/**
 * Class for a bug type NullBug
 */
class NullBug: public Bug
{
private:
	///bitmap information
	std::vector<std::pair<wxString, std::shared_ptr<wxBitmap>>> mBitmaps;

	/// index of the current frame to draw
	int mCurrentFrameIndex = 0;

public:
	/// Default constructor (disabled)
	NullBug() = delete;

	/// Copy constructor (disabled)
	NullBug(const NullBug &) = delete;

	/// Assignment operator
	void operator=(const NullBug &) = delete;

	NullBug(Game *game,std::shared_ptr<Item> program,wxXmlNode* bug);

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, double timeInSec) override;

	void UpdateFrame(double timeInSec);

	void ClickedOn() override;

	/**
	* Accept a visitor
	* @param visitor The visitor we accept
	*/
	virtual void Accept(ItemsVisitor* visitor) override { visitor->VisitNullBug(this); }
};

#endif //GAME_GAME_GAMELIB_NULLBUG_H
