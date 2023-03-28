/**
 * @file VirusVisitor.cpp
 * @author Aman Todi
 */

#include "pch.h"
#include "VirusVisitor.h"
#include "Virus.h"
/**
 * Assign the virus
 * @param bug The bug being visited
 */
void VirusVisitor::VisitVirus(Virus* bug)
{
	mVirus = bug;
}

/**
 * Return the Virus in the game if one
 * @return The virus
 */
Virus* VirusVisitor::FetchVirus()
{
	return mVirus;
}



