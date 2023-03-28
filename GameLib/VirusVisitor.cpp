/**
 * @file VirusVisitor.cpp
 * @author Aman Todi
 */

#include "pch.h"
#include "VirusVisitor.h"
#include "Virus.h"

/**
 * Visit the Virus in the game if one
 * @param bug
 */
void VirusVisitor::VisitVirus(Virus* bug)
{
	mVirus = bug;
}

/**
 * Return the Virus in the game if one
 * @return
 */
Virus* VirusVisitor::FetchVirus()
{
	return mVirus;
}



