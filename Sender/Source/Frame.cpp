#include "Frame.h"
#include "SenderApp.h"
#include <wx/menu.h>
#include <wx/sizer.h>
#include <format>

Frame::Frame() : wxFrame(nullptr, wxID_ANY, "Sender")
{
	wxMenu* programMenu = new wxMenu();
	programMenu->Append(new wxMenuItem(programMenu, ID_Exit, "Exit", "Exit this program."));

	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(programMenu, "Program");
	this->SetMenuBar(menuBar);

	this->Bind(wxEVT_MENU, &Frame::OnExit, this, ID_Exit);

	this->textControl = new wxTextCtrl(this, wxID_ANY);
	this->sendButton = new wxButton(this, wxID_ANY, "Send");
	this->sendButton->Bind(wxEVT_BUTTON, &Frame::OnSendButtonPressed, this);

	wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
	boxSizer->Add(this->textControl, 1, wxALL | wxGROW, 2);
	boxSizer->Add(this->sendButton, 1, wxLEFT | wxRIGHT | wxBOTTOM, 2);
	this->SetSizer(boxSizer);
}

/*virtual*/ Frame::~Frame()
{
}

void Frame::OnExit(wxCommandEvent& event)
{
	this->Close(true);
}

void Frame::OnSendButtonPressed(wxCommandEvent& event)
{
	SocketHelper::MulticastSender* sender = wxGetApp().GetSender();
	static int i = 0;
	std::string message = std::format("Message #{}", i++);
	sender->Send((uint8_t*)message.c_str(), message.length());
}