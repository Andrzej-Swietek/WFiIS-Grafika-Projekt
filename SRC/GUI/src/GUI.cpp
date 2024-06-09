#include "GUI.h"
#include <Circle.hpp>
#include <Line.hpp>
#include <Curve.hpp>
#include <PolygonShape.hpp>


//enum {
//	ID_UP_LAYER_BUTTON = wxID_HIGHEST + 1,
//	ID_DOWN_LAYER_BUTTON = wxID_HIGHEST + 2
//};

const int ID_UP_LAYER_BUTTON = 6500;
const int ID_DOWN_LAYER_BUTTON = 6501;
const int ID_LIST_SHAPES_BUTTON = 6502;



GUI::GUI(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
	: wxFrame(parent, id, title, pos, size, style)
{
	menu = new Menu(this);
	menu->SetOnExitHandler([this](wxCommandEvent& event) { OnExit(event); });
	menu->SetOnOpenHandler([this](wxCommandEvent& event) { OnOpen(event); });
	menu->SetOnSaveHandler([this](wxCommandEvent& event) { OnSave(event); });
	menu->SetOnSaveAsHandler([this](wxCommandEvent& event) { OnSaveAs(event); });
	menu->SetOnUpLayerHandler([this](wxCommandEvent& event) { OnUpLayerButtonClick(event); });
	menu->SetOnDownLayerHandler([this](wxCommandEvent& event) { OnDownLayerButtonClick(event); });

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* canvasesSizer;
	canvasesSizer = new wxBoxSizer(wxVERTICAL);

	m_canvas_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_canvas_panel->SetBackgroundColour(wxColour(255, 255, 255));

	canvasesSizer->Add(m_canvas_panel, 4, wxEXPAND | wxALL, 5);

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


	// Layer UP / Down

	wxBoxSizer* layerUpDownSizer;
	layerUpDownSizer = new wxBoxSizer(wxHORIZONTAL);

	orderLayersLabel = new wxStaticText(this, wxID_ANY, wxT("Move Layer"), wxDefaultPosition, wxDefaultSize, 0);
	orderLayersLabel->Wrap(-1);
	layerUpDownSizer->Add(orderLayersLabel, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	upLayerBtn = new wxButton(this, ID_UP_LAYER_BUTTON, wxT("Up"), wxDefaultPosition, wxDefaultSize, 0);
	layerUpDownSizer->Add(upLayerBtn, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	downLayerBtn = new wxButton(this, ID_DOWN_LAYER_BUTTON, wxT("Down"), wxDefaultPosition, wxDefaultSize, 0);
	layerUpDownSizer->Add(downLayerBtn, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	listShapesBtn = new  wxButton(this, ID_LIST_SHAPES_BUTTON, wxT("List Shapes"), wxDefaultPosition, wxDefaultSize, 0);
	layerUpDownSizer->Add(listShapesBtn, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	layersSizer->Add(layerUpDownSizer, 1, wxEXPAND, 5);

	// SELECTION STATUS

	wxBoxSizer* selectedSizer;
	selectedSizer = new wxBoxSizer(wxHORIZONTAL);

	selectedLabelText = new wxStaticText(this, wxID_ANY, wxT("Selected Shape:"), wxDefaultPosition, wxDefaultSize, 0);
	selectedLabelText->Wrap(-1);
	selectedLabelText->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString));

	selectedSizer->Add(selectedLabelText, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	selectedShapeStatus = new wxStaticText(this, wxID_ANY, wxT("No Selection"), wxDefaultPosition, wxDefaultSize, 0);
	selectedShapeStatus->Wrap(-1);
	selectedSizer->Add(selectedShapeStatus, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);


	layersSizer->Add(selectedSizer, 1, wxEXPAND, 5);

	//

	layersScrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	layersScrolledWindow->SetScrollRate(5, 5);
	layersScrolledWindow->SetBackgroundColour(wxColour(125, 122, 122));

	layersSizer->Add(layersScrolledWindow, 6, wxEXPAND | wxALL, 5);


	controlsSizer->Add(layersSizer, 1, wxEXPAND, 5);


	mainSizer->Add(controlsSizer, 3, wxEXPAND, 5);


	this->SetSizer(mainSizer);
	this->Layout();

	this->Centre(wxBOTH);

	//
	// bind the paint event - also refreshes on resize??
	//
	m_canvas_panel->Bind(wxEVT_PAINT, &GUI::OnPaint, this);
	// rotationSlider->Bind(wxEVT_SCROLL_THUMBTRACK, &GUI::RotationSliderUpdate, this);

	rotationSlider->Bind(wxEVT_SCROLL_THUMBTRACK, &GUI::RotationSliderUpdate, this);

	/*std::shared_ptr<Circle> c = std::make_shared<Circle>(new Circle(2,2,1));
	shapes.push_back(c.get());*/

	// Bind events to buttons
	//Bind(wxEVT_BUTTON, &GUI::OnUpLayerButtonClick, this, ID_UP_LAYER_BUTTON);
	//Bind(wxEVT_BUTTON, &GUI::OnDownLayerButtonClick, this, ID_DOWN_LAYER_BUTTON);

	Bind(wxEVT_BUTTON, &GUI::OnUpLayerButtonClick, this, ID_UP_LAYER_BUTTON);
	Bind(wxEVT_BUTTON, &GUI::OnDownLayerButtonClick, this, ID_DOWN_LAYER_BUTTON);
	Bind(wxEVT_BUTTON, &GUI::OnListShapesButtonClick, this, ID_LIST_SHAPES_BUTTON);
}

GUI::~GUI()
{
}


void GUI::Repaint() const
{
	wxClientDC dc1(m_canvas_panel);
	wxBufferedDC dc(&dc1);
	dc.SetBackground(wxBrush(wxColour(255, 255, 255)));
	dc.Clear();
	int w, h;
	m_canvas_panel->GetSize(&w, &h);

	DrawShapes(dc, w, h);
}

void GUI::RefreshLayersDisplay() const
{

	// Clear old components
	wxWindowList& children = layersScrolledWindow->GetChildren();
	Logger::getInstance()->log("Children", children.size()); int i = 0;

	while (!children.empty()) {
		wxWindow* child = children.front();
		children.erase(children.begin()); // Remove child from list
		child->Destroy(); // Destroy the child window
	}


	// Create ShapePanel instances for each shape and add them to layersScrolledWindow
	wxBoxSizer* layersSizer = new wxBoxSizer(wxVERTICAL);
	int id = 0;
	for (const auto& shape : shapes) {
		wxString shapeName = Shape::shapeTypeToString(shape->getShapeType());
		int shapeId = id++;														 /* TODO: Get the shape ID */
		ShapesPanel* shapePanel = new ShapesPanel(
			layersScrolledWindow,
			shapeName.append(": ").append(std::to_string(shapeId)),
			shapeId
		);
		layersSizer->Add(shapePanel, 0, wxEXPAND | wxALL, 5);
	}

	layersScrolledWindow->SetSizer(layersSizer);
	layersScrolledWindow->Layout();
	layersScrolledWindow->Refresh();
}

void GUI::OnPaint(wxPaintEvent& event)
{
	Repaint();
}

//
// TODO: necessary? For now resizing is handled in the respective Shape::draw() implementations
// UI seems to not update sometimes (like clicking on the slider instead of dragging the thumbnail or when resizing/minimizing/maximizing the window)
//
void GUI::UpdateShapesOnResize()
{
	for (const auto& shape : shapes)
	{
		
	}
}

void GUI::DrawShapes(wxDC& dc, int canvWidth, int canvHeight) const
{
	if (shapes.size() == 0) return;
	for (const auto& shape : shapes)
	{
		/*Logger::getInstance()->log("Info", Shape::shapeTypeToString(shape->getShapeType()));*/
		shape->draw(&dc, canvWidth, canvHeight);	
	}
}

/*
	rotation angle stored in the Shape object and used when drawing - no alternation of vertices
	the same can be done with other transformations
*/

void GUI::RotationSliderUpdate(wxScrollEvent& event)
{
	//WxStaticText_alpha->SetLabel(wxString::Format(wxT("%d"), WxScrollBar_alpha->GetThumbPosition()));
	double alpha = rotationSlider->GetValue();

	// rotation angle in radians
	double angle = alpha * M_PI / 180.0;

	//
	// for now rotating all the shapes - it should rotate only selected shapes in the future
	// rotation is implemented directly in the Shape::Draw() methods - perhaps it can be done better (split transformations into methods/functions?)
	for (const auto& shape : shapes)
	{
		shape->setRotationAngle(angle);
	}
	Repaint();
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
		this->shapes = XMLDataLoaderAdapter::getInstance().load(file_path);
	
		// Clear old components
		wxWindowList& children = layersScrolledWindow->GetChildren();

		while (!children.empty()) {
			wxWindow* child = children.front();
			children.erase(children.begin()); // Remove child from list
			child->Destroy(); // Destroy the child window
		}

		// Create ShapePanel instances for each shape and add them to layersScrolledWindow
		wxBoxSizer* layersSizer = new wxBoxSizer(wxVERTICAL);
		int id = 0;
		for (const auto& shape : shapes) {
			wxString shapeName = Shape::shapeTypeToString(shape->getShapeType());	/* TODO: Get the shape name */
			int shapeId = id++;				/* TODO: Get the shape ID */
			ShapesPanel* shapePanel = new ShapesPanel(
				layersScrolledWindow,
				shapeName.append(": ").append(std::to_string(shapeId)),
				shapeId
			);
			shapePanel->SetSelectionCallback([this] { updateSelectionStatusDisplay(); });
			layersSizer->Add(shapePanel, 0, wxEXPAND | wxALL, 5);
		}

		layersScrolledWindow->SetSizer(layersSizer);
		layersScrolledWindow->Layout();
	}
	try
	{
		Repaint();
	}
	catch (const std::exception& e)
	{
		Logger::getInstance()->log("Error", e.what());
	}
	
}


void GUI::OnSave(wxCommandEvent& event)
{
	ImageSaver::getInstance(m_canvas_panel)->SaveImage(this);
	//m_imageSaver->SaveImage(this);
}


void GUI::OnSaveAs(wxCommandEvent& event)
{
	ImageSaver::getInstance(m_canvas_panel)->SaveImage(this);
}

void GUI::OnGoToDocs(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("https://docs.wxwidgets.org/");
}

void GUI::OnUpLayerButtonClick(wxCommandEvent& event) {
	if (!SelectionManager::getInstance()->isShapeSelected()) return;
	const int selected_index = SelectionManager::getInstance()
													->getSelectedShapeIndex();
	if (selected_index == 0) {
		wxLogMessage("This action is not permitted");
		return;
	}

	std::swap(shapes[selected_index], shapes[selected_index - 1]);
	// wxLogMessage("Up button clicked");

	SelectionManager::getInstance()
		->selectShape(selected_index - 1);

	Repaint();
	RefreshLayersDisplay();
	this->updateSelectionStatusDisplay();
}

void GUI::OnDownLayerButtonClick(wxCommandEvent& event) {
	if (!SelectionManager::getInstance()->isShapeSelected()) return;
	const int selected_index = SelectionManager::getInstance()
												->getSelectedShapeIndex();

	if (selected_index == shapes.size()-1 ) {
		wxLogMessage("This action is not permitted");
		return;
	}

	std::swap(shapes[selected_index], shapes[selected_index + 1]);
	//wxLogMessage("Down button clicked");

	SelectionManager::getInstance()
		->selectShape(selected_index + 1);

	Repaint();
	RefreshLayersDisplay();
	this->updateSelectionStatusDisplay();
}

void GUI::OnListShapesButtonClick(wxCommandEvent& event)
{
	ShapeDialog dialog(this, shapes);
	dialog.ShowModal();
}

void GUI::updateSelectionStatusDisplay() {
	const int selected_index = SelectionManager::getInstance()
											->getSelectedShapeIndex();

	this->selectedShapeStatus->SetLabel(
		selected_index == -1 ?
			"No Selection" : Shape::shapeTypeToString( shapes[selected_index]->getShapeType() )
	);
}