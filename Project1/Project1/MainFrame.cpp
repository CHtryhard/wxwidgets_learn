#include "MainFrame.h"
#include<wx/wx.h>
#include<wx/spinctrl.h>
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	
	//point is location starting from top left corner
	wxButton* button = new wxButton(panel, wxID_ANY, "Confirm", wxPoint(150, 50), wxSize(100, 35));

	wxCheckBox* checkbox = new wxCheckBox(panel, wxID_ANY, "Checkbox", wxPoint(550, 50),wxDefaultSize,wxCHK_3STATE|wxCHK_ALLOW_3RD_STATE_FOR_USER);

	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "Static Text, NOT editable!", wxPoint(0, 150),wxSize(400,-1),wxALIGN_CENTER_HORIZONTAL);
	staticText->SetBackgroundColour(*wxLIGHT_GREY); 

	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "editable Text!", wxPoint(550, 150),wxSize(200,-1),wxTE_PASSWORD);

	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL);
	
	//wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 205), wxSize(-1, 125),wxGA_VERTICAL);

	gauge->SetValue(50);

	wxArrayString choices;
	choices.Add("Item A");
	choices.Add("Item B");
	choices.Add("Item C");

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);
	choice->Select(0); //default is -1 for empty

	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1));

	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 500), wxSize(200, -1), choices,wxLB_MULTIPLE);

	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "Radio Box", wxPoint(555, 450), wxDefaultSize, choices,1);
	//same as above since there is only 3 items
	//wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "Radio Box", wxPoint(555, 450), wxDefaultSize, choices,3,wxLB_MULTIPLE);
	
}