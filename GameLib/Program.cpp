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

/// Program name font size
const int ProgramNameFontSize = 22;
/**
 * Constructor
 * @param game Game this bug is a member of
 */
Program::Program(Game* game) : Item(game, ProgramImage)
{
    double centerX = GameWidth/2;
    double centerY = GameHeight/2;


	this->SetLocation(625, 500);
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
}




