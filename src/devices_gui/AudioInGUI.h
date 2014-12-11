#ifndef AUDIOINGUI_H
#define AUDIOINGUI_H

#include "wx/wx.h"
#include "wx/choice.h"
#include "wx/sizer.h"
#include "wx/button.h"
#include "devices/MicrophoneReader.h"


class AudioInGUI : public wxPanel
{
public:
	AudioInGUI(wxWindow* parent, wxWindowID id,
		const wxPoint& pos = wxDefaultPosition, MicrophoneReader* device = nullptr);

	MicrophoneReader* getDevice();
	void setDevice(MicrophoneReader* device);

	void OnDeviceSelect(wxCommandEvent& e);
	void OnRecord(wxCommandEvent& e);
	void OnStop(wxCommandEvent& e);

private:
	MicrophoneReader* filter;
	wxStaticBoxSizer* sizer;
	wxStaticBox* wrap;
	wxChoice* DeviceList;
	wxButton* Record;
	wxButton* Stop;

	DECLARE_EVENT_TABLE()
};

#endif