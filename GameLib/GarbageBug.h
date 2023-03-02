/**
 * @file GarbageBug.h
 * @author srira
 *
 *
 */

#ifndef GAME_GAME_GAMELIB_GARBAGEBUG_H
#define GAME_GAME_GAMELIB_GARBAGEBUG_H

#include "Bug.h"
#include "Game.h"
/**
 * Class for a bug type GarbageBug
 */
class GarbageBug: public Bug
{
private:
//	/// Width of the sprite image
//	int mWidth = 0;
//
//	/// Height of the sprite image
//	int mHeight = 0;


public:
	/// Default constructor (disabled)
	GarbageBug() = delete;

	/// Copy constructor (disabled)
	GarbageBug(const GarbageBug &) = delete;

	/// Assignment operator
	void operator=(const GarbageBug &) = delete;

	GarbageBug(Game *game);
};

#endif //GAME_GAME_GAMELIB_GARBAGEBUG_H
