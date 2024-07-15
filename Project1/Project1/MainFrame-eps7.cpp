#include "MainFrame.h"
#include<wx/wx.h>

//
// below is the static way of event handling
// 	   there are some limitations
// 	   set up on compulating
// 	   can not modify binding during run time
// enum IDs
//{
//	BUTTON_ID = 2,
//	SLIDER_ID = 3,
//	TEXT_ID = 4
//
//};
//wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
//	EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
//	EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)
//	EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
//wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	wxButton* button1 = new wxButton(panel, wxID_ANY, "Button1", wxPoint(300, 275), wxSize(200, 50));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button2", wxPoint(300, 350), wxSize(200, 50));
	
	this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);

	CreateStatusBar();
}
void MainFrame::OnClose(wxCloseEvent& evt) {
	wxLogMessage("Frame Closed");
	evt.Skip();
}

void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt) {
	wxLogMessage("Button Clicked");
}

void MainFrame::OnButton1Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button1 Clicked");
	evt.Skip();
}
void MainFrame::OnButton2Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button2 Clicked");
	evt.Skip();
}
