/**
 * @file RedundancySplitBug.h
 * @author Blake
 *
 *
 */

#ifndef PROJECT1_REDUNDANCYSPLITBUG_H
#define PROJECT1_REDUNDANCYSPLITBUG_H

#include "Bug.h"
#include "Game.h"
#include "RedundancyBug.h"

class RedundancySplitBug :  public RedundancyBug{
private:
    /// array to hold each part of the bug
    std::vector<std::shared_ptr<wxImage>> mBugPartsSpriteSheet;


    double rotation = 0;

    bool decreasing = false;

	/**
	 * Name of this type of bug
	 * @return The name of this type of bug
	 */
    std::string Name() override {return "RedundancySplit";};


    /// array to hold individual frames of the animation
    std::vector<std::shared_ptr<wxImage>> mSpriteSheetFrames;

    /// index of the current frame to draw
    int mCurrentFrameIndex = 0;


    /// The bitmap we can display for this Bug splash
    std::shared_ptr<wxBitmap> mBugSplatBitmap;

public:

    /// Default constructor (disabled)
    RedundancySplitBug() = delete;

    RedundancySplitBug(Game *game);

    /// Copy constructor (disabled)
    RedundancySplitBug(const RedundancySplitBug &) = delete;

    /// Assignment operator
    void operator=(const RedundancySplitBug &) = delete;

    /**
 	 * Set the bug to splat
	 */
    void ClickedOn() override;


};

#endif //PROJECT1_REDUNDANCYSPLITBUG_H
