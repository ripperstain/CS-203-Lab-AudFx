#ifndef SOURCESELECTOR_H
#define SOURCESELECTOR_H

#include "wx/wx.h"
#include "wx/choice.h"
#include "wx/sizer.h"
#include "wx/button.h"

#include "devices_GUI/AudioInGUI.h"
#include "devices_GUI/OpenFile_gui.h"

class SourceSelectorGUI : public wxPanel
{
public:
	SourceSelectorGUI(wxWindow* parent, wxWindowID id,
						const wxPoint& pos = wxDefaultPosition);

	AbstractAudio* getDevice();
	void setDevice(MicrophoneReader* device);

	void OnOptionOneSelect(wxCommandEvent& e);
	void OnOptionTwoSelect(wxCommandEvent& e);

private:
	OpenFileGUI*		file_source_gui;
	AudioInGUI*			audio_in_source_gui;
	wxStaticBoxSizer*	sizer;
	wxStaticBox*		panel_wrap;
	wxChoice*			device_list;
	wxRadioButton*		option_one;
	wxRadioButton*		option_two;

	DECLARE_EVENT_TABLE()
};

#endif