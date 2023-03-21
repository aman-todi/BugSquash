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
    /// array to hold each part of the bug
    std::vector<std::shared_ptr<wxImage>> mBugPartsSpriteSheet;

    double rotation = 0;
    bool decreasing = false;


	/// array to hold individual frames of the animation
	std::vector<std::shared_ptr<wxImage>> mSpriteSheetFrames;

	/// index of the current frame to draw
	int mCurrentFrameIndex = 0;


	/// The bitmap we can display for this Bug splash
	std::shared_ptr<wxBitmap> mBugSplatBitmap;


public:

	/// Default constructor (disabled)
	RedundancyBug() = delete;

	/// Copy constructor (disabled)
	RedundancyBug(const RedundancyBug &) = delete;

	/// Assignment operator
	void operator=(const RedundancyBug &) = delete;

    RedundancyBug(Game *game,wxXmlNode* program,wxXmlNode* bug);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void OnTimer(wxTimerEvent &event);

    void UpdateFrame(std::shared_ptr<wxGraphicsContext> gc, bool isLeft);

    /**
 	 * Set the bug to splat
	 */
    void ClickedOn() override;

	/**
	* Accept a visitor
	* @param visitor The visitor we accept
	*/
	virtual void Accept(ItemsVisitor* visitor) override { visitor->VisitRedundancyBug(this); }
};

#endif //GAME_GAME_GAMELIB_REDUNDANCYBUG_H
