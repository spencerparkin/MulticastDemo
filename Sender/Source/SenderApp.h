#pragma once

#include <wx/app.h>
#include "MulticastSender.h"

class Frame;

class SenderApp : public wxApp
{
public:
	SenderApp();
	virtual ~SenderApp();

	virtual bool OnInit() override;
	virtual int OnExit() override;

	SocketHelper::MulticastSender* GetSender();

private:
	Frame* frame;
	SocketHelper::MulticastSender sender;
};

wxDECLARE_APP(SenderApp);