#include "ShapesPanel.hpp"

wxBEGIN_EVENT_TABLE(ShapesPanel, wxPanel)
    EVT_BUTTON(ID_HIDE_BUTTON, ShapesPanel::OnHideButtonClick)
wxEND_EVENT_TABLE()

ShapesPanel::ShapesPanel(wxWindow* parent, const wxString& shapeName, int shapeId)
    : wxPanel(parent, wxID_ANY), m_shapeId(shapeId) {

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    m_shapeNameLabel = new wxStaticText(this, wxID_ANY, shapeName);
    sizer->Add(m_shapeNameLabel, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_hideButton = new wxButton(this, ID_HIDE_BUTTON, wxT("Hide Shape"));
    sizer->Add(m_hideButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    this->SetSizer(sizer);
    this->Layout();
}

void ShapesPanel::OnHideButtonClick(wxCommandEvent& event) {
    wxLogMessage("Hide button clicked for shape ID: %d", m_shapeId);
    // Implement the logic to hide the shape here
}
