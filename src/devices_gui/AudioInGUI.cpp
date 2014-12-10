#include "AudioInGUI.h"

const int ID_CHOICE = 120;
const int ID_RECORDBUTTON = 121;
const int ID_STOPBUTTON = 122;

BEGIN_EVENT_TABLE(AudioInGUI, wxPanel)
EVT_CHOICE(ID_CHOICE, AudioInGUI::OnDeviceSelect)
EVT_BUTTON(ID_RECORDBUTTON, AudioInGUI::OnRecord)
EVT_BUTTON(ID_STOPBUTTON, AudioInGUI::OnStop)
END_EVENT_TABLE()

AudioInGUI::AudioInGUI(wxWindow* parent, wxWindowID id,
const wxPoint& pos, MicrophoneReader* device)
: wxPanel(parent, id, pos, wxSize(200, 100), wxSTATIC_BORDER, wxT("Audio In"))
{
	if (device == nullptr){
		filter = new MicrophoneReader("Recorder");
	}
	else{
		filter = device;
	}


	//Create 'wrap' for Distortion GUI element
	wrap = new wxStaticBox(this, wxID_ANY, wxT("Audio In"));

	//Set up the sizer for the panel
	sizer = new wxStaticBoxSizer(wrap, wxVERTICAL);


	//Create the device list to select Audio In device
	wxStaticText* drvLabel = new wxStaticText(this, wxID_ANY, wxT("Audio In Devices"));
	sizer->Add(drvLabel, 0, wxALIGN_CENTER, 10);
	
	devicelist devices = filter->GetDevices();
	wxArrayString devlist;
	for (auto it = devices.begin(); it != devices.end(); ++it){
		devlist.Add(wxString(it->c_str()));
	}
	DeviceList = new wxChoice(this, ID_CHOICE, wxDefaultPosition, wxDefaultSize, devlist);
	sizer->Add(DeviceList, 0, 0, 10);


	//Create Record and Stop buttons (Eventually make this a single button that toggles)
	wxBoxSizer* buttonrow = new wxBoxSizer(wxHORIZONTAL);
	Record = new wxButton(this, ID_RECORDBUTTON, wxT("Record"), wxDefaultPosition, wxDefaultSize);
	buttonrow->Add(Record, 0, 0, 10);
	Stop = new wxButton(this, ID_STOPBUTTON, wxT("Stop"), wxDefaultPosition, wxDefaultSize);
	buttonrow->Add(Stop, 0, 0, 10);

	sizer->Add(buttonrow, 0, 0, 10);

	SetSizer(sizer);
	sizer->Fit(this);
	sizer->SetSizeHints(this);
}

MicrophoneReader* AudioInGUI::getDevice()
{
	return filter;
}


void AudioInGUI::setDevice(MicrophoneReader* device)
{
	if (device != nullptr){
		filter = device;
	}
}

void AudioInGUI::OnDeviceSelect(wxCommandEvent& e)
{
	filter->SelectDevice(e.GetSelection());
}

void AudioInGUI::OnRecord(wxCommandEvent& e)
{
	filter->record();
}

void AudioInGUI::OnStop(wxCommandEvent& e)
{
	filter->stop();
}