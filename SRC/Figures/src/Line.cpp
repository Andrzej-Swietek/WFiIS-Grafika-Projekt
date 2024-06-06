#include "Line.hpp"

Line::Line(const Line& other)
    : start(other.start), end(other.end),Shape(other.stroke, other.outline, other.fill)
{
}

Line::Line(const Point& start, const Point& end)
 : start(start), end(end), Shape() 
 {}

Line::Line(const Point& start, const Point& end, int stroke, std::string outline, std::string fill)
 : start(start), end(end), Shape(stroke, outline, fill) 
 {}

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

    wxColour lineColor = *wxBLUE;
    int strokeWidth = stroke;

    wxPen pen(lineColor, strokeWidth);
    dc->SetPen(pen);

    wxPoint startPoint(start.getX() * scaler / 100, start.getY() * scaler /100);
    wxPoint endPoint(end.getX() * scaler / 100, end.getY() * scaler / 100);

    dc->DrawLine(startPoint, endPoint);
}

void Line::rotate(Matrix rotationMatrix)
{
    Vector a, b;

    a.Set(start.x, start.y);
    b.Set(end.x, end.y);

    Vector a_ = rotationMatrix * a;
    Vector b_ = rotationMatrix * b;

    start.setX(a_.GetX()); start.setY(a_.GetY());
    end.setX(b_.GetX()); end.setY(b_.GetY());
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

