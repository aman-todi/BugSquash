/**
 * @file LevelLoader.h
 * @author srira
 *
 *
 */

#ifndef PROJECT1_GAMELIB_LEVELLOADER_H
#define PROJECT1_GAMELIB_LEVELLOADER_H
#include "Game.h"
/**
 * Loads in the levels
 */
class LevelLoader
{
private:

	///number of programs in a level
	int mNumPrograms = 0;

	///number of bugs in a level
	int mNumBugs = 0;

public:
	/// Default constructor (disabled)
	//LevelLoader() = delete;

	/// Copy constructor (disabled)
	LevelLoader(const LevelLoader &) = delete;

	/// Assignment operator
	void operator=(const LevelLoader &) = delete;

	LevelLoader(Game *game,const std::wstring &filename);

	/**
	 * getter for number of programs
	 * @return
	 */
	int GetNumPrograms(){return mNumPrograms;}

	/**
	 * getter for number of bugs
	 * @return
	 */
	int GetNumBugs(){return mNumBugs;}
};

#endif //PROJECT1_GAMELIB_LEVELLOADER_H
