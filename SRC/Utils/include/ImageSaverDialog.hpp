#pragma once
#include <wx/wx.h>


/**
 * @class ImageSaverDialog
 * @brief Dialog for specifying dimensions to save an image.
 */
class ImageSaverDialog : public wxDialog {
public:
    /**
     * @brief Constructor for ImageSaverDialog.
     *
     * @param parent Pointer to the parent window.
     * @param canvasWidth Width of the canvas to save.
     * @param canvasHeight Height of the canvas to save.
     */
    ImageSaverDialog(wxWindow* parent, int canvasWidth, int canvasHeight);


    /**
     * @brief Get the width entered in the dialog.
     *
     * @return int Width entered in the dialog.
     */
    int GetWidth() const;


    /**
     * @brief Get the height entered in the dialog.
     *
     * @return int Height entered in the dialog.
     */
    int GetHeight() const;

private:
    wxTextCtrl* m_widthCtrl;
    wxTextCtrl* m_heightCtrl;
    int canvasWidth;
    int canvasHeight;
};