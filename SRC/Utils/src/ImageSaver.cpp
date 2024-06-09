#include "ImageSaver.hpp"
#include "ImageSaverDialog.hpp"

ImageSaver::ImageSaver(wxPanel* drawingPanel)
    : m_drawingPanel(drawingPanel) {
}

// Initialize the static member
ImageSaver* ImageSaver::instance = nullptr;

ImageSaver* ImageSaver::getInstance(wxPanel* drawingPanel) {
    if (instance == nullptr) {
        instance = new ImageSaver(drawingPanel);
    }
    return instance;
}

void ImageSaver::SaveImage(wxWindow* parent) {

    // get the size of the drawing panel
    wxSize panelSize = m_drawingPanel->GetSize();
    int panelWidth = panelSize.GetWidth();
    int panelHeight = panelSize.GetHeight();

    // launch prompt dialog
    ImageSaverDialog dlg(parent, panelWidth, panelHeight);
    if (dlg.ShowModal() == wxID_OK) {
        int targetWidth = dlg.GetWidth();
        int targetHeight = dlg.GetHeight();

        wxFileDialog saveFileDialog(parent, _("Save BMP file"), "", "", "BMP files (*.bmp)|*.bmp", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
        if (saveFileDialog.ShowModal() == wxID_CANCEL) {
            return;
        }

        wxString filePath = saveFileDialog.GetPath();

        // create a bitmap with the size of the drawing panel
        wxBitmap bitmap(panelWidth, panelHeight);
        wxMemoryDC memDC(bitmap);
        memDC.SetBackground(*wxWHITE_BRUSH);
        memDC.Clear();

        // Blit the content of the drawing panel to the memory DC
        wxClientDC dc(m_drawingPanel);
        m_drawingPanel->PrepareDC(dc);
        memDC.Blit(0, 0, panelWidth, panelHeight, &dc, 0, 0);

        memDC.SelectObject(wxNullBitmap);

        // rescale the bitmap to the target size
        wxImage image = bitmap.ConvertToImage();
        image.Rescale(targetWidth, targetHeight);

        // save the rescaled image as a BMP file
        image.SaveFile(filePath, wxBITMAP_TYPE_BMP);
        wxMessageBox("Image saved successfully", "Info", wxOK | wxICON_INFORMATION);
    }
}