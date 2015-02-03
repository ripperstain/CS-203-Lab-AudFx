#ifndef VOCALBLEEDGUI_H
#define VOCALBLEEDGUI_H

#include "wx/wx.h"
#include "wx/checkbox.h"
#include "wx/sizer.h"
#include "devices/VocalBleed.h"


class VocalBleedGUI : public wxPanel
{
public:
	VocalBleedGUI(wxWindow* parent, wxWindowID id,
		const wxPoint& pos = wxDefaultPosition, VocalBleed* device = nullptr);

	VocalBleed* getDevice();
	void setDevice(VocalBleed* device);

	void OnchkEnable(wxCommandEvent& e);

private:
	VocalBleed* filter;
	wxStaticBoxSizer* sizer;
	wxStaticBox* wrap;
	wxCheckBox* chkEnabled;

	DECLARE_EVENT_TABLE()
};

#endif