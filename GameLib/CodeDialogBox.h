/**
 * @file CodeDialogBox.h
 * @author srira
 *
 *
 */

#ifndef PROJECT1_GAMELIB_CODEDIALOGBOX_H
#define PROJECT1_GAMELIB_CODEDIALOGBOX_H

#include "pch.h"
/**
 * The Fat Bug code box
 */
class CodeDialogBox: public wxDialog
{
private:
	/// The text that appears in the pop box
	wxTextCtrl *m_textCtrl;

	///solution
	std::string mSol;

	///checks if solution is right
	bool mPassed = false;
public:
	CodeDialogBox(wxWindow *parent, const wxString& code,const wxString& solution);

	wxString GetText() const;

	bool PassCheck(){return mPassed;}
	void OnOK(wxCommandEvent& event);

protected:
	//wxDECLARE_EVENT_TABLE();
	bool SolutionChecker();
	void OnTextChanged();
};

#endif //PROJECT1_GAMELIB_CODEDIALOGBOX_H
