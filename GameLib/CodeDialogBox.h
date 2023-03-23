/**
 * @file CodeDialogBox.h
 * @author srira
 *
 *
 */

#ifndef PROJECT1_GAMELIB_CODEDIALOGBOX_H
#define PROJECT1_GAMELIB_CODEDIALOGBOX_H

#include "pch.h"
#include "GameView.h"
/**
 * The Fat Bug code box
 */
class CodeDialogBox: public wxDialog
{
private:
	/// The text that appears in the pop box
	wxTextCtrl *m_textCtrl;

	///solution
	std::wstring mSol;

	///checks if solution is right
	bool mPassed = false;

	GameView* mView;
public:
	CodeDialogBox(GameView *parent, const std::wstring code,const std::wstring solution);

	/**
	 * Get if the solution is correct or not
	 * @return True if passed, else false
	 */
	bool PassCheck(){return mPassed;}

	void OnOK(wxCommandEvent& event);

	void OnTextChange(wxCommandEvent& event);
protected:

};

#endif //PROJECT1_GAMELIB_CODEDIALOGBOX_H
