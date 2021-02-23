#include "MainWindow.h"
#include "App.h"
#include <wx/wx.h>

bool App::OnInit()
{
	if (!wxApp::OnInit()) return false;

	MainWindow *main = new MainWindow();
	main->Show(true);

	return true;
}



wxIMPLEMENT_APP(App);



