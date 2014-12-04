#include "distortion_gui.h"

const int ID_SLIDER = 120;
BEGIN_EVENT_TABLE(DistortionGUI, wxPanel)
EVT_CHECKBOX(wxID_ANY, DistortionGUI::OnchkEnable)
EVT_SLIDER(ID_SLIDER, DistortionGUI::OnDriveAdjust)
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
	sizer->Add(chkEnabled, 0, 0, 4);

	//Create the 'Drive' slider input for the distortion level
	wxStaticText* drvLabel = new wxStaticText(this, wxID_ANY, wxT("Drive"));
	sizer->Add(drvLabel, 0, wxALIGN_CENTER, 10);
	DriveControl = new wxSlider(this, ID_SLIDER, 20, 10, 40, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL | wxSL_LABELS);
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

void DistortionGUI::OnchkEnable(wxCommandEvent& e)
{
	wxMessageBox(wxT("Checkbox Event"),
		"Event Handler",
		wxOK | wxICON_INFORMATION,
		this);

}

void DistortionGUI::OnDriveAdjust(wxCommandEvent& e)
{
	filter->SetDistort(DriveControl->GetValue());
	wxMessageBox(wxString::Format
		("Slider Event: %d", e.GetId()),
		"Event Handler",
		wxOK | wxICON_INFORMATION,
		this);

}