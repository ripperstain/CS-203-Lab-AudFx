#ifndef PLAYBACK_GUI_H
#define PLAYBACK_GUI_H

#include "devices/PCMPlayer.h"
#include "wx/wx.h"
#include "wx/button.h"
#include "wx/choice.h"
#include "wx/sizer.h"


class PlaybackGUI : public wxPanel
{
public:
	PlaybackGUI(wxWindow* parent, wxWindowID id,
		const wxPoint& pos = wxDefaultPosition, PCMPlayer* pcmplayer = nullptr);

	PCMPlayer* getDevice();
	void setDevice(PCMPlayer* device);

	void OnDeviceSelect(wxCommandEvent& e);
	void OnPlay(wxCommandEvent& e);
	void OnPause(wxCommandEvent& e);
	void OnStop(wxCommandEvent& e);

private:
	PCMPlayer* player;
	wxStaticBoxSizer* sizer;
	wxStaticBox* wrap;
	wxButton* play;
	wxButton* pause;
	wxButton* stop;
	wxChoice* DeviceList;

	DECLARE_EVENT_TABLE()
};

#endif