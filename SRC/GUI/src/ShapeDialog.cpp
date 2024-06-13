#include "ShapeDialog.hpp"


ShapeDialog::ShapeDialog(wxWindow* parent, const std::vector<std::unique_ptr<Shape>>& shapes)
    : wxDialog(parent, wxID_ANY, "Shape List", wxDefaultPosition, wxSize(500, 800)) {
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    wxTextCtrl *textCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);

    sizer->Add(textCtrl, 1, wxEXPAND | wxALL, 10);
    SetSizer(sizer);

    PopulateShapeList(shapes);
}

void ShapeDialog::PopulateShapeList(const std::vector<std::unique_ptr<Shape>>& shapes) {
    wxTextCtrl* textCtrl = dynamic_cast<wxTextCtrl*>(GetSizer()->GetItem((size_t)0)->GetWindow());

    for (const auto& shape : shapes) {
        textCtrl->AppendText(shape->toString() + "\n");
    }
}
