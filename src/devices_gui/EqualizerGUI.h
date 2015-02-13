#ifndef EQUALIZERGUI_H
#define EQUALIZERGUI_H
#include "wx/wx.h"
#include "wx/checkbox.h"
#include "wx/slider.h"
#include "wx/sizer.h"
#include "devices/Equalizer.h"

class EqualizerGUI : public wxPanel
{
public:
	EqualizerGUI(wxWindow* parent, wxWindowID id,
		const wxPoint& pos = wxDefaultPosition, Equalizer* device = nullptr);

	Equalizer* getDevice();
	void setDevice(Equalizer* device);

	void OnLowAdjust(wxCommandEvent& e);
	void OnLowMidAdjust(wxCommandEvent& e);
	void OnMidAdjust(wxCommandEvent& e);
	void OnHighMidAdjust(wxCommandEvent& e);
	void OnHighAdjust(wxCommandEvent& e);
private:
	wxStaticBox* wrap;
	Equalizer* device;
	wxStaticBoxSizer* sizer;
	wxSlider* low_control;
	wxSlider* lowMid_control;
	wxSlider* mid_control;
	wxSlider* highMid_control;
	wxSlider* high_control;

	DECLARE_EVENT_TABLE()

};

#endif