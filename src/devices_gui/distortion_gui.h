#ifndef DISTORTION_GUI_H
#define DISTORTION_GUI_H

#include "wx/wx.h"
#include "wx/checkbox.h"
#include "wx/slider.h"
#include "wx/sizer.h"
#include "devices/filters/DistortionFilter.h"


class DistortionGUI : public wxPanel
{
public:
	DistortionGUI(wxWindow* parent, wxWindowID id, 
		const wxPoint& pos = wxDefaultPosition, DistortionFilter* device = nullptr);

	AbstractAudio* getDevice();
	void setDevice(DistortionFilter* device);

	void OnchkEnable(wxCommandEvent& e);
	void OnDriveAdjust(wxCommandEvent& e);

private:
	DistortionFilter* filter;
	wxStaticBoxSizer* sizer;
	wxStaticBox* wrap;
	wxCheckBox* chkEnabled;
	wxSlider* DriveControl;

	DECLARE_EVENT_TABLE()
};

#endif