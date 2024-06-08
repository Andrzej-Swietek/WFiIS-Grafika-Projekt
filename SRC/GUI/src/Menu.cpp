#include "Menu.hpp"
Menu::Menu(wxFrame* parent) : parentFrame(parent) {
    menuBar = new wxMenuBar;

    // Assign unique IDs
    ID_UP_LAYER = wxID_HIGHEST + 1;
    ID_DOWN_LAYER = wxID_HIGHEST + 2;

    CreateFileMenu();
    CreateEditMenu();
    CreateSettingsMenu();
    CreateHelpMenu();

    parentFrame->SetMenuBar(menuBar);
}

void Menu::CreateFileMenu() {
    fileMenu = new wxMenu;
    fileMenu->Append(wxID_OPEN, "&Open\tCtrl+O");
    fileMenu->Append(wxID_SAVE, "&Save\tCtrl+S");
    fileMenu->Append(wxID_SAVEAS, "Save &As...\tCtrl+Shift+S");
    fileMenu->AppendSeparator();
    fileMenu->Append(wxID_EXIT, "E&xit\tCtrl+Q");
    menuBar->Append(fileMenu, "&File");
}

void Menu::CreateEditMenu() {
    editMenu = new wxMenu;
    editMenu->Append(ID_UP_LAYER, "Up Layer\tCtrl+Up");
    editMenu->Append(ID_DOWN_LAYER, "Down Layer\tCtrl+Down");
    menuBar->Append(editMenu, "&Edit");
}

void Menu::CreateSettingsMenu() {
    settingsMenu = new wxMenu;
    settingsMenu->Append(wxID_ANY, "&Settings");
    menuBar->Append(settingsMenu, "&Settings");
}

void Menu::CreateHelpMenu() {
    helpMenu = new wxMenu;
    helpMenu->Append(wxID_HELP, "&Help\tF1");
    helpMenu->Append(wxID_ABOUT, "&About\tF2");
    helpMenu->AppendSeparator();
    helpMenu->Append(wxID_ANY, "Go to &Docs", "Go to documentation");
    menuBar->Append(helpMenu, "&Help");
}

void Menu::SetOnExitHandler(std::function<void(wxCommandEvent&)> handler) {
    parentFrame->Bind(wxEVT_MENU, handler, wxID_EXIT);
}

void Menu::SetOnOpenHandler(std::function<void(wxCommandEvent&)> handler) {
    parentFrame->Bind(wxEVT_MENU, handler, wxID_OPEN);
}

void Menu::SetOnSaveHandler(std::function<void(wxCommandEvent&)> handler) {
    parentFrame->Bind(wxEVT_MENU, handler, wxID_SAVE);
}

void Menu::SetOnSaveAsHandler(std::function<void(wxCommandEvent&)> handler) {
    parentFrame->Bind(wxEVT_MENU, handler, wxID_SAVEAS);
}

void Menu::SetOnUpLayerHandler(std::function<void(wxCommandEvent&)> handler) {
    parentFrame->Bind(wxEVT_MENU, handler, ID_UP_LAYER);
}

void Menu::SetOnDownLayerHandler(std::function<void(wxCommandEvent&)> handler) {
    parentFrame->Bind(wxEVT_MENU, handler, ID_DOWN_LAYER);
}