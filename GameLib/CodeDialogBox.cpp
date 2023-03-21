/**
 * @file CodeDialogBox.cpp
 * @author srira
 */

#include "pch.h"
#include "CodeDialogBox.h"

const wxString& name = "Bug Squash IDE";

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

wxString CodeDialogBox::GetText() const
{
	return m_textCtrl->GetValue();
}

void CodeDialogBox::OnOK(wxCommandEvent& event)
{
	EndModal(wxID_OK);
}

void CodeDialogBox::OnCancel(wxCommandEvent& event)
{
	EndModal(wxID_CANCEL);
}
