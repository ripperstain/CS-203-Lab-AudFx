#include "EqualizerGUI.h"

const int ID_SPEEDSLIDER = 555;
BEGIN_EVENT_TABLE(EqualizerGUI, wxPanel)
EVT_SLIDER(ID_SPEEDSLIDER, EqualizerGUI::OnLowAdjust)
EVT_SLIDER(ID_SPEEDSLIDER, EqualizerGUI::OnLowMidAdjust)
EVT_SLIDER(ID_SPEEDSLIDER, EqualizerGUI::OnMidAdjust)
EVT_SLIDER(ID_SPEEDSLIDER, EqualizerGUI::OnHighMidAdjust)
EVT_SLIDER(ID_SPEEDSLIDER, EqualizerGUI::OnHighAdjust)
END_EVENT_TABLE()

EqualizerGUI::EqualizerGUI(wxWindow* parent, wxWindowID id,
const wxPoint& pos, Equalizer* dev)
: wxPanel(parent, id, pos, wxSize(200, 100), wxSTATIC_BORDER, wxT("Equalizer"))
{
	if (dev == nullptr){
		device = new Equalizer("EQ");
	}
	else{
		device = dev;
	}


	//Create 'wrap' for Distortion GUI element
	wrap = new wxStaticBox(this, wxID_ANY, wxT("Equalizer"));

	//Set up the sizer for the panel
	sizer = new wxStaticBoxSizer(wrap, wxVERTICAL);

	//Create the enabled/disabled checkbox

	wxFlexGridSizer* tmpSizer = new wxFlexGridSizer(2, 2, 0, 0);
	//Create the slider inputs for the distortion filter (drive and mix)

	/* ****** NOTE******
	Had trouble with the driver slider overlapping the Mix slider value
	Setting border didn't have any effect
	Added padding spaces to Drive and Mix labels to force the spacing and
	remove the overlap
	*/
	//wxStaticText* drvLabel = new wxStaticText(this, wxID_ANY, wxT(" Playback Speed "));
	//tmpSizer->Add(drvLabel, 0, wxALIGN_CENTER, 10);


	low_control = new wxSlider(this, ID_SPEEDSLIDER, 100, 0, 200, wxDefaultPosition, wxDefaultSize,
		wxSL_VERTICAL | wxSL_LABELS | wxSL_INVERSE);
	tmpSizer->Add(low_control, 0, wxALIGN_LEFT, 500);
	lowMid_control = new wxSlider(this, ID_SPEEDSLIDER, 100, 0, 200, wxDefaultPosition, wxDefaultSize,
		wxSL_VERTICAL | wxSL_LABELS | wxSL_INVERSE);
	tmpSizer->Add(lowMid_control, 0, wxALIGN_LEFT, 500);
	mid_control = new wxSlider(this, ID_SPEEDSLIDER, 100, 0, 200, wxDefaultPosition, wxDefaultSize,
		wxSL_VERTICAL | wxSL_LABELS | wxSL_INVERSE);
	tmpSizer->Add(mid_control, 0, wxALIGN_LEFT, 500);
	highMid_control = new wxSlider(this, ID_SPEEDSLIDER, 100, 0, 200, wxDefaultPosition, wxDefaultSize,
		wxSL_VERTICAL | wxSL_LABELS | wxSL_INVERSE);
	tmpSizer->Add(highMid_control, 0, wxALIGN_LEFT, 500);
	high_control = new wxSlider(this, ID_SPEEDSLIDER, 100, 0, 200, wxDefaultPosition, wxDefaultSize,
		wxSL_VERTICAL | wxSL_LABELS | wxSL_INVERSE);
	tmpSizer->Add(high_control, 0, wxALIGN_LEFT, 500);


	sizer->Add(tmpSizer, 0, wxALIGN_CENTER, 5);

	SetSizer(sizer);
	sizer->Fit(this);
	sizer->SetSizeHints(this);
}

Equalizer* EqualizerGUI::getDevice()
{
	return device;
}


void EqualizerGUI::setDevice(Equalizer* device)
{
	if (device != nullptr){
		device = device;
	}
}


void EqualizerGUI::OnLowAdjust(wxCommandEvent& e)
{
	device->setLowGain(((double)low_control->GetValue()) / 100.0f);


}

void EqualizerGUI::OnLowMidAdjust(wxCommandEvent& e)
{
	device->setLowMidGain(((double)lowMid_control->GetValue()) / 100.0f);


}

void EqualizerGUI::OnMidAdjust(wxCommandEvent& e)
{
	device->setMidGain(((double)mid_control->GetValue()) / 100.0f);


}

void EqualizerGUI::OnHighMidAdjust(wxCommandEvent& e)
{
	device->setHighMidGain(((double)highMid_control->GetValue()) / 100.0f);


}

void EqualizerGUI::OnHighAdjust(wxCommandEvent& e)
{
	device->setHighGain(((double)high_control->GetValue()) / 100.0f);


}

