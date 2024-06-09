#pragma once
#include <wx/wx.h>

class ImageSaver {
public:
    static ImageSaver* getInstance(wxPanel* drawingPanel);

    void SaveImage(wxWindow* parent);

private:
    ImageSaver(wxPanel* drawingPanel);
    static ImageSaver* instance;

    wxPanel* m_drawingPanel;
};