#pragma once

#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/button.h>

class Frame : public wxFrame
{
public:
	Frame();
	virtual ~Frame();

	enum
	{
		ID_Exit = wxID_HIGHEST
	};

	void OnExit(wxCommandEvent& event);
	void OnSendButtonPressed(wxCommandEvent& event);

private:
	wxButton* sendButton;
	wxTextCtrl* textControl;
};