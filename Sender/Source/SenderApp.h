#pragma once

#include <wx/app.h>

class Frame;

class SenderApp : public wxApp
{
public:
	SenderApp();
	virtual ~SenderApp();

	virtual bool OnInit() override;
	virtual int OnExit() override;

private:
	Frame* frame;
};

wxDECLARE_APP(SenderApp);