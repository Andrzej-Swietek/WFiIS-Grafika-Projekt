#include "Polygon.hpp"

 Polygon::Polygon(int n, int stroke, std::string outline, std::string fill, std::vector<Point> points)
        : n(n), points(points), Shape(stroke, outline, fill) {}


Polygon::Polygon(int n, std::vector<Point> points)
    : n(n), points(points), Shape() {}


Polygon::Polygon(std::vector<Point> points)
    : n(points.size()), points(points), Shape() {}


void Polygon::draw() const {}


Point Polygon::getCenter() const {
    return Point(
        std::accumulate(points.begin(), points.end(), 0, [](int sum, Point point) { return sum + point.getX(); }) / n,
        std::accumulate(points.begin(), points.end(), 0, [](int sum, Point point) { return sum + point.getY(); }) / n
    );
}


std::vector<Point> Polygon::getPoints() const {
    return points;
}


void Polygon::setPoints(const std::vector<Point>& points) {
    this->points = points;
    this->n = points.size();
}


int Polygon::getN() const {
    return n;
}


void Polygon::setN(int n) {
    this->n = n;
}


Polygon& Polygon::operator=(const Polygon& other) {
    if (this != &other) {
        this->n = other.n;
        this->points = other.points;
        this->stroke = other.stroke;
        this->outline = other.outline;
        this->fill = other.fill;
    }

    return *this;
}


void Polygon::addPoint(const Point& point) {
    points.push_back(point);
    n++;
}


void Polygon::removePoint(const Point& point) {
    points.erase(std::remove(points.begin(), points.end(), point), points.end());
    n--;
}


void Polygon::movePoint(const Point& point, const Point& newPoint) {
    std::replace(points.begin(), points.end(), point, newPoint);
}


void Polygon::moveVertex(const int index, const Point& newPoint) {
    points[index] = newPoint;
}
