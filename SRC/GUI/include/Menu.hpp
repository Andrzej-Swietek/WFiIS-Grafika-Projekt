#pragma once 

#include <wx/wx.h>
#include <functional>

/**
 * @brief The Menu class for the SVG Rasterizer application.
 */
class Menu {
public:
    /**
     * @brief Construct a new Menu object.
     * 
     * @param parent Parent frame.
     * @return no return
     */
    Menu(wxFrame* parent);

    /**
     * @brief Set the handler for the exit menu item.
     * 
     * @param handler Function to handle exit events.
     * @return no return
     */
    void SetOnExitHandler(std::function<void(wxCommandEvent&)> handler);

    /**
     * @brief Set the handler for the open menu item.
     * 
     * @param handler Function to handle open events.
     * @return no return
     */
    void SetOnOpenHandler(std::function<void(wxCommandEvent&)> handler);

    /**
     * @brief Set the handler for the save menu item.
     * 
     * @param handler Function to handle save events.
     * @return no return
     */
    void SetOnSaveHandler(std::function<void(wxCommandEvent&)> handler);

    /**
     * @brief Set the handler for the save as menu item.
     * 
     * @param handler Function to handle save as events.
     * @return no return
     */
    void SetOnSaveAsHandler(std::function<void(wxCommandEvent&)> handler);

    /**
     * @brief Set the handler for the up layer menu item.
     * 
     * @param handler Function to handle up layer events.
     * @return no return
     */
    void SetOnUpLayerHandler(std::function<void(wxCommandEvent&)> handler);


    /**
     * @brief Set the handler for the down layer menu item.
     *
     * @param handler Function to handle down layer events.
     * @return no return
     */
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


    /**
     * @brief Create the file menu.
     * @return no return
     */
    void CreateFileMenu();


    /**
     * @brief Create the edit menu.
     * @return no return
     */
    void CreateEditMenu();


    /**
     * @brief Create the settings menu.
     * @return no return
     */
    void CreateSettingsMenu();


    /**
     * @brief Create the help menu.
     * @return no return
     */
    void CreateHelpMenu();
};