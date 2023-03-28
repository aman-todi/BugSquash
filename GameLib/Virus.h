/**
 * @file Virus.h
 * @author Aman Todi
 *
 *
 */

#ifndef PROJECT1_GAMELIB_VIRUS_H
#define PROJECT1_GAMELIB_VIRUS_H

#include "Bug.h"
#include "Game.h"

/**
 * Class for a bug type Virus
 */
class Virus: public Bug
{
private:
	///bitmap information
	std::vector<std::pair<wxString, std::shared_ptr<wxBitmap>>> mBitmaps;

	/// index of the current frame to draw
	int mCurrentFrameIndex = 0;

	/// speed in x direction
	int mSpeedX = 0;

	/// speed in y direction
	int mSpeedY = 0;

public:
	/// Default constructor (disabled)
	Virus() = delete;

	/// Copy constructor (disabled)
	Virus(const Virus &) = delete;

	/// Assignment operator
	void operator=(const Virus &) = delete;

	Virus(Game *game, std::shared_ptr<Item> program, wxXmlNode* bug);

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, double timeInSec) override;

	void Update(double elapsed, double timeInSec) override;

	void UpdateFrame(double timeInSec);

	/**
     * Accept a visitor for virus
     * @param visitor The visitor we accept
     */
	void Accept(ItemsVisitor* visitor) override { visitor->VisitVirus(this); }

};


#endif //PROJECT1_GAMELIB_VIRUS_H
