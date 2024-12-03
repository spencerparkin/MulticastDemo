#include "Frame.h"
#include "ReceiverApp.h"
#include <wx/menu.h>
#include <wx/sizer.h>
#include <format>

Frame::Frame() : wxFrame(nullptr, wxID_ANY, "Receiver"), timer(this, ID_Timer)
{
	wxMenu* programMenu = new wxMenu();
	programMenu->Append(new wxMenuItem(programMenu, ID_Exit, "Exit", "Exit this program."));

	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(programMenu, "Program");
	this->SetMenuBar(menuBar);

	this->Bind(wxEVT_MENU, &Frame::OnExit, this, ID_Exit);
	this->Bind(wxEVT_TIMER, &Frame::OnTimer, this, ID_Timer);

	this->textControl = new wxTextCtrl(this, wxID_ANY);

	wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
	boxSizer->Add(this->textControl, 1, wxALL | wxGROW, 2);
	this->SetSizer(boxSizer);

	this->timer.Start(10);
}

/*virtual*/ Frame::~Frame()
{
}

void Frame::OnExit(wxCommandEvent& event)
{
	this->Close(true);
}

void Frame::OnTimer(wxTimerEvent& event)
{
	SocketHelper::ThreadedMulticastReceiver* receiver = wxGetApp().GetReceiver();
	SocketHelper::ThreadedMulticastReceiver::Message message{};
	if (receiver->ReceiveMessageFromThread(message))
	{
		wxString text((const char*)message.buffer);
		this->textControl->AppendText(text + "\n");
	}
}