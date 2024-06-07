#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/button.h>

class ShapesPanel : public wxPanel {
public:
    ShapesPanel(wxWindow* parent, const wxString& shapeName, int shapeId);

private:
    void OnHideButtonClick(wxCommandEvent& event);

    int m_shapeId;
    wxStaticText* m_shapeNameLabel;
    wxButton* m_hideButton;

    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_HIDE_BUTTON = 1000
};
