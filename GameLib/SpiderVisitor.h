/**
 * @file SpiderVisitor.h
 * @author Aman Todi
 *
 *
 */

#ifndef PROJECT1_GAMELIB_SPIDERVISITOR_H
#define PROJECT1_GAMELIB_SPIDERVISITOR_H

#include "ItemsVisitor.h"
#include "Bug.h"

class Spider;

class SpiderVisitor : public ItemsVisitor
{
private:
	Spider* mSpider = nullptr;
public:
	virtual void VisitSpider (Spider* bug) override;

	Spider* FetchSpider();
};

#endif //PROJECT1_GAMELIB_SPIDERVISITOR_H
