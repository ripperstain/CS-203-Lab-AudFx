#include "PlaybackSpeedGUI.h"

const int ID_SPEEDSLIDER = 555;
BEGIN_EVENT_TABLE(PlaybackSpeedGUI, wxPanel)
EVT_SLIDER(ID_SPEEDSLIDER, PlaybackSpeedGUI::OnPanAdjust)
END_EVENT_TABLE()

PlaybackSpeedGUI::PlaybackSpeedGUI(wxWindow* parent, wxWindowID id,
const wxPoint& pos, PlaybackSpeedDevice* dev)
: wxPanel(parent, id, pos, wxSize(200, 100), wxSTATIC_BORDER, wxT("Pan Filter"))
{
	if (dev == nullptr){
		device = new PlaybackSpeedDevice("Playback Speed");
	} else{
		device = dev;
	}


	//Create 'wrap' for Distortion GUI element
	wrap = new wxStaticBox(this, wxID_ANY, wxT("Playback Speed"));

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


	speed_control = new wxSlider(this, ID_SPEEDSLIDER, 100, 0, 200, wxDefaultPosition, wxDefaultSize, 
								wxSL_VERTICAL | wxSL_LABELS | wxSL_INVERSE);
	tmpSizer->Add(speed_control, 0, wxALIGN_LEFT, 500);


	sizer->Add(tmpSizer, 0, wxALIGN_CENTER, 5);

	SetSizer(sizer);
	sizer->Fit(this);
	sizer->SetSizeHints(this);
}

PlaybackSpeedDevice* PlaybackSpeedGUI::getDevice()
{
	return device;
}


void PlaybackSpeedGUI::setDevice(PlaybackSpeedDevice* device)
{
	if (device != nullptr){
		device = device;
	}
}


void PlaybackSpeedGUI::OnPanAdjust(wxCommandEvent& e)
{
	device->SetPlaybackSpeed(((float)speed_control->GetValue()) / 100.0f);


}

