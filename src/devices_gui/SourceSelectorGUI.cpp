#include "SourceSelectorGUI.h"

const int ID_FILEOPTION = 160;
const int ID_AUDIOINOPTION = 161;
BEGIN_EVENT_TABLE(SourceSelectorGUI, wxPanel)
EVT_RADIOBUTTON(ID_FILEOPTION, SourceSelectorGUI::OnOptionOneSelect)
EVT_RADIOBUTTON(ID_AUDIOINOPTION, SourceSelectorGUI::OnOptionTwoSelect)
END_EVENT_TABLE()

SourceSelectorGUI::SourceSelectorGUI(wxWindow* parent, wxWindowID id,
const wxPoint& pos)
: wxPanel(parent, id, pos, wxSize(400, 100), wxSTATIC_BORDER, wxT("Source Selector"))
{

	file_source_gui = new OpenFileGUI(this, wxID_ANY);
	audio_in_source_gui = new AudioInGUI(this, wxID_ANY);
	audio_in_source_gui->Enable(false);

	panel_wrap = new wxStaticBox(this, wxID_ANY, wxT("Source Selector"));
	//Set up the sizer for the panel
	sizer = new wxStaticBoxSizer(panel_wrap, wxVERTICAL);
	option_one = new wxRadioButton(this, ID_FILEOPTION, wxT(""), wxDefaultPosition, wxDefaultSize);
	option_one->SetValue(true);

	option_two = new wxRadioButton(this, ID_AUDIOINOPTION, wxT(""), wxDefaultPosition, wxDefaultSize);
	wxFlexGridSizer* tmpSizer = new wxFlexGridSizer(2, 2, 5, 5);

	tmpSizer->Add(option_one, 0, 0, 10);
	tmpSizer->Add(file_source_gui, 0, 0, 10);
	tmpSizer->Add(option_two, 0, 0, 10);
	tmpSizer->Add(audio_in_source_gui, 0, 0, 10);

	sizer->Add(tmpSizer);

	SetSizer(sizer);
	sizer->Fit(this);
	sizer->SetSizeHints(this);
}

void SourceSelectorGUI::OnOptionOneSelect(wxCommandEvent& e)
{
	audio_in_source_gui->Enable(false);
	file_source_gui->Enable(true);

}

void SourceSelectorGUI::OnOptionTwoSelect(wxCommandEvent& e)
{
		audio_in_source_gui->Enable(true);
		file_source_gui->Enable(false);
}

AbstractAudio* SourceSelectorGUI::getDevice()
{
	return file_source_gui->getDevice();

}