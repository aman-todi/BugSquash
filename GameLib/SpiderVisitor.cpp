/**
 * @file SpiderVisitor.cpp
 * @author Aman Todi
 */

#include "pch.h"
#include "SpiderVisitor.h"
#include "Spider.h"

void SpiderVisitor::VisitSpider(Spider* bug)
{
	mSpider = bug;
}

Spider* SpiderVisitor::FetchSpider()
{
	return mSpider;
}



