/**
 * @file GameView.cpp
 * @author sriram
 * @author ethan
 */

#include "pch.h"

#include <sstream>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

#include "ids.h"

#include "GameView.h"
#include "GarbageBug.h"
#include "NullBug.h"
#include "RedundancyBug.h"
#include "FeatureBug.h"
#include "LevelLoader.h"
#include "CodeDialogBox.h"
#include "BugVisitor.h"
#include "Scoreboard.h"

/// Frame duration in milliseconds
const int FrameDuration = 30;

/// Animation timer duration in milliseconds
const int AnimationDuration = 5;

/// Game area in virtual pixels
const static int GameWidth = 1250;

/// Game area height in virtual pixels
const static int GameHeight = 1000;

///Bug speed in virtual pixels per second
const static int BugSpeed = 10;

/// To convert milliseconds to seconds
const static double MsToSec = 1000;

/// The level0 XML
const std::wstring LevelZeroXMLFileName = L"data/level0.xml";

/// The level1 XML
const std::wstring LevelOneXMLFileName = L"data/level1.xml";

/// The level2 XML
const std::wstring LevelTwoXMLFileName = L"data/level2.xml";

/// The level3 XML
const std::wstring LevelThreeXMLFileName = L"data/level3.xml";

using namespace std;

/**
 * Initialize the game view class.
 * @param parent The parent window for this class
 */
void GameView::Initialize(wxFrame* parent)
{
	Create(parent, wxID_ANY,
            wxDefaultPosition, wxDefaultSize,
            wxFULL_REPAINT_ON_RESIZE);

	SetBackgroundStyle(wxBG_STYLE_PAINT);
	//mTimerBugMotion.Start(3/BugSpeed);

	Bind(wxEVT_PAINT, &GameView::OnPaint, this);
	//parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnFileSaveAs, this, wxID_SAVEAS);
	//parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnFileOpen, this, wxID_OPEN);
    Bind(wxEVT_SIZE , &GameView::OnSize, this, IDM_RESIZE);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnViewShrink, this, IDM_SHRINK);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevelZero, this, IDM_LEVELZERO);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevelOne, this, IDM_LEVELONE);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevelTwo, this, IDM_LEVELTWO);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevelThree, this, IDM_LEVELTHREE);

	// The mouse events
	Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
	Bind(wxEVT_LEFT_UP, &GameView::OnLeftUp, this);
	Bind(wxEVT_MOTION, &GameView::OnMouseMove, this);
	Bind(wxEVT_LEFT_DCLICK, &GameView::OnDoubleClick, this);
	Bind(wxEVT_TIMER, &GameView::OnTimer1, this);
	Bind(wxEVT_TIMER, &GameView::OnTimer2, this);


	// The timer for animation
	mTimerAnimation.SetOwner(this);
	mTimerAnimation.Start(FrameDuration);
	mStopWatch.Start();

	// The timer for bug motion
	mTimerBugMotion.SetOwner(this);
	mTimerBugMotion.Start(AnimationDuration);
}



/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear the image to black
    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

	//convert the time to seconds
	double TimeInSec = double(mTime) / MsToSec;
	mGame.Update(elapsed, TimeInSec);

    // Create a graphics context
    auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    // Tell the game class to draw
    wxRect rect = GetRect();
    auto minDimension = min(rect.GetWidth(), rect.GetHeight());
    if(minDimension == 0)
    {
        // No reason to draw if the window is size zero
        // and this avoids any divide by zero errors
        return;
    }

    mGame.OnDraw(gc,rect.GetWidth(), rect.GetHeight());
}

/**
 * Event handler for resizing the window
 * @param event Size event
 */
void GameView::OnSize(wxSizeEvent& event)
{
    Refresh();
	event.Skip();
}

/**
 * Event handler for wxEVT_TIMER for animation timer
 * @param event Timer event
 */
