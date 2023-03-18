/**
 * @file LevelLoader.h
 * @author srira
 *
 *
 */

#ifndef PROJECT1_GAMELIB_LEVELLOADER_H
#define PROJECT1_GAMELIB_LEVELLOADER_H
#include "Game.h"
class LevelLoader
{
private:

public:
	/// Default constructor (disabled)
	//LevelLoader() = delete;

	/// Copy constructor (disabled)
	LevelLoader(const LevelLoader &) = delete;

	/// Assignment operator
	void operator=(const LevelLoader &) = delete;

	LevelLoader(Game *game,const std::wstring &filename);
};

#endif //PROJECT1_GAMELIB_LEVELLOADER_H
