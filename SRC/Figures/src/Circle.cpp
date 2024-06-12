#include "Circle.hpp"

Circle::Circle(int x, int y, int r) 
: x(x), y(y), r(r), Shape(1, "black", "transparent")
{
    this->setShapeType(ShapeType::CIRCLE);
}

Circle::Circle(int x, int y, int r, int stroke, std::string outline, std::string fill)
: x(x), y(y), r(r), Shape(stroke, outline, fill)
{
    this->setShapeType(ShapeType::CIRCLE);
}


void Circle::draw(wxDC* dc, int canvWidth, int canvHeight) const {
    std::cout << "Drawing a circle at (" << x << ", " << y << ") with radius " << r << std::endl;


    //dc->SetPen(*wxBLACK);  // outline
    //dc->SetBrush(wxBrush(*wxBLUE_BRUSH));  // fill

    int scaler = (canvWidth < canvHeight) ? canvWidth : canvHeight;

    double scaleFactor = static_cast<double>(scale) / 100.0;


    int centerX = x * scaler / 100;
    int centerY = y * scaler / 100;
    int radius = r * scaleFactor * scaler / 100;

    int strokeWidth = stroke * scaleFactor /** canvWidth / 100*/;

    //Logger::getInstance()->log("Info line", outline);

    std::array<int, 3> rgb = Shape::getRGB(outline);

    wxColour lineColor(rgb.at(0), rgb.at(1), rgb.at(2));

    wxPen pen(lineColor, strokeWidth);
    dc->SetPen(pen);

    Logger::getInstance()->log("Info line Circle", fill);

    rgb = Shape::getRGB(fill);

    wxColour fillColor(rgb.at(0), rgb.at(1), rgb.at(2));
    wxBrush brush(fillColor);
    dc->SetBrush(brush);

    dc->DrawCircle(centerX, centerY, radius);
}

//
// does rotating a circle make sense??
void Circle::rotate()
{
    /*Vector a;

    a.Set(pt.x, pt.y);

    Vector a_ = rotationMatrix * a;

    pt.x = a_.GetX();
    pt.y = a_.GetY();*/
}

 Point Circle::getCenter() const
 {
    return Point(x, y);
 }

int Circle::getX() const {
    return x;
}

int Circle::getY() const {
    return y;
}

int Circle::getR() const {
    return r;
}

void Circle::setX(int x) {
    this->x = x;
}

void Circle::setY(int y) {
    this->y = y;
}

void Circle::setR(int r) {
    this->r = r;
}

std::string Circle::toString()
{
    std::stringstream ss;
    ss << "Circle: {"
        << "Center: (" << x << ", " << y << "), "
        << "Radius: " << r << ", "
        << "Stroke: " << getStroke() << ", "
        << "Outline Color: " << getOutline() << ", "
        << "Fill Color: " << getFill() << ", "
        << "Shape Type: " << (getShapeType() == ShapeType::CIRCLE ? "CIRCLE" : "UNKNOWN")
        << "}";
    return ss.str();
}
