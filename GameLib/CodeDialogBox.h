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

public:
	CodeDialogBox(wxWindow *parent, const wxString& code);

	wxString GetText() const;

	void OnOK(wxCommandEvent& event);
	void OnCancel(wxCommandEvent& event);

protected:
	//wxDECLARE_EVENT_TABLE();
};

#endif //PROJECT1_GAMELIB_CODEDIALOGBOX_H
