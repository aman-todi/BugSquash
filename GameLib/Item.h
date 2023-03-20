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

    // Item location in the game
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

    /// The underlying bug image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this bug
    std::unique_ptr<wxBitmap> mItemBitmap;

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
	 * @param dc  Device context to draw on
	 */
	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics){}

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
	double GetWidth() const {return mItemBitmap->GetWidth(); }

	/**
	 * Get item (bitmap) height
	 * @return height in pixels
	 */
	double GetHeight() const {return mItemBitmap->GetHeight(); }

	/**
	 * Check if area is transparent
	 * @param x, y
	 * @return bool
	 */
	bool CheckTransparency(double x , double y) { return mItemImage->IsTransparent(int(x), int(y)); }

    double DistanceTo(std::shared_ptr<Item> item);

    virtual wxXmlNode* XmlSave(wxXmlNode* node);

    virtual void XmlLoad(wxXmlNode* node);

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
     */
    virtual void Update(double elapsed) {}

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
	virtual void SetName(std::string name){}

	//virtual std::wstring GetCode(){};
    //void SetMirror(bool m);   still need to implement this
protected:
    Item(Game *game, const std::wstring &filename);

};

#endif //GAME_ITEM_H
