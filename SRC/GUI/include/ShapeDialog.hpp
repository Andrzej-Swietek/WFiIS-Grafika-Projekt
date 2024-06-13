#pragma once

#include <wx/wx.h>
#include <wx/textctrl.h>

#include <vector>
#include <memory>

#include "Shape.hpp"



/**
 * @class ShapeDialog
 * @brief Dialog window for displaying a list of shapes.
 */
class ShapeDialog : public wxDialog {
public:


    /**
     * @brief Construct a new ShapeDialog object.
     *
     * @param parent Parent window.
     * @param shapes Vector of shapes to display.
     * @return no return
     */

    ShapeDialog(wxWindow* parent, const std::vector<std::unique_ptr<Shape>>& shapes);

private:


    /**
     * @brief Populate the shape list in the dialog.
     *
     * @param shapes Vector of shapes to populate the list with.
     * @return no return
     */
    void PopulateShapeList(const std::vector<std::unique_ptr<Shape>>& shapes);
};

