#include <wx/wx.h>

class MainWindow: public wxFrame
{
public:
	MainWindow();

	void OnBoardClicked(wxCommandEvent &event);

	wxDECLARE_EVENT_TABLE();
};