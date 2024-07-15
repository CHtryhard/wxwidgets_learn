#pragma once
//#include<wx/frame.h> 
#include<wx/wx.h> // this header include most of headers

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	void OnButtonClicked(wxCommandEvent& evt);
	void OnSliderChanged(wxCommandEvent& evt);
	void OnTextChanged(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

