#pragma once

#include <wx/app.h>
#include "ThreadedMulticastReceiver.h"

class Frame;

class ReceiverApp : public wxApp
{
public:
	ReceiverApp();
	virtual ~ReceiverApp();

	virtual bool OnInit() override;
	virtual int OnExit() override;

	SocketHelper::ThreadedMulticastReceiver* GetReceiver();

private:
	Frame* frame;
	SocketHelper::ThreadedMulticastReceiver receiver;
};

wxDECLARE_APP(ReceiverApp);