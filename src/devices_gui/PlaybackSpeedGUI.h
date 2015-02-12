#ifndef PLAYBACKSPEEDGUI_H
#define PLAYBACKSPEEDGUI_H
#include "wx/wx.h"
#include "wx/checkbox.h"
#include "wx/slider.h"
#include "wx/sizer.h"
#include "devices/playbackspeed_processor.h"

class PlaybackSpeedGUI : public wxPanel
{
public:
	PlaybackSpeedGUI(wxWindow* parent, wxWindowID id,
		const wxPoint& pos = wxDefaultPosition, PlaybackSpeedDevice* device = nullptr);

	PlaybackSpeedDevice* getDevice();
	void setDevice(PlaybackSpeedDevice* device);

	void OnPanAdjust(wxCommandEvent& e);
private:
	wxStaticBox* wrap;
	PlaybackSpeedDevice* device;
	wxStaticBoxSizer* sizer;
	wxSlider* speed_control;

	DECLARE_EVENT_TABLE()

};

#endif