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
    std::shared_ptr<wxImage> mLaptopImage;

    /// Laptop Bitmap
    wxGraphicsBitmap mLaptopBitmap;

	///program name
	wxString mNameString;
public:

	Program(Game* game,wxXmlNode* program);

	/**
	 * Accept a visitor
	 * @param visitor The visitor we accept
	 */
	virtual void Accept(ItemsVisitor* visitor) override { visitor->VisitProgram(this); }

    /**
     * Draw program
     * @param gc
     * @param timeInSec how long the game has been running for
     */
	void Draw(std::shared_ptr<wxGraphicsContext> gc, double timeInSec) override;


    //virtual bool HitTest(int x, int y) override;

	/**
	 * Sets the name of the progrma
	 * @param name The name of the program
	 */
	void SetName(std::string name)  {mNameString=name;}
};

#endif //GAME_GAMELIB_PROGRAM_H
