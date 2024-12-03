#include "ReceiverApp.h"
#include "Frame.h"

wxIMPLEMENT_APP(ReceiverApp);

ReceiverApp::ReceiverApp()
{
	this->frame = nullptr;
}

/*virtual*/ ReceiverApp::~ReceiverApp()
{
}

/*virtual*/ bool ReceiverApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	this->receiver.SetLocalAddress("192.168.0.5", 8908);
	this->receiver.SetMulticastAddress("234.5.0.5", 8908);
	if (!this->receiver.Setup())
		return false;

	this->frame = new Frame();
	this->frame->Show();

	return true;
}

/*virtual*/ int ReceiverApp::OnExit()
{
	this->receiver.Shutdown();
	return 0;
}

SocketHelper::ThreadedMulticastReceiver* ReceiverApp::GetReceiver()
{
	return &this->receiver;
}