#pragma once

#include "wx/wx.h"
#include "wx/checkbox.h"
#include "wx/slider.h"
#include "wx/sizer.h"
#include "devices/filters/PanFilter.h"

class PanFilterGUI : public wxPanel
{
public:
	PanFilterGUI(wxWindow* parent, wxWindowID id,
		const wxPoint& pos = wxDefaultPosition, PanFilter* device = nullptr);

	PanFilter* getDevice();
	void setDevice(PanFilter* device);

	void OnPanAdjust(wxCommandEvent& e);
private:
	wxStaticBox* wrap;
	PanFilter* filter;
	wxStaticBoxSizer* sizer;
	wxSlider* PanControl;

	DECLARE_EVENT_TABLE()

};

