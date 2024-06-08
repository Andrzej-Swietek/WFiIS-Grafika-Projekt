#pragma once 

#include <wx/wx.h>
#include <functional>


class Menu {
public:
    Menu(wxFrame* parent);
    void SetOnExitHandler(std::function<void(wxCommandEvent&)> handler);
    void SetOnOpenHandler(std::function<void(wxCommandEvent&)> handler);
    void SetOnSaveHandler(std::function<void(wxCommandEvent&)> handler);
    void SetOnSaveAsHandler(std::function<void(wxCommandEvent&)> handler);
    void SetOnUpLayerHandler(std::function<void(wxCommandEvent&)> handler);
    void SetOnDownLayerHandler(std::function<void(wxCommandEvent&)> handler);


    int ID_UP_LAYER;
    int ID_DOWN_LAYER;

private:
    wxFrame* parentFrame;
    wxMenuBar* menuBar;
    wxMenu* fileMenu;
    wxMenu* editMenu;
    wxMenu* settingsMenu;
    wxMenu* helpMenu;

    void CreateFileMenu();
    void CreateEditMenu();
    void CreateSettingsMenu();
    void CreateHelpMenu();
};