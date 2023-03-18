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
	/// array to hold individual frames of the animation
	std::vector<std::shared_ptr<wxImage>> mSpriteSheetFrames;

	/// index of the current frame to draw
	int mCurrentFrameIndex = 0;


	/// The bitmap we can display for this Bug splash
	std::shared_ptr<wxBitmap> mBugSplatBitmap;

	/// Has the bug been clicked on
	bool mSplat = false;

	/// Bool helper to slow down moving through the sprite
	bool mSpriteShift = false;

public:
	/// Default constructor (disabled)
	NullBug() = delete;

	/// Copy constructor (disabled)
	NullBug(const NullBug &) = delete;

	/// Assignment operator
	void operator=(const NullBug &) = delete;

	NullBug(Game *game);

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	//void OnTimer(wxTimerEvent &event);

	void UpdateFrame();

	/**
 	 * Set the bug to splat
 	 */
	void ClickedOn() override { mSplat=true; }

	/**
	* Accept a visitor
	* @param visitor The visitor we accept
	*/
	virtual void Accept(ItemsVisitor* visitor) override { visitor->VisitNullBug(this); }

};

#endif //GAME_GAME_GAMELIB_NULLBUG_H
