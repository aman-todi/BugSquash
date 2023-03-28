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


class Virus;

class VirusVisitor : public ItemsVisitor
{
private:
	Virus* mVirus = nullptr;
public:
	virtual void VisitVirus (Virus* bug) override;

	Virus* FetchVirus();
};

#endif //PROJECT1_GAMELIB_VIRUSVISITOR_H
