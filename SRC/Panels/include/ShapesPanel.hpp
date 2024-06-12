#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/button.h>

#include <functional>

#include "SelectionManager.hpp"

class ShapesPanel : public wxPanel {
public:
    ShapesPanel(wxWindow* parent, const wxString& shapeName, int shapeId);

    void SetSelectionCallback(std::function<void()> callback);

    void SetHideCallback(std::function<void()> callback);

private:
    void OnHideButtonClick(wxCommandEvent& event);
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
