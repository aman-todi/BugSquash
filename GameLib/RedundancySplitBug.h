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
/**
 * The redundancy bugs that appear from being clicked on
 */
class RedundancySplitBug :  public RedundancyBug {
private:

    /// index of the current frame to draw
    int mCurrentFrameIndex = 0;


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

    /**
	* Accept a visitor
	* @param visitor The visitor we accept
	*/
    virtual void Accept(ItemsVisitor* visitor) override { visitor->VisitRedundancySplitBug(this); }
};

#endif //PROJECT1_REDUNDANCYSPLITBUG_H
