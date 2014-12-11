#ifndef PLAYBACK_GUI_H
#define PLAYBACK_GUI_H

#include "wx/wx.h"
#include "wx/checkbox.h"
#include "wx/slider.h"
#include "wx/sizer.h"


class PlaybackGUI : public wxPanel
{
public:
	PlaybackGUI(wxWindow* parent, wxWindowID id,
		const wxPoint& pos = wxDefaultPosition);


private:
	wxStaticBoxSizer* sizer;
	wxStaticBox* wrap;
	wxButton* play;

	DECLARE_EVENT_TABLE()
};

#endif