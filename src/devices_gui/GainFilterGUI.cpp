#include "GainFilterGUI.h"

const int ID_DRIVESLIDER = 120;
const int ID_MIXSLIDER = 121;
BEGIN_EVENT_TABLE(GainFilterGUI, wxPanel)
EVT_SLIDER(ID_DRIVESLIDER, GainFilterGUI::OnGainAdjust)
END_EVENT_TABLE()

GainFilterGUI::GainFilterGUI(wxWindow* parent, wxWindowID id,
const wxPoint& pos, GainFilter* device)
: wxPanel(parent, id, pos, wxSize(200, 100), wxSTATIC_BORDER, wxT("Gain Filter"))
{
	if (device == nullptr){
		filter = new GainFilter("Gain Filter");
	}
	else{
		filter = device;
	}


	//Create 'wrap' for Distortion GUI element
	wrap = new wxStaticBox(this, wxID_ANY, wxT("Gain Filter"));

	//Set up the sizer for the panel
	sizer = new wxStaticBoxSizer(wrap, wxHORIZONTAL);

	//Create the enabled/disabled checkbox
	
	wxFlexGridSizer* tmpSizer = new wxFlexGridSizer(2, 2, 0, 0);
	//Create the slider inputs for the distortion filter (drive and mix)

	/* ****** NOTE******
	Had trouble with the driver slider overlapping the Mix slider value
	Setting border didn't have any effect
	Added padding spaces to Drive and Mix labels to force the spacing and
	remove the overlap
	*/
	wxStaticText* drvLabel = new wxStaticText(this, wxID_ANY, wxT("  Gain    "));
	tmpSizer->Add(drvLabel, 0, wxALIGN_CENTER, 10);
	

	GainControl = new wxSlider(this, ID_DRIVESLIDER, 20, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);
	tmpSizer->Add(GainControl, 0, wxALIGN_LEFT, 500);
	

	sizer->Add(tmpSizer, 0, wxALIGN_CENTER, 5);
	
	SetSizer(sizer);
	sizer->Fit(this);
	sizer->SetSizeHints(this);
}

GainFilter* GainFilterGUI::getDevice()
{
	return filter;
}


void GainFilterGUI::setDevice(GainFilter* device)
{
	if (device != nullptr){
		filter = device;
	}
}


void GainFilterGUI::OnGainAdjust(wxCommandEvent& e)
{
	filter->setgain(GainControl->GetValue());
	

}

