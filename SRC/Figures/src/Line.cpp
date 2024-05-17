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

void Line::draw() const {
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

