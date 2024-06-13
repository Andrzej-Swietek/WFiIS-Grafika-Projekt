#include "ImageSaverDialog.hpp"

ImageSaverDialog::ImageSaverDialog(wxWindow* parent, int canvasWidth, int canvasHeight)
    : wxDialog(parent, wxID_ANY, "Save Image", wxDefaultPosition, wxSize(250, 150)), canvasWidth(canvasWidth), canvasHeight(canvasHeight) {

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* widthSizer = new wxBoxSizer(wxHORIZONTAL);
    widthSizer->Add(new wxStaticText(this, wxID_ANY, "Width:"), 0, wxALL, 5);
    m_widthCtrl = new wxTextCtrl(this, wxID_ANY, std::to_string(canvasWidth));
    widthSizer->Add(m_widthCtrl, 1, wxALL, 5);

    wxBoxSizer* heightSizer = new wxBoxSizer(wxHORIZONTAL);
    heightSizer->Add(new wxStaticText(this, wxID_ANY, "Height:"), 0, wxALL, 5);
    m_heightCtrl = new wxTextCtrl(this, wxID_ANY, std::to_string(canvasHeight));
    heightSizer->Add(m_heightCtrl, 1, wxALL, 5);

    sizer->Add(widthSizer, 1, wxEXPAND | wxALL, 5);
    sizer->Add(heightSizer, 1, wxEXPAND | wxALL, 5);

    sizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxALIGN_CENTER | wxALL, 5);

    SetSizerAndFit(sizer);
}

int ImageSaverDialog::GetWidth() const {
    long width;
    if (m_widthCtrl->GetValue().ToLong(&width)) {
        return static_cast<int>(width);
    }
    return canvasWidth; // default value if parsing fails
}

int ImageSaverDialog::GetHeight() const {
    long height;
    if (m_heightCtrl->GetValue().ToLong(&height)) {
        return static_cast<int>(height);
    }
    return canvasHeight; // default value if parsing fails
}