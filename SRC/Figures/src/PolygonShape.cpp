#include "PolygonShape.hpp"

PolygonShape::PolygonShape(int n, int stroke, std::string outline, std::string fill, std::vector<Point> points)
        : n(n), points(points), Shape(stroke, outline, fill)
{
    this->setShapeType(ShapeType::POLYGON);
}


PolygonShape::PolygonShape(int n, std::vector<Point> points)
    : n(n), points(points), Shape()
{
    this->setShapeType(ShapeType::POLYGON);
}


PolygonShape::PolygonShape(std::vector<Point> points)
    : n(points.size()), points(points), Shape() 
{
    this->setShapeType(ShapeType::POLYGON);
}


void PolygonShape::draw() const {}


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
