/**
 * @file GarbageBug.h
 * @author srira
 *
 *
 */

#ifndef GAME_GAME_GAMELIB_GARBAGEBUG_H
#define GAME_GAME_GAMELIB_GARBAGEBUG_H

#include "Bug.h"
#include "Game.h"
/**
 * Class for a bug type GarbageBug
 */
class GarbageBug: public Bug
{
private:
	///bitmap information
	std::vector<std::pair<wxString, std::shared_ptr<wxBitmap>>> mBitmaps;

	/// index of the current frame to draw
	int mCurrentFrameIndex = 0;

public:
	/// Default constructor (disabled)
	GarbageBug() = delete;

	/// Copy constructor (disabled)
	GarbageBug(const GarbageBug &) = delete;

	/// Assignment operator
	void operator=(const GarbageBug &) = delete;

	GarbageBug(Game *game,wxXmlNode* program,wxXmlNode* bug);

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, double timeInSec) override;

	void UpdateFrame(double v);

	void ClickedOn() override;

	/**
	 * Accept a visitor
	 * @param visitor The visitor we accept
	 */
	virtual void Accept(ItemsVisitor* visitor) override { visitor->VisitGarbageBug(this); }
};

#endif //GAME_GAME_GAMELIB_GARBAGEBUG_H
