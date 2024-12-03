#pragma once

#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/timer.h>

class Frame : public wxFrame
{
public:
	Frame();
	virtual ~Frame();

	enum
	{
		ID_Exit = wxID_HIGHEST,
		ID_Timer
	};

	void OnExit(wxCommandEvent& event);
	void OnTimer(wxTimerEvent& event);

private:
	wxTextCtrl* textControl;
	wxTimer timer;
};