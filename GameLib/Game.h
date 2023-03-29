/**
 * @file Game.h
 * @author sriram
 *
 *
 */

#ifndef PROJECT1_GAMELIB_GAME_H
#define PROJECT1_GAMELIB_GAME_H

#include <memory>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include "Bug.h"
#include "Item.h"
#include <random>
#include <wx/graphics.h>
#include <unordered_map>

class Scoreboard;
class ItemsVisitor;
class Program;

/**
 * The main Game class
 */
class Game
{
private:

	/// All of the bugs in game
	std::vector<std::shared_ptr<Item> > mItems;

	///image bitmaps for all bugs
	std::unordered_map<wxString, std::vector<std::pair<wxString,std::shared_ptr<wxBitmap>>>> mItemBitmaps;

    ///Game Scoreboard
	std::shared_ptr<Scoreboard> mScoreboard;


    /// Level Name
    wxString mLevelName;

	/// Random number generator
	std::mt19937 mRandom;

    ///Is Window Shrunk?
    bool mShrinked = false;

    ///Scaled Window Value
    double mScale = 0;

    ///X-coord scale offset
    double mXOffset = 0;

    ///Y-coord scale offset
    double mYOffset = 0;

	/// level number
	int mLevel = 1;


public:
	Game();

	/**
	 * Destructor
	*/
	virtual ~Game() = default;


	void AddItem(std::shared_ptr<Item> item);
	void AddItemBitmap(wxString bugType,std::vector<std::pair<wxString,std::shared_ptr<wxBitmap>>> bitmaps);
	std::shared_ptr<Item> HitTest(int x, int y);
	void DeleteBug(std::shared_ptr<Item> item);
	std::vector<std::pair<wxString,std::shared_ptr<wxBitmap>>> GetItemBitmaps(wxString ItemType);

	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics,int width, int height,double timeInSec);

	void Clear();

	/**
     * Shrink The Game Window
     */
    void Shrink();

	void Update(double elapsed, double Time);

	void UpdateAnimationTime();

	/// visitor
	void Accept(ItemsVisitor* visitor);

	std::shared_ptr<Item> OnClick(double x, double y,bool doubleCLick);

	/**
	 * Gets the scoreboard
	 * @return The scoreboard
	 */
    std::shared_ptr<Scoreboard> GetScoreboard() {return mScoreboard;}

    /**
     * Get Level Name
     * @return wxString
     */
    wxString GetLevelName() {return mLevelName;}

    /**
     * Set Level Name
     * @param lv new level name
     */
    void SetLevelName(wxString lv) {mLevelName = lv;}

    /**
     * Get Scale
     * @return mScale
     */
    double GetScale() {return mScale;}

    /**
     * Get X Offset
     * @return the X offset
     */
    double GetXOffSet() {return mXOffset;}

    /**
     * Get Y Offset
     * @return The Y offset
     */
    double GetYOffSet() {return mYOffset;}

    /**
     * Add Split Redundancy Bug to the game
     * @param item redundancy bug item object
     * @param randNum randomly generated number, average 200
     * @return RedBug redundancy split bug object
     */
    std::shared_ptr<Bug> AddRed(std::shared_ptr<Item> item, double randNum);

	void PlayVirus();
};
#endif //PROJECT1_GAMELIB_GAME_H
