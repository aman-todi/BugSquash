/**
 * @file Program.cpp
 * @authors Aman Todi
 * @authors Ethan Silver
 */

#include "pch.h"
#include "Program.h"

/// Game area in virtual pixels
const static double GameWidth = 1250;

/// Game area height in virtual pixels
const static double GameHeight = 1000;


/// How close the user has click
/// For the bug to splat
const double HitRadius = 50;

/// Program name font size
const int ProgramNameFontSize = 15;

/// The color of the Text on the program
const wxColour FontColor = wxColour(255, 255, 255);

/**
 * Constructor
 * @param game Game this bug is a member of
 * @param program The program info
 */
Program::Program(Game* game,wxXmlNode* program) : Item(game)
{
	double programX, programY;
	program->GetAttribute("x").ToDouble(&programX);
	program->GetAttribute("y").ToDouble(&programY);
	mNameString= program->GetAttribute("name");

	SetLocation(programX,programY);

    mLaptopBitmap = game->GetItemBitmaps("program")[0].second;
}

/**
 * Draw program
 * @param gc
 * @param timeInSec how long the game has been running for
 */
void Program::Draw(std::shared_ptr<wxGraphicsContext> gc, double timeInSec)
{
    int laptopWid = mLaptopBitmap->GetWidth();
    int laptopHgt = mLaptopBitmap->GetHeight();

    //Draw Laptop
    gc->DrawBitmap(mLaptopBitmap->ConvertToImage(), GetX() - laptopWid/3, GetY() - laptopHgt/3, laptopWid, laptopHgt);

    //Draw Text
    wxFont fontLabel(ProgramNameFontSize,
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);

    double wid, hit;

    gc->SetFont(fontLabel, FontColor);
    gc->GetTextExtent(mNameString, &wid, &hit);
    gc->DrawText(mNameString, GetX() - wid/5, GetY());
}





