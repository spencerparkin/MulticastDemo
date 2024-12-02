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

	this->frame = new Frame();
	this->frame->Show();

	return true;
}

/*virtual*/ int ReceiverApp::OnExit()
{
	return 0;
}