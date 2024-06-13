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


/**
 * @class GUI
 * @brief Main graphical user interface (GUI) class for SVG Rasterizer application.
 *
 * This class represents the main window of the application, containing panels, controls, and
 * event handlers for managing shapes, layers, and user interactions. It integrates with various
 * wxWidgets components to provide a graphical interface for creating, editing, and manipulating
 * vector shapes such as circles, curves, polygons, and lines.
 */
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

	wxBoxSizer* vertexEditorSizer;
	wxScrolledWindow* vertexEditorScrolledWindow;


	void updateSelectionStatusDisplay();
	void PopulateVertexEditor();

public:
	/// CONSTRUCTORS & DESTRUCTORS
	
	 /**
	 * @brief Construct a new GUI object.
	 *
	 * @param parent Parent window.
	 * @param id Window ID.
	 * @param title Title of the window.
	 * @param pos Position of the window.
	 * @param size Size of the window.
	 * @param style Window style.
	 * @return no return
	 */
	GUI(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("SVG Rasterizer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1024, 708), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);


	/**
	 * @brief Destroy the GUI object.
	 * @return no return
	 */
	~GUI();


	/**
	 * @brief Handle the exit event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnExit(wxCommandEvent& event);


	/**
	 * @brief Handle the open file event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnOpen(wxCommandEvent& event);


	/**
	 * @brief Handle the save file event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnSave(wxCommandEvent& event);


	/**
	 * @brief Handle the save as file event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnSaveAs(wxCommandEvent& event);


	/**
	 * @brief Handle the go to documentation event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnGoToDocs(wxCommandEvent& event);


	/**
	 * @brief Handle the resize event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnSize(wxSizeEvent& event);


	/**
	 * @brief Handle the up layer button click event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnUpLayerButtonClick(wxCommandEvent& event);


	/**
	 * @brief Handle the down layer button click event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnDownLayerButtonClick(wxCommandEvent& event);


	/**
	 * @brief Handle the list shapes button click event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnListShapesButtonClick(wxCommandEvent& event);


	/**
	 * @brief Handle the stroke color picker change event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnStrokePickerChange(wxColourPickerEvent& event);


	/**
	 * @brief Handle the fill color picker change event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnFillPickerChange(wxColourPickerEvent& event);


	/**
	 * @brief Handle the scale slider change event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnScaleSliderChange(wxScrollEvent& event);


	/**
	 * @brief Handle the vertex text change event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnVertexTextChange(wxCommandEvent& event);


	/**
	 * @brief Handle the paint event.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void OnPaint(wxPaintEvent& event);


	/**
	 * @brief Repaint the canvas.
	 * @return no return
	 */
	void Repaint() const;


	/**
	 * @brief Refresh the display of layers.
	 * @return no return
	 */
	void RefreshLayersDisplay();


	/**
	 * @brief Draw the shapes on the canvas.
	 *
	 * @param dc Device context for drawing.
	 * @param canvWidth Width of the canvas.
	 * @param canvHeight Height of the canvas.
	 * @return no return
	 */
	void DrawShapes(wxDC& dc, int canvWidth, int canvHeight) const;


	/**
	 * @brief Update the rotation slider value.
	 *
	 * @param event Event object.
	 * @return no return
	 */
	void RotationSliderUpdate(wxScrollEvent& event);

	// Vector to store shapes
	std::vector<std::unique_ptr<Shape>> shapes;

	// Vectors to store vertex fields
	std::vector<wxTextCtrl*> m_vertexXFields;
	std::vector<wxTextCtrl*> m_vertexYFields;
};
