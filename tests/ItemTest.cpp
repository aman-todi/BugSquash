/**
 * @file ItemTest.cpp
 * @author Auden Garrard
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Game.h>
#include <NullBug.h>

/// I don't know if this is the right way to approuch this class


/// image for the NullBug
const std::wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";


class ItemMock : public Item
{
public:
	ItemMock(Game *Game) : Item(Game,NullBugSpriteImageName){}
	void Accept(ItemsVisitor* visitor) override {}
};

TEST(ItemTest, Construct)
{
	Game game;
	ItemMock item(&game);
}

//TEST(ItemTest,HitTest)
//{
//	Game game;
//	//ItemMock item(&game);
//
//	// Testing on an empty game
//	ASSERT_FALSE(game.HitTest(3,3));
//
//	///How can I add bug to test if it is being hit or not
//	//ASSERT_TRUE(game.HitTest());
//
//}
