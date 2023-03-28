	/**
 * @file Program.h
 * @author Aman Todi
 *
 *
 */

#ifndef GAME_GAMELIB_PROGRAM_H
#define GAME_GAMELIB_PROGRAM_H

#include "Item.h"
#include "Game.h"

/**
 * Class for a bug type Program
 */
class Program : public Item
{
private:
    /// The Laptop image
	std::shared_ptr<wxBitmap> mLaptopBitmap;

	///program name
	wxString mNameString;
public:

	Program(Game* game,wxXmlNode* program);

	/**
	 * Accept a visitor
	 * @param visitor The visitor we accept
	 */
	virtual void Accept(ItemsVisitor* visitor) override { visitor->VisitProgram(this); }

	void Draw(std::shared_ptr<wxGraphicsContext> gc, double timeInSec) override;
};

#endif //GAME_GAMELIB_PROGRAM_H
