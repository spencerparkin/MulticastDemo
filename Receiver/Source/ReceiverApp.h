#pragma once

#include <wx/app.h>

class Frame;

class ReceiverApp : public wxApp
{
public:
	ReceiverApp();
	virtual ~ReceiverApp();

	virtual bool OnInit() override;
	virtual int OnExit() override;

private:
	Frame* frame;
};

wxDECLARE_APP(ReceiverApp);