#include "distortion_gui.h"

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
	sizer->Add(chkEnabled, 0, 0, 4);

	//Create the 'Drive' slider input for the distortion level
	wxStaticText* drvLabel = new wxStaticText(this, wxID_ANY, wxT("  Drive"));
	sizer->Add(drvLabel, 0, wxALIGN_CENTER, 10);
	DriveControl = new wxSlider(this, wxID_ANY, 20, 10, 40, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL | wxSL_LABELS);
	sizer->Add(DriveControl, 0, wxALIGN_CENTER, 5);

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
