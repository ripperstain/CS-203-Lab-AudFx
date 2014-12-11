#include "OpenFile_gui.h"

const int ID_DRIVESLIDER = 120;
const int ID_MIXSLIDER = 121;
BEGIN_EVENT_TABLE(OpenFileGUI, wxPanel)
EVT_BUTTON(wxFD_OPEN, OpenFileGUI::OpenFile)
END_EVENT_TABLE()

OpenFileGUI::OpenFileGUI(wxWindow* parent, wxWindowID id,
const wxPoint& pos)
: wxPanel(parent, id, pos, wxSize(400, 100), wxSTATIC_BORDER, wxT("Open File"))
{
	//Create 'wrap' for Open File GUI element
	wrap = new wxStaticBox(this, wxID_ANY, wxT("Open File"),wxDefaultPosition,wxSize(400,100));

	//Set up the sizer for the panel
	sizer = new wxStaticBoxSizer(wrap, wxVERTICAL);

	wxFlexGridSizer* tmpSizer = new wxFlexGridSizer(4, 3, 2, 0);


	wxStaticText* drvLabel = new wxStaticText(this, wxID_ANY, wxT("File: "));
	tmpSizer->Add(drvLabel, 0, wxALIGN_CENTER, 10);
	wxStaticText* mixLabel = new wxStaticText(this, wxID_ANY, wxT(""));
	tmpSizer->Add(mixLabel, 0, wxALIGN_CENTER, 10);
	wxButton* openFileDialog = new wxButton(this, wxFD_OPEN, wxT("..."));
	tmpSizer->Add(openFileDialog, 0, wxALIGN_CENTER, 10);


	sizer->Add(tmpSizer, 0, wxALIGN_CENTER, 5);


	SetSizer(sizer);
	sizer->Fit(this);
	sizer->SetSizeHints(this);
}

void OpenFileGUI::OpenFile(wxCommandEvent& e)
{
	wxFileDialog *OpenDialog = new wxFileDialog(
		this, wxT("Choose a file to open"), wxEmptyString, wxEmptyString,
		wxT("Wav File (*.wav)|*.wav|All Files (*.*)|*.*"),
		wxFD_OPEN, wxDefaultPosition);

	// Creates a "open file" dialog with 4 file types
	if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
	{
		CurrentDocPath = OpenDialog->GetPath();
	}
}