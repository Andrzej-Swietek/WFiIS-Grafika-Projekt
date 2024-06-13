//
// Created by andrzej on 22.03.24.
//
#include <wx/wxprec.h>
#include "GUI.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};



wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    SetProcessDPIAware();
    GUI* frame = new GUI(NULL); 
    frame->Show(true);
    return true;
}
