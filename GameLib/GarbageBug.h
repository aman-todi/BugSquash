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
	std::vector<std::shared_ptr<wxImage>> mSpriteSheetFrames;

	/// index of the current frame to draw
	int mCurrentFrameIndex = 0;


	/// The bitmap we can display for this Bug splash
	std::shared_ptr<wxBitmap> mBugSplatBitmap;

	/// Has the bug been clicked on
	bool mSplat = false;

public:
	/// Default constructor (disabled)
	GarbageBug() = delete;

	/// Copy constructor (disabled)
	GarbageBug(const GarbageBug &) = delete;

	/// Assignment operator
	void operator=(const GarbageBug &) = delete;

	GarbageBug(Game *game);

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	void UpdateFrame();

	void ClickedOn() override;

	/**
	 * Accept a visitor
	 * @param visitor The visitor we accept
	 */
	virtual void Accept(ItemsVisitor* visitor) override { visitor->VisitGarbageBug(this); }

	bool AtProgram() override;
};

#endif //GAME_GAME_GAMELIB_GARBAGEBUG_H
