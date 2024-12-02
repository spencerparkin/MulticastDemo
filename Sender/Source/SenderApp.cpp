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

	this->frame = new Frame();
	this->frame->Show();

	return true;
}

/*virtual*/ int SenderApp::OnExit()
{
	return 0;
}