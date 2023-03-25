/**
 * @file ShapeShifterBug.h
 * @author Aman Todi
 *
 *
 */

#ifndef PROJECT1_GAMELIB_SHAPESHIFTERBUG_H
#define PROJECT1_GAMELIB_SHAPESHIFTERBUG_H

#include "Bug.h"
#include "Game.h"

/**
 *  class for ShapeShifterBug
 */
class ShapeShifterBug : public Bug
{
private:
	/// array to hold individual frames of the animation
	std::vector<std::shared_ptr<wxImage>> mSpriteSheetFrames;

	/// index of the current frame to draw
	int mCurrentFrameIndex = 0;


	/// The bitmap we can display for this Bug splash
	std::shared_ptr<wxBitmap> mBugSplatBitmap;

public:
	/// Default constructor (disabled)
	ShapeShifterBug() = delete;

	/// Copy constructor (disabled)
	ShapeShifterBug(const ShapeShifterBug &) = delete;

	/// Assignment operator
	void operator=(const ShapeShifterBug &) = delete;

	ShapeShifterBug(Game *game,wxXmlNode* program,wxXmlNode* bug);

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, double timeInSec) override;

	void UpdateFrame(double v);

	void ClickedOn() override;

	/**
	 * Accept a visitor
	 * @param visitor The visitor we accept
	 */
	virtual void Accept(ItemsVisitor* visitor) override { visitor->VisitShapeShifterBug(this); }
};

#endif //PROJECT1_GAMELIB_SHAPESHIFTERBUG_H
