#include "PolygonShape.hpp"
#include "vecmat.h"

PolygonShape::PolygonShape(int n, int stroke, std::string outline, std::string fill, std::vector<Point> points)
    : n(n), points(points), Shape(stroke, outline, fill) {}


PolygonShape::PolygonShape(int n, std::vector<Point> points)
    : n(n), points(points), Shape() {}


PolygonShape::PolygonShape(std::vector<Point> points)
    : n(points.size()), points(points), Shape() {}


void PolygonShape::draw(wxDC* dc, int canvWidth, int canvHeight) const 
{
    int scaler = (canvWidth < canvHeight) ? canvWidth : canvHeight;

    wxColour outlineColor = *wxRED;
    wxColour fillColor = *wxGREEN;
    int strokeWidth = stroke;

    wxPen pen(outlineColor, strokeWidth);
    dc->SetPen(pen);

    wxBrush brush(fillColor);
    dc->SetBrush(brush);

    // draw rotated copy of vertices?

    std::vector<wxPoint> vertices;
    for (Point pt : points)
    {
        vertices.push_back(wxPoint(pt.getX() * scaler / 100, pt.getY() * scaler / 100));
    }

    dc->DrawPolygon(vertices.size(), vertices.data());
}

void PolygonShape::rotate()
{
    Matrix M;
    M.data[0][0] = cos(rotationAngle);
    M.data[0][1] = -sin(rotationAngle);
    M.data[1][0] = sin(rotationAngle);
    M.data[1][1] = cos(rotationAngle);

    for (int i = 0; i < points.size(); i++)
    {
        Point center = getCenter();
        Vector a;

        a.Set(points[i].x - center.x, points[i].y - center.x);

        Vector a_ = M * a;

        points[i].setX(a_.GetX() + center.x);
        points[i].setY(a_.GetY() + center.x);
    }
}


Point PolygonShape::getCenter() const {
    return Point(
        std::accumulate(points.begin(), points.end(), 0, [](int sum, Point point) { return sum + point.getX(); }) / n,
        std::accumulate(points.begin(), points.end(), 0, [](int sum, Point point) { return sum + point.getY(); }) / n
    );
}


std::vector<Point> PolygonShape::getPoints() const {
    return points;
}


void PolygonShape::setPoints(const std::vector<Point>& points) {
    this->points = points;
    this->n = points.size();
}


int PolygonShape::getN() const {
    return n;
}


void PolygonShape::setN(int n) {
    this->n = n;
}


PolygonShape& PolygonShape::operator=(const PolygonShape& other) {
    if (this != &other) {
        this->n = other.n;
        this->points = other.points;
        this->stroke = other.stroke;
        this->outline = other.outline;
        this->fill = other.fill;
    }

    return *this;
}


void PolygonShape::addPoint(const Point& point) {
    points.push_back(point);
    n++;
}


void PolygonShape::removePoint(const Point& point) {
    points.erase(std::remove(points.begin(), points.end(), point), points.end());
    n--;
}


void PolygonShape::movePoint(const Point& point, const Point& newPoint) {
    std::replace(points.begin(), points.end(), point, newPoint);
}


void PolygonShape::moveVertex(const int index, const Point& newPoint) {
    points[index] = newPoint;
}