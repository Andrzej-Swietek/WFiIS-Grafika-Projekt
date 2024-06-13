#pragma once
#include <wx/wx.h>


/**
 * @class ImageSaver
 * @brief Singleton class for saving an image of a drawing panel.
 */
class ImageSaver {
public:
    /**
     * @brief Get the singleton instance of ImageSaver.
     *
     * @param drawingPanel Pointer to the drawing panel to save.
     * @return ImageSaver* Singleton instance of ImageSaver.
     */
    static ImageSaver* getInstance(wxPanel* drawingPanel);


    /**
     * @brief Save an image of the drawing panel.
     *
     * @param parent Pointer to the parent window.
     */
    void SaveImage(wxWindow* parent);

private:
    /**
     * @brief Private constructor for ImageSaver.
     *
     * @param drawingPanel Pointer to the drawing panel to save.
     */
    ImageSaver(wxPanel* drawingPanel);
    static ImageSaver* instance;

    wxPanel* m_drawingPanel;
};