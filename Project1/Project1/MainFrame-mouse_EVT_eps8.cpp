#include "MainFrame.h"
#include<wx/wx.h>


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	wxStatusBar* statusBar = CreateStatusBar();
	statusBar->SetDoubleBuffered(true);

	wxButton* button1 = new wxButton(panel, wxID_ANY, "Button1", wxPoint(300, 275), wxSize(200, 50));

	button1->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
}

void MainFrame::OnMouseEvent(wxMouseEvent& evt) {
	//wxPoint mousePos = evt.GetPosition();
	wxPoint mousePos = wxGetMousePosition();
	mousePos = this->ScreenToClient(mousePos);
	wxString message = wxString::Format("Mouse Event detected! x = %d, y = %d", mousePos.x, mousePos.y);
	wxLogStatus(message);
}