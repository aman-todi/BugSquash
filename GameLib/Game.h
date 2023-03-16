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

    ///Game Scoreboard
    std::shared_ptr<Scoreboard> mScoreboard;

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


	void Add(std::shared_ptr<Bug> item);
	std::shared_ptr<Item> HitTest(int x, int y);
//	void MoveToFront(std::shared_ptr<Bug> item);
//	void MovetoEnd(std::shared_ptr<Bug> item);
	void DeleteBug(std::shared_ptr<Bug> item);


	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics,int width, int height);

	void Clear();

	// I don't think we can have this
	//std::vector<std::shared_ptr<Item>> GetItems(){return mItems;}


    /**
     * Shrink The Game Window
     */
    void Shrink();

    /**
     * Is the Game Shrunk?
     * @return bool
     */
    bool IsShrunk() {return mShrinked;}

	void Update(double elapsed);
	//void SortBugs();

	void UpdateList(std::shared_ptr<Item> item);

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

	/**
	 * Set the item single clicked to splat
	 * @param x, y location which was clicked
	 */
	std::shared_ptr<Item> OnLeftDown(double x, double y);
};

#endif //PROJECT1_GAMELIB_GAME_H
