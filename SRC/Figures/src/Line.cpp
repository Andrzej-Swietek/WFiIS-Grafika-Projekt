#include "Line.hpp"
#include <Logger.hpp>

Line::Line(const Line& other)
    : start(other.start), end(other.end),Shape(other.stroke, other.outline, other.fill)
{
    this->setShapeType(ShapeType::LINE);
}

Line::Line(const Point& start, const Point& end)
 : start(start), end(end), Shape() 
 {
    this->setShapeType(ShapeType::LINE);
 }

Line::Line(const Point& start, const Point& end, int stroke, std::string outline, std::string fill)
 : start(start), end(end), Shape(stroke, outline, fill) 
 {
    this->setShapeType(ShapeType::LINE);
 }

Line& Line::operator=(const Line& other)
{
    if (this != &other) {
        start = other.start;
        end = other.end;
        stroke = other.stroke;
        outline = other.outline;
        fill = other.fill;
    }
    return *this;
}

Line& Line::operator=(Line&& other) noexcept
{
    if (this != &other) {
        start = std::move(other.start);
        end = std::move(other.end);
        stroke = other.stroke;
        outline = std::move(other.outline);
        fill = std::move(other.fill);
        other.stroke = 1;
        other.outline = "";
        other.fill = "transparent";
    }
    return *this;
}

Point Line::getCenter() const {
    return Point((start.getX() + end.getX()) / 2, (start.getY() + end.getY()) / 2);
}

void Line::draw(wxDC* dc, int canvWidth, int canvHeight) const
{
    int scaler = (canvWidth < canvHeight) ? canvWidth : canvHeight;

    //wxColour lineColor = *wxBLUE;

    std::array<int, 3> rgb = Shape::getRGB(outline);

    wxColour lineColor(rgb.at(0), rgb.at(1), rgb.at(2));
    
    int strokeWidth = stroke;

    wxPen pen(lineColor, strokeWidth);
    dc->SetPen(pen);

    //
    // creating and applying the rotation matrix
    Matrix rotM;
    rotM.data[0][0] = cos(rotationAngle);
    rotM.data[0][1] = -sin(rotationAngle);
    rotM.data[1][0] = sin(rotationAngle);
    rotM.data[1][1] = cos(rotationAngle);

   
    Point center = getCenter();

    //
    // applying the rotation matrix
    Vector a, b;
    a.Set(start.x - center.x, start.y - center.y);
    b.Set(end.x - center.x, end.y - center.y);

    Vector a_ = rotM * a;
    Vector b_ = rotM * b;
    
    double scaleFactor = static_cast<double>(scale) / 100.0;
    
    Point tStart, tEnd;
    tStart.setX((a_.GetX() + center.x)); tStart.setY((a_.GetY() + center.y));
    tEnd.setX((b_.GetX() + center.x)); tEnd.setY((b_.GetY() + center.y));
    Logger::getInstance()->log("scaleFactor", scale); 

    //
    // scalling transformed points based on window size
    wxPoint startPoint((a_.GetX() * scaleFactor + center.getX()) * scaler / 100, (a_.GetY() * scaleFactor + center.getY()) * scaler / 100);
    wxPoint endPoint((b_.GetX() * scaleFactor + center.getX()) * scaler / 100, (b_.GetY() * scaleFactor + center.getY()) * scaler / 100);

    dc->DrawLine(startPoint, endPoint);
}

void Line::rotate()
{
    Matrix M;
    M.data[0][0] = cos(rotationAngle);
    M.data[0][1] = -sin(rotationAngle);
    M.data[1][0] = sin(rotationAngle);
    M.data[1][1] = cos(rotationAngle);

    Vector a, b;
    Point center = getCenter();
    a.Set(start.x-center.x, start.y-center.y);
    b.Set(end.x-center.x, end.y-center.y);

    Vector a_ = M * a;
    Vector b_ = M * b;

    start.setX(a_.GetX()+center.x); start.setY(a_.GetY()+center.y);
    end.setX(b_.GetX()+center.x); end.setY(b_.GetY()+center.y);
}


Point Line::getStart() const {
    return start;
}

Point Line::getEnd() const {
    return end;
}

void Line::setStart(const Point& start) {
    this->start = start;
}

void Line::setEnd(const Point& end) {
    this->end = end;
}

std::string Line::toString()
{
    std::stringstream ss;
    ss << "Line: {"
        << "Start: (" << start.getX() << ", " << start.getY() << "), "
        << "End: (" << end.getX() << ", " << end.getY() << "), "
        << "Stroke: " << getStroke() << ", "
        << "Outline Color: " << getOutline() << ", "
        << "Fill Color: " << getFill() << ", "
        << "Shape Type: " << (getShapeType() == ShapeType::LINE ? "LINE" : "UNKNOWN")
        << "}";
    return ss.str();
}
