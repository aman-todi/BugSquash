/**
 * @file Item.cpp
 * @author Blake
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"



using namespace std;

/**
 * Game Destructor
 *
 */
Item::~Item()
{

}

/**
 * Constructor
 * @param game The game this item is a member of
 */
Item::Item(Game *game) : mGame(game)
{

}



