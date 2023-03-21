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
	: wxDialog(parent, wxID_ANY, name)
{
	wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

	// Create the text control and set its initial text.
	m_textCtrl = new wxTextCtrl(this, wxID_ANY, code);
	sizer->Add(m_textCtrl, wxSizerFlags().Expand().Border());

	wxBoxSizer *buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	wxButton *okButton = new wxButton(this, wxID_OK, "OK");
	wxButton *cancelButton = new wxButton(this, wxID_CANCEL, "Cancel");
	buttonSizer->Add(okButton, wxSizerFlags().Border(wxRIGHT));
	buttonSizer->Add(cancelButton);
	sizer->Add(buttonSizer, wxSizerFlags().Align(wxALIGN_RIGHT).Border(wxTOP|wxRIGHT|wxBOTTOM));

	SetSizerAndFit(sizer);
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
/**
 * The handler for the "Cancel" option
 * @param event Mouse event
 */
void CodeDialogBox::OnCancel(wxCommandEvent& event)
{
	EndModal(wxID_CANCEL);
}
