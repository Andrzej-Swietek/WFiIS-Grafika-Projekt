//
// Created by andrzej on 22.03.24.
//
#include <wx/wxprec.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame();
private:
    void OnExit(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnSaveAs(wxCommandEvent& event);
    void OnGoToDocs(wxCommandEvent& event);
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    SetProcessDPIAware();
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "wxStart")
{
    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(wxID_OPEN, "&Open\tCtrl+O");
    fileMenu->Append(wxID_SAVE, "&Save\tCtrl+S");
    fileMenu->Append(wxID_SAVEAS, "Save &As...\tCtrl+Shift+S");
    fileMenu->AppendSeparator();
    fileMenu->Append(wxID_EXIT, "E&xit\tCtrl+Q");
    

    wxMenu* editMenu = new wxMenu;
    editMenu->Append(wxID_COPY, "&Copy\tCtrl+C");
    editMenu->Append(wxID_CUT, "Cu&t\tCtrl+X");
    editMenu->Append(wxID_PASTE, "&Paste\tCtrl+V");


    wxMenu* settingsMenu = new wxMenu;
    settingsMenu->Append(wxID_EXIT);

    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(wxID_HELP, "&Help\tF1");
    helpMenu->Append(wxID_ABOUT, "&About\tF2");
    helpMenu->AppendSeparator();
    helpMenu->Append(wxID_ANY, "Go to &Docs", "Go to documentation");
    helpMenu->Append(wxID_EXIT);


    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(editMenu, "&Edit");
    menuBar->Append(settingsMenu, "&Settings");
    menuBar->Append(helpMenu, "&Help");


    SetMenuBar(menuBar);

    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MyFrame::OnOpen, this, wxID_OPEN);
    Bind(wxEVT_MENU, &MyFrame::OnSave, this, wxID_SAVE);
    Bind(wxEVT_MENU, &MyFrame::OnSaveAs, this, wxID_SAVEAS);
    //Bind(wxEVT_MENU, &MyFrame::OnGoToDocs, this, wxID_ANY);
}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}


void MyFrame::OnOpen(wxCommandEvent& event)
{

}


void MyFrame::OnSave(wxCommandEvent& event)
{

}


void MyFrame::OnSaveAs(wxCommandEvent& event)
{

}

void MyFrame::OnGoToDocs(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("https://docs.wxwidgets.org/");
}