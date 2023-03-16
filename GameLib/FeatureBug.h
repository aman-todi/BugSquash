/**
 * @file FeatureBug.h
 * @author srira
 *
 *
 */

#ifndef GAME_GAME_GAMELIB_FEATUREBUG_H
#define GAME_GAME_GAMELIB_FEATUREBUG_H

#include "Bug.h"
#include "Game.h"

/**
 * Class for a bug type FeatureBug
 */
class FeatureBug: public Bug
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
	FeatureBug() = delete;

	/// Copy constructor (disabled)
	FeatureBug(const FeatureBug &) = delete;

	/// Assignment operator
	void operator=(const FeatureBug &) = delete;

	FeatureBug(Game *game);

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	void OnTimer(wxTimerEvent &event);

	void UpdateFrame();

	/**
 	 * Set the bug to splat
	 */
	void ClickedOn() override { mSplat=true; }

	/**
	* Accept a visitor
	* @param visitor The visitor we accept
	*/
	virtual void Accept(ItemsVisitor* visitor) override { visitor->VisitFeatureBug(this); }

};

#endif //GAME_GAME_GAMELIB_FEATUREBUG_H
