/**
 * @file Item.h
 * @author Blake
 *
 *
 */

#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include <memory>
#include "ItemsVisitor.h"

class Game;
/**
 * base class for any item in our Game
 */
class Item {
private:
    /// The game this item is contained in
    Game *mGame = nullptr;


    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item


    bool mMirror = false;   ///< True mirrors the item image

	/// Time variable to help animation
	long mKeepTime = 0;

public:
    virtual ~Item();
    /**
     * The X location of the item
     * @return X location in pixels
     */
    double GetX() const { return mX; }

	/**
	 * Gets the name of the bug
	 * @return
	 */
    virtual std::string Name(){return "none";};

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    void SetLocation(double x, double y) { mX = x; mY = y; }

    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    /// Assignment operator
    void operator=(const Item &) = delete;
	/**
	 * Draw this Item
	 * @param graphics  Device context to draw on
	 * @param timeInSec how long the game has been running for
	 */
	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, double timeInSec) {}

	/**
	 * virtual HitTest always returns false
	 * @param x, y location clicked
	 * @return bool
	 */
    virtual bool HitTest(int x, int y) { return false; };

	/**
 	 * Get item (bitmap) width
 	 * @return width in pixels
 	 */
	//double GetWidth() const {return mItemBitmap->GetWidth(); }

	/**
	 * Get item (bitmap) height
	 * @return height in pixels
	 */
	//double GetHeight() const {return mItemBitmap->GetHeight(); }


	//bool CheckTransparency(double x , double y) { return mItemImage->IsTransparent(int(x), int(y)); }

    //double DistanceTo(std::shared_ptr<Item> item);

	/**
	 * Animation Time Getter
	 * @return time in milliseconds
	 */
	long GetTime() { return mKeepTime; }

	/**
 	 * Reset animation time to 0
 	 */
	void ResetTime() { mKeepTime = 0; }

	/**
     * Add to animation time
     */
	void AddTime() { mKeepTime += 5; }

    /**
     * Handle updates for animation
     * @param elapsed The time since the last update
     * @param timeInSec How long the level has been running for
     */
    virtual void Update(double elapsed, double timeInSec) {}

	/**
	 * Accept a visitor
	 * @param visitor The visitor we accept
	 */
	virtual void Accept(ItemsVisitor* visitor) = 0;

    /**
     * Get the pointer to the Game object
     * @return Pointer to Game object
     */
    Game *GetGame() { return mGame; }

	/// Register if the bug has been clicked on
	virtual void ClickedOn(){};

	/**
	 * Checks to see if the bug has reached the program
	 * @return false
	 */
	virtual bool AtProgram(){return false;};
	/**
	 * Check to see if the bug has been click on
	 * @return false
	 */
	virtual bool GetSplat() {return false;}


protected:
    Item(Game *game);

};

#endif //GAME_ITEM_H
