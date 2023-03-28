/**
 * @file VirusVisitor.h
 * @author Aman Todi
 *
 *
 */

#ifndef PROJECT1_GAMELIB_VIRUSVISITOR_H
#define PROJECT1_GAMELIB_VIRUSVISITOR_H

#include "ItemsVisitor.h"
#include "Bug.h"

/**
 * Visitor to find the virus in the game
 * and return a pointer to it
 */
class Virus;
/**
 * Find the Virus
 */
class VirusVisitor : public ItemsVisitor
{
private:
	/// The Virus
	Virus* mVirus = nullptr;
public:
	virtual void VisitVirus (Virus* bug) override;

	Virus* FetchVirus();
};

#endif //PROJECT1_GAMELIB_VIRUSVISITOR_H
