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
	/// array to hold individual frames of the animation
	std::vector<std::unique_ptr<wxBitmap>> mSpriteSheetFrames;

	/// index of the current frame to draw
	int mCurrentFrameIndex = 0;

	/// The bitmap we can display for this Bug
	std::unique_ptr<wxBitmap> mBugBitmap;

	/// The bitmap we can display for this Bug splash
	std::unique_ptr<wxBitmap> mBugSplatBitmap;

	/// Has the bug been clicked on
	bool mSplat = false;

	wxTimer mTimer;
public:
	/// Default constructor (disabled)
	GarbageBug() = delete;

	/// Copy constructor (disabled)
	GarbageBug(const GarbageBug &) = delete;

	/// Assignment operator
	void operator=(const GarbageBug &) = delete;

	GarbageBug(Game *game);

	virtual void Draw(wxDC* dc) override;

	void UpdateFrame();

	void OnTimer(wxTimerEvent &event);

	/**
	* Accept a visitor
	* @param visitor The visitor we accept
	*/
	virtual void Accept(ItemsVisitor* visitor) override { visitor->VisitGarbageBug(this); }

};

#endif //GAME_GAME_GAMELIB_GARBAGEBUG_H
