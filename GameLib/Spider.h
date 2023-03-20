/**
 * @file Spider.h
 * @author Aman Todi
 *
 *
 */

#ifndef PROJECT1_GAMELIB_SPIDER_H
#define PROJECT1_GAMELIB_SPIDER_H

#include "Bug.h"
#include "Game.h"

/**
 * Class for a bug type FeatureBug
 */
class Spider: public Bug
{
private:
	/// array to hold individual frames of the animation
	std::vector<std::shared_ptr<wxImage>> mSpriteSheetFrames;

	/// index of the current frame to draw
	int mCurrentFrameIndex = 0;

public:
	/// Default constructor (disabled)
	Spider() = delete;

	/// Copy constructor (disabled)
	Spider(const Spider &) = delete;

	/// Assignment operator
	void operator=(const Spider &) = delete;

	Spider(Game *game);

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	void UpdateFrame();

};


#endif //PROJECT1_GAMELIB_SPIDER_H
