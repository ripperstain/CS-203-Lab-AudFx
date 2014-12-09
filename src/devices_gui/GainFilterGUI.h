#pragma once

#include "wx/wx.h"
#include "wx/checkbox.h"
#include "wx/slider.h"
#include "wx/sizer.h"
#include "devices/filters/GainFilter.h"

class GainFilterGUI : public wxPanel
{
public:
	GainFilterGUI(wxWindow* parent, wxWindowID id,
		const wxPoint& pos = wxDefaultPosition, GainFilter* device = nullptr);

	AbstractAudio* getDevice();
	void setDevice(GainFilter* device);

	void OnGainAdjust(wxCommandEvent& e);
private:
	wxStaticBox* wrap;
	GainFilter* filter;
	wxStaticBoxSizer* sizer;
	wxSlider* GainControl;

	DECLARE_EVENT_TABLE()

};

