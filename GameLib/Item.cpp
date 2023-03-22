/**
 * @file Item.cpp
 * @author Blake
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"
#include "ItemsVisitor.h"



using namespace std;

/**
 * Game Destructor
 *
 */
Item::~Item()
{
    // Not sure if needed????
}

/**
 * Constructor
 * @param game The game this item is a member of
 * @param filename The name of the file to display for this item
 */
Item::Item(Game *game, const std::wstring &filename) : mGame(game)
{
    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}

///**
// * Draw this bug
// * @param dc Device context to draw on
// */
//void Item::Draw(wxDC *dc)
//{
//    double wid = mItemBitmap->GetWidth();
//    double hit = mItemBitmap->GetHeight();
//    dc->DrawBitmap(*mItemBitmap,
//            int(GetX() - wid / 2),
//            int(GetY() - hit / 2));
//}


/**
 * Compute the distance from this item to another item
 * @param item Item we are computing the distance to
 * @return Distance in pixels
 */
double Item::DistanceTo(std::shared_ptr<Item> item)
{
    auto dx = item->GetX() - GetX();
    auto dy = item->GetY() - GetY();
	return sqrt(dx * dx + dy * dy) ;
}



