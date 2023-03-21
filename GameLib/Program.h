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

	Program(Game* game,wxXmlNode* program);

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


    //virtual bool HitTest(int x, int y) override;

    /**
     * Set Program Name
     */
    void SetLevelBugSquash() {mName = Name::BugSquash;}
	/**
	 * Set Program Name
	 */
    void SetLevelReceivables() {mName = Name::Receivables;}
	/**
	 * Sets the name of the progrma
	 * @param name The name of the program
	 */
	void SetName(std::string name) override {mNameString=name;}
	/**
	 * The name of the program
	 * @return The name of the program
	 */
    std::string GetName() {return mNameString;}

};

#endif //GAME_GAMELIB_PROGRAM_H
