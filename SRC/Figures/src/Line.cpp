#include "Line.hpp"

Line::Line(const Point& start, const Point& end)
 : start(start), end(end), Shape() 
 {}

Line::Line(const Point& start, const Point& end, int stroke, std::string outline, std::string fill)
 : start(start), end(end), Shape(stroke, outline, fill) 
 {}

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

