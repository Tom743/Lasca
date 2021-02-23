#include "MainWindow.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
	//EVT_Mouse
wxEND_EVENT_TABLE()

MainWindow::MainWindow(): wxFrame(nullptr, wxID_ANY, wxT("Laska"), wxPoint(30, 30), wxSize(800, 600))
{

} 

void MainWindow::OnBoardClicked(wxCommandEvent &event) 
{

}