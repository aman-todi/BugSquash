/**
 * @file LoadLevelOne.h
 * @author srira
 *
 *
 */

#ifndef PROJECT1_GAMELIB_LOADLEVELONE_H
#define PROJECT1_GAMELIB_LOADLEVELONE_H
#include "game.h"
class LoadLevelOne
{
private:

public:
	/// Default constructor (disabled)
	//LoadLevelOne() = delete;

	/// Copy constructor (disabled)
	LoadLevelOne(const LoadLevelOne &) = delete;

	/// Assignment operator
	void operator=(const LoadLevelOne &) = delete;

	LoadLevelOne(Game *game);
};

#endif //PROJECT1_GAMELIB_LOADLEVELONE_H
