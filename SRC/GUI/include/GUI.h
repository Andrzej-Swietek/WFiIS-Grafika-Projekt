#pragma once

#include <wx/wxprec.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/statline.h>
#include <wx/clrpicker.h>
#include <wx/scrolwin.h>
#include <wx/frame.h>
#include <wx/filedlg.h>
#include <wx/msgdlg.h>

#include <Shape.hpp>

#include "XMLDataLoaderAdapter.hpp"
#include "Logger.hpp"
#include "ShapesPanel.hpp"
#include "ImageSaver.hpp"

#include "ShapeDialog.hpp"
#include "Menu.hpp"

class GUI : public wxFrame
{
private:

protected:
	wxPanel* m_canvas_panel;
	wxTextCtrl* imageStats;
	wxStaticText* menuLabel;
	wxStaticText* scaleLabel;
	wxSlider* scaleSlider;
	wxStaticText* rotationLabel;
	wxSlider* rotationSlider;
	wxStaticLine* m_staticline11;
	wxStaticText* m_staticText6;
	wxColourPickerCtrl* colorPicker;
	wxStaticText* m_staticText5;
	wxColourPickerCtrl* strokePicker;
	wxStaticLine* m_staticline1;
	wxStaticText* m_staticText7;
	wxSlider* transparencySlider;
	wxStaticText* layersLabel;

	wxStaticText* orderLayersLabel;
	wxButton* upLayerBtn;
	wxButton* downLayerBtn;
	wxButton* listShapesBtn;

	wxStaticText* selectedLabelText;
	wxStaticText* selectedShapeStatus;

	wxScrolledWindow* layersScrolledWindow;
	Menu* menu;


	void updateSelectionStatusDisplay();

public:

	GUI(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("SVG Rasterizer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1024, 708), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~GUI();


	void OnExit(wxCommandEvent& event);
	void OnOpen(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);
	void OnSaveAs(wxCommandEvent& event);
	void OnGoToDocs(wxCommandEvent& event);

	void OnUpLayerButtonClick(wxCommandEvent& event);
	void OnDownLayerButtonClick(wxCommandEvent& event);
	void OnListShapesButtonClick(wxCommandEvent& event);

	void Repaint() const;
	void RefreshLayersDisplay() const;
	void OnPaint(wxPaintEvent& event);
	void DrawShapes(wxDC& dc, int canvWidth, int canvHeight) const;
	void UpdateShapesOnResize();
	void RotationSliderUpdate(wxScrollEvent& event);

	std::vector<std::unique_ptr<Shape>> shapes;
};
