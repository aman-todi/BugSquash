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

class GarbageBug: public Bug
{
private:
//	/// Width of the sprite image
//	int mWidth = 0;
//
//	/// Height of the sprite image
//	int mHeight = 0;


	/// array to hold individual frames of the animation
	std::vector<wxGraphicsBitmap> mSpriteSheetFrames;

	/// index of the current frame to draw
	int mCurrentFrameIndex;

	/// The bitmap we can display for this Bug
	std::unique_ptr<wxBitmap> mBugBitmap;

	/// The bitmap we can display for this Bug splash
	std::unique_ptr<wxBitmap> mBugSplatBitmap;

	bool splat = false;

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
	void OnTimer(wxTimerEvent &event);

};

#endif //GAME_GAME_GAMELIB_GARBAGEBUG_H
