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

using namespace std;
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
	vector<shared_ptr<Item> > mItems;

	///image bitmaps for all bugs
	unordered_map<wxString, vector<pair<wxString,shared_ptr<wxBitmap>>>> mItemBitmaps;

    ///Game Scoreboard
    shared_ptr<Scoreboard> mScoreboard;

    /// Level Name
    wxString mLevelName;

	//void XmlBug(wxXmlNode *node);

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

public:
	Game();

	/**
	 * Destructor
	*/
	virtual ~Game() = default;


	void AddItem(std::shared_ptr<Item> item);
	void AddItemBitmap(wxString bugType,vector<pair<wxString,shared_ptr<wxBitmap>>> bitmaps);
	std::shared_ptr<Item> HitTest(int x, int y);
//	void MoveToFront(std::shared_ptr<Bug> item);
//	void MovetoEnd(std::shared_ptr<Bug> item);
	void DeleteBug(std::shared_ptr<Item> item);

	vector<pair<wxString,shared_ptr<wxBitmap>>> GetItemBitmaps(wxString bugType);

	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics,int width, int height,double timeInSec);

	void Clear();


	/**
	 * Items getter
	 * @return pointer to mItems
	 */
	std::vector<std::shared_ptr<Item> >* GetItems() { return &mItems; }

    /**
     * Shrink The Game Window
     */
    void Shrink();

    /**
     * Is the Game Shrunk?
     * @return bool
     */
    bool IsShrunk() {return mShrinked;}

	void Update(double elapsed, double Time);
	//void SortBugs();

	void UpdateList(std::shared_ptr<Item> item);

	void UpdateAnimationTime();

	/**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
	std::mt19937 &GetRandom() {
		// Seed the random number generator
		std::random_device rd;
		mRandom.seed(1238197374);
		return mRandom;}

	/// visitor
	void Accept(ItemsVisitor* visitor);

	std::shared_ptr<Item> OnClick(double x, double y,bool doubleCLick);

	//void XmlBug(std::wstring FileName);
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
     * @return
     */
    double GetXOffSet() {return mXOffset;}

    /**
     * Get Y Offset
     * @return
     */
    double GetYOffSet() {return mYOffset;}

    /**
     * Add Split Redundancy Bug to the game
     * @param item redundancy bug item object
     * @return RedBug redundancy split bug object
     */
    std::shared_ptr<Bug> AddRed(std::shared_ptr<Item> item);
};
#endif //PROJECT1_GAMELIB_GAME_H
