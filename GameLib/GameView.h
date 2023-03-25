/**
 * @file GameView.h
 * @author sriram
 *
 *
 */


#ifndef PROJECT1_GAMELIB_GAMEVIEW_H
#define PROJECT1_GAMELIB_GAMEVIEW_H

#include <memory>
#include "Game.h"
#include "Item.h"

/**
 * Class that defines our Game View
 */
class GameView : public wxWindow
{
private:

	/// An object that describes our game
	Game mGame;

	/// The timer that allows for animation
	wxTimer mTimerAnimation;

	/// The timer that allows for bug motion updating each 3/speed seconds
	wxTimer mTimerBugMotion;

	/// Stopwatch used to measure elapsed time
	wxStopWatch mStopWatch;

    /// Enum class to keep track of game state
    enum class State {LevelStart, LevelRunning, LevelEnd};

    State mState = State::LevelStart;

    /// double used to track duration of display
    double mDisplayDuration = 0;

	/// Any bug we are currently dragging
	std::shared_ptr<Item> mClickedItem;

	/// The last stopwatch time
	long mTime = 0;

	/// level number
	int mLevel = 1;

	void OnPaint(wxPaintEvent& event);

public:

	void Initialize(wxFrame* );

	void OnMouseMove(wxMouseEvent &event);
	void OnLeftUp(wxMouseEvent &event);
	void OnLeftDown(wxMouseEvent &event);
	void OnDoubleClick(wxMouseEvent &event);


	void OnTimer1(wxTimerEvent &event);
	void OnTimer2(wxTimerEvent &event);

	void OnViewShrink(wxCommandEvent &event);
    void OnSize(wxSizeEvent& event);

    void OnLevelZero(wxCommandEvent& event);
    void OnLevelOne(wxCommandEvent& event);
    void OnLevelTwo(wxCommandEvent& event);
    void OnLevelThree(wxCommandEvent& event);

	void GamePause();
	void GameResume();

    /**
     * Set Level State to Start
     */
    void SetLevelStart() {mState=State::LevelStart;}

    /**
     * Set level State to Running
     */
    void SetLevelRunning() {mState=State::LevelRunning;}

    /**
     * Set level State to End
     */
    void SetLevelEnd() {mState=State::LevelEnd;}

//	void OnUpdateViewShrink(wxUpdateUIEvent &event);

};

#endif //PROJECT1_GAMELIB_GAMEVIEW_H
