#pragma once
#include <wx/wx.h>

class ImageSaverDialog : public wxDialog {
public:
    ImageSaverDialog(wxWindow* parent, int canvasWidth, int canvasHeight);

    int GetWidth() const;
    int GetHeight() const;

private:
    wxTextCtrl* m_widthCtrl;
    wxTextCtrl* m_heightCtrl;
    int canvasWidth;
    int canvasHeight;
};