/**
 * @file RedundancySplitBug.h
 * @author Blake
 *
 *
 */

#ifndef BUGSQUASH_REDUNDANCYSPLITBUG_H
#define BUGSQUASH_REDUNDANCYSPLITBUG_H

#include "Bug.h"
#include "Game.h"
#include "RedundancyBug.h"
/**
 * The redundancy bugs that appear from being clicked on
 */
class RedundancySplitBug :  public RedundancyBug {
private:

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

#endif //BUGSQUASH_REDUNDANCYSPLITBUG_H
