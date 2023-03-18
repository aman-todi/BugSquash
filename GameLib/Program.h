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

    /// Program Name enum
    enum class Name {BugSquash, Receivables};

    /// Program/Level Name
    Name mName;

	///program name
	std::string mNameString;
public:

    /**
     * Contructor
     * @param game
     */
	Program(Game* game);

	/**
	 * Accept a visitor
	 * @param visitor The visitor we accept
	 */
	virtual void Accept(ItemsVisitor* visitor) override { visitor->VisitProgram(this); }

    /**
     * Draw program
     * @param gc
     */
    void Draw(std::shared_ptr<wxGraphicsContext> gc) override;

    /**
     * HitTest
     * @param x, y (x,y) coords
     */
    virtual bool HitTest(int x, int y) override;

    /**
     * Set level Name
     */
    void SetLevelBugSquash() {mName = Name::BugSquash;}
    void SetLevelReceivables() {mName = Name::Receivables;}

	void SetName(std::string name) override {mNameString=name;}

    std::string GetName() {return mNameString;}
};

#endif //GAME_GAMELIB_PROGRAM_H
