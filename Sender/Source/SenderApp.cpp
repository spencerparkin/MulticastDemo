#include "SenderApp.h"
#include "Frame.h"

wxIMPLEMENT_APP(SenderApp);

SenderApp::SenderApp()
{
	this->frame = nullptr;
}

/*virtual*/ SenderApp::~SenderApp()
{
}

/*virtual*/ bool SenderApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	this->sender.SetMulticastAddress("234.5.0.5", 8908);
	if (!this->sender.Setup())
		return false;

	this->frame = new Frame();
	this->frame->Show();

	return true;
}

/*virtual*/ int SenderApp::OnExit()
{
	this->sender.Shutdown();
	return 0;
}

SocketHelper::MulticastSender* SenderApp::GetSender()
{
	return &this->sender;
}