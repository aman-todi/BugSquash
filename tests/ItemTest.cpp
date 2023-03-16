///**
// * @file ItemTest.cpp
// * @author Auden Garrard
// */
//
//#include <pch.h>
//#include "gtest/gtest.h"
//#include <Item.h>
//#include <Game.h>
//#include <NullBug.h>
//
//using namespace std;
//
///// I don't know if this is the right way to approuch this class
//
//
///// image for the NullBug
//const std::wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";
//
//
//class ItemMock : public Item
//{
//protected:
//	/**
//	 *  Populate the game with Three NullBugs
//	 * @param game The game to populate the fish to
//	 */
//	void AddThreeNullBug(Game *game)
//	{
//
//		auto bug1 = make_shared<NullBug>(game);
//		game->Add(bug1);
//		bug1->SetLocation(500,500);
//
//
//		auto bug2 = make_shared<NullBug>(game);
//		game->Add(bug2);
//		bug2->SetLocation(750,700);
//
//		auto bug3 = make_shared<NullBug>(game);
//		game->Add(bug3);
//		bug3->SetLocation(300,800);
//
//	}
//
//public:
//	ItemMock(Game *Game) : Item(Game,NullBugSpriteImageName){}
//	void Accept(ItemsVisitor* visitor) override {}
//};
//
//TEST_F(ItemTest, Construct)
//{
//	Game game;
//	ItemMock item(&game);
//}
//
//
//TEST_F(ItemTest,OnLeftDown)
//{
//	Game game;
//
//	//AddThreeNullBug(&game);
//
//	shared_ptr<Item> nullBug = game.OnLeftDown(500,500);
//
////	ASSERT_NEAR(nullBug->GetY(),500,.01);
////	ASSERT_NEAR(nullBug->GetX(),500,.01);
//
//}