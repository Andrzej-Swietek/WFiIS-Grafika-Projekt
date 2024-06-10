#pragma once

#include <wx/wx.h>
#include <wx/textctrl.h>

#include <vector>
#include <memory>

#include "Shape.hpp"

class ShapeDialog : public wxDialog {
public:
    ShapeDialog(wxWindow* parent, const std::vector<std::unique_ptr<Shape>>& shapes);

private:
    void PopulateShapeList(const std::vector<std::unique_ptr<Shape>>& shapes);
};

