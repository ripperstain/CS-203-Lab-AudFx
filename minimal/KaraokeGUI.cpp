#include "KaraokeGUI.h"

const int ID_DRIVESLIDER = 120;
const int ID_MIXSLIDER = 121;
BEGIN_EVENT_TABLE(KaraokeGUI, wxPanel)
EVT_CHECKBOX(wxID_ANY, KaraokeGUI::OnchkEnable)
END_EVENT_TABLE()

KaraokeGUI::KaraokeGUI(wxWindow* parent, wxWindowID id,
const wxPoint& pos, KaraokeProcessor* device)
: wxPanel(parent, id, pos, wxSize(200, 100), wxSTATIC_BORDER, wxT("Karaoke Processor"))
{
	if (device == nullptr){
		filter = new KaraokeProcessor("Karaoke Processor");
	}
	else{
		filter = device;
	}


	//Create 'wrap' for Karaoke GUI element
	wrap = new wxStaticBox(this, wxID_ANY, wxT("Karaoke Processor"));

	//Set up the sizer for the panel
	sizer = new wxStaticBoxSizer(wrap, wxVERTICAL);

	//Create the enabled/disabled checkbox
	chkEnabled = new wxCheckBox(this, wxID_ANY, wxT("&Enabled"), wxDefaultPosition, wxDefaultSize);
	chkEnabled->SetValue(true);

	wxFlexGridSizer* tmpSizer = new wxFlexGridSizer(2, 2, 0, 0);


	sizer->Add(tmpSizer, 0, wxALIGN_CENTER, 5);
	sizer->Add(chkEnabled, 0, wxALIGN_RIGHT, 4);

	SetSizer(sizer);
	sizer->Fit(this);
	sizer->SetSizeHints(this);
}

AbstractAudio* KaraokeGUI::getDevice()
{
	return filter;
}


void KaraokeGUI::setDevice(KaraokeProcessor* device)
{
	if (device != nullptr){
		filter = device;
	}
}

void KaraokeGUI::OnchkEnable(wxCommandEvent& e)
{
	filter->Enable(chkEnabled->GetValue());
	/*wxMessageBox(wxString::Format
	("Checkbox Event: %d", (filter->isEnabled() ? 1 : 0)),
	"Event Handler",
	wxOK | wxICON_INFORMATION,
	this);*/

}
