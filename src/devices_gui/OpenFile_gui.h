#ifndef OPENFILE_GUI_H
#define OPENFILE_GUI_H

#include "wx/wx.h"
#include "wx/checkbox.h"
#include "wx/slider.h"
#include "wx/sizer.h"


class OpenFileGUI : public wxPanel
{
public:
	OpenFileGUI(wxWindow* parent, wxWindowID id,
		const wxPoint& pos = wxDefaultPosition);

	void OpenFile(wxCommandEvent& e);

	wxString CurrentDocPath;

private:
	wxStaticBoxSizer* sizer;
	wxStaticBox* wrap;
	wxButton* browse;


	DECLARE_EVENT_TABLE()
};

#endif