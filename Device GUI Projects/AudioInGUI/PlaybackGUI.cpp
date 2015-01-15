#include "PlaybackGUI.h"

PlaybackGUI::PlaybackGUI(wxWindow* parent, wxWindowID id, const wxPoint& pos)
: wxPanel(parent, id, pos, wxSize(200, 100), wxSTATIC_BORDER, wxT("Distortion Filter"))
{

	//Create 'wrap' for Distortion GUI element
	wrap = new wxStaticBox(this, wxID_ANY, wxT("Playback"));


	SetSizer(sizer);
	sizer->Fit(this);
	sizer->SetSizeHints(this);
}

