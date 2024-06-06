#include "GUI.h"


GUI::GUI(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->setUpMenu();
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* canvasesSizer;
	canvasesSizer = new wxBoxSizer(wxVERTICAL);

	m_panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel1->SetBackgroundColour(wxColour(255, 255, 255));

	canvasesSizer->Add(m_panel1, 4, wxEXPAND | wxALL, 5);

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer(wxHORIZONTAL);

	imageStats = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
	imageStats->SetForegroundColour(wxColour(255, 255, 255));
	imageStats->SetBackgroundColour(wxColour(33, 35, 27));

	bSizer15->Add(imageStats, 1, wxALL, 5);


	canvasesSizer->Add(bSizer15, 1, wxEXPAND, 5);


	mainSizer->Add(canvasesSizer, 6, wxEXPAND, 5);

	wxBoxSizer* controlsSizer;
	controlsSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* controlsInnerSizer;
	controlsInnerSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* transformationsLabelSizer;
	transformationsLabelSizer = new wxBoxSizer(wxHORIZONTAL);

	menuLabel = new wxStaticText(this, wxID_ANY, wxT("\nTransformations"), wxPoint(-1, -1), wxSize(-1, 50), wxALIGN_CENTER_HORIZONTAL);
	menuLabel->Wrap(-1);
	menuLabel->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial")));
	menuLabel->SetForegroundColour(wxColour(255, 255, 255));
	menuLabel->SetBackgroundColour(wxColour(33, 33, 33));

	transformationsLabelSizer->Add(menuLabel, 1, wxALIGN_TOP | wxALL, 5);


	controlsInnerSizer->Add(transformationsLabelSizer, 1, wxEXPAND, 5);

	wxBoxSizer* scaleSizer;
	scaleSizer = new wxBoxSizer(wxVERTICAL);

	scaleLabel = new wxStaticText(this, wxID_ANY, wxT("Scale:"), wxDefaultPosition, wxDefaultSize, 0);
	scaleLabel->Wrap(-1);
	scaleLabel->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

	scaleSizer->Add(scaleLabel, 0, wxALL, 5);

	wxBoxSizer* bSizer142;
	bSizer142 = new wxBoxSizer(wxHORIZONTAL);

	scaleSlider = new wxSlider(this, wxID_ANY, 100, 0, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);
	bSizer142->Add(scaleSlider, 1, wxALIGN_CENTER | wxALL, 5);


	scaleSizer->Add(bSizer142, 1, wxEXPAND, 5);


	controlsInnerSizer->Add(scaleSizer, 1, wxEXPAND, 5);

	wxBoxSizer* rotationSizer;
	rotationSizer = new wxBoxSizer(wxVERTICAL);

	rotationLabel = new wxStaticText(this, wxID_ANY, wxT("Rotation:"), wxDefaultPosition, wxDefaultSize, 0);
	rotationLabel->Wrap(-1);
	rotationLabel->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

	rotationSizer->Add(rotationLabel, 0, wxALL, 5);

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer(wxHORIZONTAL);

	rotationSlider = new wxSlider(this, wxID_ANY, 0, 0, 360, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);
	bSizer141->Add(rotationSlider, 1, wxALIGN_CENTER | wxALL, 5);


	rotationSizer->Add(bSizer141, 1, wxEXPAND, 5);


	controlsInnerSizer->Add(rotationSizer, 1, wxEXPAND, 5);

	m_staticline11 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	controlsInnerSizer->Add(m_staticline11, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* colorsSizer;
	colorsSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* colorSizer;
	colorSizer = new wxBoxSizer(wxHORIZONTAL);

	m_staticText6 = new wxStaticText(this, wxID_ANY, wxT("Color:"), wxPoint(-1, -1), wxDefaultSize, 0);
	m_staticText6->Wrap(-1);
	m_staticText6->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

	colorSizer->Add(m_staticText6, 0, wxALIGN_CENTER | wxALL, 5);

	colorPicker = new wxColourPickerCtrl(this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE);
	colorSizer->Add(colorPicker, 0, wxALIGN_CENTER | wxALL, 5);


	colorsSizer->Add(colorSizer, 1, wxEXPAND, 5);

	wxBoxSizer* strokeSizer;
	strokeSizer = new wxBoxSizer(wxHORIZONTAL);

	m_staticText5 = new wxStaticText(this, wxID_ANY, wxT("Stroke:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText5->Wrap(-1);
	m_staticText5->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

	strokeSizer->Add(m_staticText5, 0, wxALIGN_CENTER | wxALL, 5);

	strokePicker = new wxColourPickerCtrl(this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE);
	strokeSizer->Add(strokePicker, 0, wxALIGN_CENTER | wxALL, 5);


	colorsSizer->Add(strokeSizer, 1, wxEXPAND, 5);


	controlsInnerSizer->Add(colorsSizer, 0, wxEXPAND, 5);

	m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	controlsInnerSizer->Add(m_staticline1, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* transparencySizer;
	transparencySizer = new wxBoxSizer(wxVERTICAL);

	m_staticText7 = new wxStaticText(this, wxID_ANY, wxT("Transparency:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText7->Wrap(-1);
	m_staticText7->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

	transparencySizer->Add(m_staticText7, 0, wxALL, 5);

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer(wxHORIZONTAL);

	transparencySlider = new wxSlider(this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);
	bSizer14->Add(transparencySlider, 1, wxALIGN_CENTER | wxALL, 5);


	transparencySizer->Add(bSizer14, 1, wxEXPAND, 5);


	controlsInnerSizer->Add(transparencySizer, 1, wxEXPAND, 5);


	controlsSizer->Add(controlsInnerSizer, 2, wxEXPAND, 5);

	wxBoxSizer* layersSizer;
	layersSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* labelSizer;
	labelSizer = new wxBoxSizer(wxHORIZONTAL);

	layersLabel = new wxStaticText(this, wxID_ANY, wxT("\nLayers"), wxPoint(-1, -1), wxSize(-1, 50), wxALIGN_CENTER_HORIZONTAL);
	layersLabel->Wrap(-1);
	layersLabel->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial")));
	layersLabel->SetForegroundColour(wxColour(255, 255, 255));
	layersLabel->SetBackgroundColour(wxColour(33, 33, 33));

	labelSizer->Add(layersLabel, 1, wxALL, 5);


	layersSizer->Add(labelSizer, 1, wxEXPAND, 5);

	layersScrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	layersScrolledWindow->SetScrollRate(5, 5);
	layersScrolledWindow->SetBackgroundColour(wxColour(125, 122, 122));

	layersSizer->Add(layersScrolledWindow, 6, wxEXPAND | wxALL, 5);


	controlsSizer->Add(layersSizer, 1, wxEXPAND, 5);


	mainSizer->Add(controlsSizer, 3, wxEXPAND, 5);


	this->SetSizer(mainSizer);
	this->Layout();

	this->Centre(wxBOTH);
}

GUI::~GUI()
{
}

void GUI::setUpMenu()
{
	wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(wxID_OPEN, "&Open\tCtrl+O");
    fileMenu->Append(wxID_SAVE, "&Save\tCtrl+S");
    fileMenu->Append(wxID_SAVEAS, "Save &As...\tCtrl+Shift+S");
    fileMenu->AppendSeparator();
    fileMenu->Append(wxID_EXIT, "E&xit\tCtrl+Q");
    

    wxMenu* editMenu = new wxMenu;
    editMenu->Append(wxID_COPY, "&Copy\tCtrl+C");
    editMenu->Append(wxID_CUT, "Cu&t\tCtrl+X");
    editMenu->Append(wxID_PASTE, "&Paste\tCtrl+V");


    wxMenu* settingsMenu = new wxMenu;
    settingsMenu->Append(wxID_EXIT);

    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(wxID_HELP, "&Help\tF1");
    helpMenu->Append(wxID_ABOUT, "&About\tF2");
    helpMenu->AppendSeparator();
    helpMenu->Append(wxID_ANY, "Go to &Docs", "Go to documentation");
    helpMenu->Append(wxID_EXIT);


    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(editMenu, "&Edit");
    menuBar->Append(settingsMenu, "&Settings");
    menuBar->Append(helpMenu, "&Help");


    SetMenuBar(menuBar);

    Bind(wxEVT_MENU, &GUI::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &GUI::OnOpen, this, wxID_OPEN);
    Bind(wxEVT_MENU, &GUI::OnSave, this, wxID_SAVE);
    Bind(wxEVT_MENU, &GUI::OnSaveAs, this, wxID_SAVEAS);
}


void GUI::OnExit(wxCommandEvent& event)
{
    Close(true);
}


void GUI::OnOpen(wxCommandEvent& event)
{
	wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("XML file (*.xml)|*.xml"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (WxOpenFileDialog.ShowModal() == wxID_OK) 
	{
		std::string file_path = WxOpenFileDialog.GetPath().ToStdString();
		std::vector<std::unique_ptr<Shape>> shapes = XMLDataLoaderAdapter::getInstance().load(file_path);
		//PolygonShape p(3, { {1,2}, {2,3}, {3, 4}});
	}
}


void GUI::OnSave(wxCommandEvent& event)
{

}


void GUI::OnSaveAs(wxCommandEvent& event)
{

}

void GUI::OnGoToDocs(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("https://docs.wxwidgets.org/");
}