/**
 * @file CodeDialogBox.cpp
 * @author srira
 */

#include "pch.h"
#include "CodeDialogBox.h"

/// The title to the pop up window
const wxString& name = "Bug Squash IDE";
/**
 * Constructor
 * @param parent The bug that is associated with is
 * @param code The text in the box
 */
CodeDialogBox::CodeDialogBox(wxWindow *parent, const wxString& code)
	: wxDialog(parent, wxID_ANY, name, wxDefaultPosition, wxSize(600, 800))
{
	wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

	// Create the text control and set its initial text.
	m_textCtrl = new wxTextCtrl(this, wxID_ANY, code, wxDefaultPosition,
								wxDefaultSize, wxTE_MULTILINE|wxTE_DONTWRAP|wxTE_READONLY);
	sizer->SetMinSize(wxSize(400, 500));

	sizer->Add(m_textCtrl, 1, wxEXPAND|wxALL, 10);

	// Create the sizer for the OK button.
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

	// Add the OK button to the sizer.
	wxButton* okButton = new wxButton(this, wxID_OK, "OK");
	buttonSizer->Add(okButton, 0, wxALL, 10);

	// Add the button sizer to the main sizer.
	sizer->Add(buttonSizer, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 10);

	SetSizerAndFit(sizer);
	CenterOnParent();
}
/**
 * Gets the text that appears in the pop up box
 * @return The text in the pop up box
 */
wxString CodeDialogBox::GetText() const
{
	return m_textCtrl->GetValue();
}
/**
 * The handler for the "Ok" option
 * @param event Mouse event
 */
void CodeDialogBox::OnOK(wxCommandEvent& event)
{
	EndModal(wxID_OK);
}

