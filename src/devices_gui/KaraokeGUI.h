#ifndef KARAOKEGUI_H
#define KARAOKEGUI_H

#include "wx/wx.h"
#include "wx/checkbox.h"
#include "wx/sizer.h"
#include "devices/KaraokeProcessor.h"


class KaraokeGUI : public wxPanel
{
public:
	KaraokeGUI(wxWindow* parent, wxWindowID id,
		const wxPoint& pos = wxDefaultPosition, KaraokeProcessor* device = nullptr);

	KaraokeProcessor* getDevice();
	void setDevice(KaraokeProcessor* device);

	void OnchkEnable(wxCommandEvent& e);

private:
	KaraokeProcessor* filter;
	wxStaticBoxSizer* sizer;
	wxStaticBox* wrap;
	wxCheckBox* chkEnabled;

	DECLARE_EVENT_TABLE()
};

#endif