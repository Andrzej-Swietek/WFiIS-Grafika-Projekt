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

#include "XMLDataLoaderAdapter.hpp"
#include "Logger.hpp"

class GUI : public wxFrame
{
private:

protected:
	wxPanel* m_panel1;
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
	wxScrolledWindow* layersScrolledWindow;

public:

	GUI(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("SVG Rasterizer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1024, 708), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~GUI();

	void setUpMenu();


	void OnExit(wxCommandEvent& event);
	void OnOpen(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);
	void OnSaveAs(wxCommandEvent& event);
	void OnGoToDocs(wxCommandEvent& event);

};