#include "PlaybackGUI.h"

const int ID_CHOICE = 120;
const int ID_PLAYBUTTON = 121;
const int ID_PAUSEBUTTON = 122;
const int ID_STOPBUTTON = 123;

BEGIN_EVENT_TABLE(PlaybackGUI, wxPanel)
EVT_CHOICE(ID_CHOICE, PlaybackGUI::OnDeviceSelect)
EVT_BUTTON(ID_PLAYBUTTON, PlaybackGUI::OnPlay)
EVT_BUTTON(ID_PAUSEBUTTON, PlaybackGUI::OnPause)
EVT_BUTTON(ID_STOPBUTTON, PlaybackGUI::OnStop)
END_EVENT_TABLE()

PlaybackGUI::PlaybackGUI(wxWindow* parent, wxWindowID id, const wxPoint& pos, PCMPlayer* pcmplayer)
: wxPanel(parent, id, pos, wxSize(200, 100), wxSTATIC_BORDER, wxT("Player"))
{

	if (pcmplayer == nullptr){
		player = new PCMPlayer("Player");
	}
	else{
		player = pcmplayer;
	}

	//Create 'wrap' for Distortion GUI element
	wrap = new wxStaticBox(this, wxID_ANY, wxT("Playback"));
	//Set up the sizer for the panel
	sizer = new wxStaticBoxSizer(wrap, wxVERTICAL);


	//Create the device list to select Audio In device
	wxStaticText* drvLabel = new wxStaticText(this, wxID_ANY, wxT("Audio Out Devices"));
	sizer->Add(drvLabel, 0, wxALIGN_CENTER, 10);

	devicelist devices = player->GetDevices();
	wxArrayString devlist;
	for (auto it = devices.begin(); it != devices.end(); ++it){
		devlist.Add(wxString(it->c_str()));
	}
	DeviceList = new wxChoice(this, ID_CHOICE, wxDefaultPosition, wxDefaultSize, devlist);
	sizer->Add(DeviceList, 0, 0, 10);

	//Create Record and Stop buttons (Eventually make this a single button that toggles)
	wxBoxSizer* buttonrow = new wxBoxSizer(wxHORIZONTAL);
	play = new wxButton(this, ID_PLAYBUTTON, wxT("Play"), wxDefaultPosition, wxDefaultSize);
	buttonrow->Add(play, 0, 0, 10);
	pause = new wxButton(this, ID_PAUSEBUTTON, wxT("Pause"), wxDefaultPosition, wxDefaultSize);
	buttonrow->Add(pause, 0, 0, 10);
	stop = new wxButton(this, ID_STOPBUTTON, wxT("Stop"), wxDefaultPosition, wxDefaultSize);
	buttonrow->Add(stop, 0, 0, 10);

	sizer->Add(buttonrow, 0, 0, 10);

	SetSizer(sizer);
	sizer->Fit(this);
	sizer->SetSizeHints(this);
}

PCMPlayer* PlaybackGUI::getDevice()
{
	return player;
}
void PlaybackGUI::setDevice(PCMPlayer* device)
{
	if (device != nullptr){
		player = device;
	}
}

void PlaybackGUI::OnDeviceSelect(wxCommandEvent& e)
{
	player->SelectDevice(e.GetSelection());
}

void PlaybackGUI::OnPlay(wxCommandEvent& e)
{
	player->play();
}

void PlaybackGUI::OnPause(wxCommandEvent& e)
{
	player->pause();
}

void PlaybackGUI::OnStop(wxCommandEvent& e)
{
	player->stop();
}
