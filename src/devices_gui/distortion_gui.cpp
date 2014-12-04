#include "distortion_gui.h"

const int ID_DRIVESLIDER = 120;
const int ID_MIXSLIDER = 121;
BEGIN_EVENT_TABLE(DistortionGUI, wxPanel)
EVT_CHECKBOX(wxID_ANY, DistortionGUI::OnchkEnable)
EVT_SLIDER(ID_DRIVESLIDER, DistortionGUI::OnDriveAdjust)
EVT_SLIDER(ID_MIXSLIDER, DistortionGUI::OnMixAdjust)
END_EVENT_TABLE()

DistortionGUI::DistortionGUI(wxWindow* parent, wxWindowID id,
	const wxPoint& pos, DistortionFilter* device)
	: wxPanel(parent, id, pos, wxSize(200, 100), wxSTATIC_BORDER, wxT("Distortion Filter"))
{
	if (device == nullptr){
		filter = new DistortionFilter("Distortion Filter");
	}
	else{
		filter = device;
	}


	//Create 'wrap' for Distortion GUI element
	wrap = new wxStaticBox(this, wxID_ANY, wxT("Distortion Filter"));

	//Set up the sizer for the panel
	sizer = new wxStaticBoxSizer(wrap, wxVERTICAL);

	//Create the enabled/disabled checkbox
	chkEnabled = new wxCheckBox(this, wxID_ANY, wxT("&Enabled"), wxDefaultPosition, wxDefaultSize);
	chkEnabled->SetValue(true);

	wxFlexGridSizer* tmpSizer = new wxFlexGridSizer(2, 2, 0, 0);
	//Create the slider inputs for the distortion filter (drive and mix)

	/* ****** NOTE******
	Had trouble with the driver slider overlapping the Mix slider value
	Setting border didn't have any effect
	Added padding spaces to Drive and Mix labels to force the spacing and
	remove the overlap
	*/
	wxStaticText* drvLabel = new wxStaticText(this, wxID_ANY, wxT("  Drive    "));
	tmpSizer->Add(drvLabel, 0, wxALIGN_CENTER, 10);
	wxStaticText* mixLabel = new wxStaticText(this, wxID_ANY, wxT("    Mix  "));
	tmpSizer->Add(mixLabel, 0, wxALIGN_CENTER, 10);

	DriveSlider = new wxSlider(this, ID_DRIVESLIDER, 20, 10, 40, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL | wxSL_LABELS);
	tmpSizer->Add(DriveSlider, 0, wxALIGN_LEFT, 500);
	MixSlider = new wxSlider(this, ID_MIXSLIDER, 80, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL | wxSL_LABELS);
	tmpSizer->Add(MixSlider, 0, wxALIGN_RIGHT, 500);

	sizer->Add(tmpSizer, 0, wxALIGN_CENTER, 5);
	sizer->Add(chkEnabled, 0, wxALIGN_RIGHT, 4);

	SetSizer(sizer);
	sizer->Fit(this);
	sizer->SetSizeHints(this);
}

AbstractAudio* DistortionGUI::getDevice()
{
	return filter;
}


void DistortionGUI::setDevice(DistortionFilter* device)
{
	if (device != nullptr){
		filter = device;
	}
}

void DistortionGUI::OnchkEnable(wxCommandEvent& e)
{
	filter->Enable(chkEnabled->GetValue());
	/*wxMessageBox(wxString::Format
		("Checkbox Event: %d", (filter->isEnabled() ? 1 : 0)),
		"Event Handler",
		wxOK | wxICON_INFORMATION,
		this);*/

}

void DistortionGUI::OnDriveAdjust(wxCommandEvent& e)
{
	filter->SetDistort(DriveSlider->GetValue());
	/*wxMessageBox(wxString::Format
		("Drive Slider Event: %f", filter->GetDistort()),
		"Event Handler",
		wxOK | wxICON_INFORMATION,
		this);*/

}

void DistortionGUI::OnMixAdjust(wxCommandEvent& e)
{
	float mix = (float)MixSlider->GetValue() / 100.0f;
	filter->SetMix(mix);
	/*wxMessageBox(wxString::Format
		("Mix Slider Event: %f", filter->GetMix()),
		"Event Handler",
		wxOK | wxICON_INFORMATION,
		this);*/
}