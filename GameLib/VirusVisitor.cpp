/**
 * @file VirusVisitor.cpp
 * @author Aman Todi
 */

#include "pch.h"
#include "VirusVisitor.h"
#include "Virus.h"

void VirusVisitor::VisitVirus(Virus* bug)
{
	mVirus = bug;
}

Virus* VirusVisitor::FetchVirus()
{
	return mVirus;
}



