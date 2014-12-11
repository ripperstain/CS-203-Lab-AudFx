
#include "wx/wx.h"
#include "wx/checkbox.h"
#include "wx/slider.h"
#include "wx/sizer.h"
#include "devices/WavReader.h"

class OpenFileGUI : public wxPanel
{
public:
	OpenFileGUI(wxWindow* parent, wxWindowID id,
		const wxPoint& pos = wxDefaultPosition);

	WavReader* getDevice();
	void setDevice(WavReader* device);

	void OpenFile(wxCommandEvent& e);

	wxString CurrentDocPath;

private:
	WavReader *reader;
	wxStaticBoxSizer* sizer;
	wxStaticBox* wrap;
	wxButton* browse;


	DECLARE_EVENT_TABLE()
};

