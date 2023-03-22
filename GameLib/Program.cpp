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

/// Program image filename
const std::wstring ProgramImage = L"images/laptop.png";

/// How close the user has click
/// For the bug to splat
const double HitRadius = 50;

/// Program name font size
const int ProgramNameFontSize = 15;

/// The color of the Text on the program
const wxColour FontColor = wxColour(0, 200, 200);

/**
 * Constructor
 * @param game Game this bug is a member of
 * @param program The program info
 */
Program::Program(Game* game,wxXmlNode* program) : Item(game, ProgramImage)
{
	double programX, programY;
	program->GetAttribute("x").ToDouble(&programX);
	program->GetAttribute("y").ToDouble(&programY);
	mNameString= program->GetAttribute("name");

	SetLocation(programX,programY);

    mLaptopImage = std::make_shared<wxImage>(ProgramImage);
}

void Program::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
    //Create Image Bitmap
    if (mLaptopBitmap.IsNull()) {
        mLaptopBitmap = gc->CreateBitmapFromImage(*mLaptopImage);
    }

    int laptopWid = mLaptopImage->GetWidth();
    int laptopHgt = mLaptopImage->GetHeight();

    //Draw Laptop
    gc->DrawBitmap(mLaptopBitmap, GetX() - laptopWid/3, GetY() - laptopHgt/3, laptopWid, laptopHgt);

    //Draw Text
    wxFont fontLabel(ProgramNameFontSize,
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);

    double wid, hit;

    gc->SetFont(fontLabel, FontColor);
    gc->GetTextExtent(mNameString, &wid, &hit);
    gc->DrawText(mNameString, GetX() - wid/4, GetY() - hit/3);
}
/**
	* HitTest
	* @param x, y (x,y) coords
 	* @return if the Hit is within the radius
	*/
//bool Program::HitTest(int x, int y)
//{
//
////    double dx = x - GetX();
////    double dy = y - GetY();
////
////    return sqrt(dx * dx + dy * dy) < HitRadius;
//	return false;
//}




