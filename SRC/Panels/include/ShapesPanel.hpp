#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/button.h>

#include <functional>

#include "SelectionManager.hpp"


/**
 * @class ShapesPanel
 * @brief Panel displaying information and controls for a specific shape.
 */
class ShapesPanel : public wxPanel {
public:

    /**
     * @brief Construct a new ShapesPanel object.
     *
     * @param parent Parent window.
     * @param shapeName Name of the shape.
     * @param shapeId Unique ID of the shape.
     * @return no return
     */
    ShapesPanel(wxWindow* parent, const wxString& shapeName, int shapeId);


    /**
     * @brief Set the callback function for shape selection.
     *
     * @param callback Function to call when the shape is selected.
     * @return void
     */
    void SetSelectionCallback(std::function<void()> callback);


    /**
     * @brief Set the callback function for hiding the shape.
     *
     * @param callback Function to call when hiding the shape.
     * @return void
     */

    void SetHideCallback(std::function<void()> callback);

private:
    /**
     * @brief Event handler for the hide button click event.
     *
     * @param event Button click event.
     * @return void
     */
    void OnHideButtonClick(wxCommandEvent& event);


    /**
     * @brief Event handler for selecting the shape.
     *
     * @param event Button click event.
     * @return void
     */
    void SelectShape(wxCommandEvent& event);

    int m_shapeId;
    wxStaticText* m_shapeNameLabel;
    wxButton* m_selectButton;
    wxButton* m_hideButton;

    std::function<void()> selectionCallback;
    std::function<void()> hideCallback;

    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_HIDE_BUTTON = 1000,
    ID_SELECT_BUTTON = 1001
};