void GameView::OnTimer1(wxTimerEvent &event){

	// Auto load the next level
	if (mLevel == 0){
		if (mGame.GetScoreboard()->GetTotalScore() == 3){
			mGame.Clear();
			mGame.GetScoreboard()->ResetScore();
			mLevel = 1;
			LevelLoader level1(&mGame,LevelOneXMLFileName);
			mStopWatch.Start(0);
		}
	}
	else if (mLevel == 1){
		if (mGame.GetScoreboard()->GetTotalScore() == 12){
			mGame.Clear();
			mGame.GetScoreboard()->ResetScore();
			mLevel = 2;
			LevelLoader level2(&mGame,LevelTwoXMLFileName);
			mStopWatch.Start(0);
		}
	}

	else if (mLevel == 2){
		if (mGame.GetScoreboard()->GetTotalScore() == 24){
			mGame.Clear();
			mGame.GetScoreboard()->ResetScore();
			mLevel = 3;
			LevelLoader level2(&mGame,LevelThreeXMLFileName);
			mStopWatch.Start(0);
		}
	}

	Refresh();
}

/**
 * Event handler for wxEVT_TIMER for bug motion timer
 * @param event Timer event
 */
void GameView::OnTimer2(wxTimerEvent &event){

	// Calls game to update animation timer for each bug
	mGame.UpdateAnimationTime();
	Refresh();
}


/**
* Handle the left mouse button down event
* @param event
*/
void GameView::OnLeftDown(wxMouseEvent &event)
{
	//Check to see if we hit a bug
	mClickedItem = mGame.OnClick(event.GetX(),event.GetY(),false);
	if(mClickedItem != nullptr)
	{
		//Moves the bug to the end of the list
		//mGame.UpdateList(mClickedItem);
		Refresh();
	}
}

/**
* Handle the left mouse button up event
* @param event
*/
void GameView::OnLeftUp(wxMouseEvent &event)
{
	OnMouseMove(event);
}

/**
* Handle the mouse move event
* @param event
*/
void GameView::OnMouseMove(wxMouseEvent &event)
{

}

/**
* Checks for double click
* @param event
*/

void GameView::OnDoubleClick(wxMouseEvent &event)
{
	//Check to see if we hit a bug
	mClickedItem = mGame.OnClick(event.GetX(),event.GetY(),true);

	if (mClickedItem != nullptr)
	{
		BugVisitor visitor;
		mClickedItem->Accept(&visitor);
		
		if(visitor.Fatbug())
		{
			auto code = visitor.GetCode();
			auto solution = visitor.GetSolution();

			CodeDialogBox dlg(this, code,solution);
			// Show the dialog box as a modal dialog
			dlg.ShowModal();

			//increase fixed score by 1
			bool passed = dlg.PassCheck();
			if (passed)
			{
				visitor.SetSplat();
			}
			Refresh();
		}
	}
}

/**
 * Turns or off the no clipping
 * @param event Menu event
 */
void GameView::OnViewShrink(wxCommandEvent& event)
{
    mGame.Shrink();
    Refresh();
}
/**
 * Loads in level Zero
 * @param event Menu event
 */
void GameView::OnLevelZero(wxCommandEvent& event)
{
	mGame.Clear();
	mLevel = 0;
    LevelLoader level0(&mGame,LevelZeroXMLFileName);
}
/**
 * Loads in level One
 * @param event Menu event
 */
void GameView::OnLevelOne(wxCommandEvent& event)
{
	mGame.Clear();
	mLevel = 1;
    LevelLoader level1(&mGame,LevelOneXMLFileName);
	mStopWatch.Start(0);
}
/**
 * Loads in level Two
 * @param event Menu event
 */
void GameView::OnLevelTwo(wxCommandEvent& event)
{
	mGame.Clear();
	mLevel = 2;
    LevelLoader level2(&mGame,LevelTwoXMLFileName);
	mStopWatch.Start(0);
}
/**
 * Loads in level Three
 * @param event Menu event
 */
void GameView::OnLevelThree(wxCommandEvent& event)
{
	mGame.Clear();
	mLevel = 3;
    LevelLoader level3(&mGame,LevelThreeXMLFileName);
	mStopWatch.Start(0);
}

/**
 * Pause the game
 */
void GameView::GamePause()
{
	mStopWatch.Pause();
	mTimerBugMotion.Stop();
	mTimerAnimation.Stop();
}

/**
 * Resume  the game
 */
void GameView::GameResume()
{
	mStopWatch.Resume();
	mTimerBugMotion.Start(5);
	mTimerAnimation.Start(30);
}