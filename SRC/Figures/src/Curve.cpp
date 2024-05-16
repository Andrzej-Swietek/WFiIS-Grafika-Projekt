#include "Curve.hpp"

Curve::Curve(int stroke, std::string outline, std::string fill, std::vector<Point> points)
    : Shape(stroke, outline, fill), points(points) {}

Curve::Curve(std::vector<Point> points)
    : Shape(), points(points) {}

Curve::Curve()
    : Shape() {}

void Curve::draw() const {
}

Point Curve::getCenter() const {
    return std::accumulate(points.begin(), points.end(), Point(0, 0), [](Point sum, Point point) { return sum + point; }) / points.size();
}

std::vector<Point> Curve::getPoints() const {
    return points;
}

void Curve::setPoints(const std::vector<Point>& points) {
    this->points = points;
}

int Curve::getN() const {
    return n;
}

void Curve::setN(int n) {
    points.resize(n);
    this->n = n;
}

Curve& Curve::operator=(const Curve& other) {
    if (this != &other) {
        points = other.points;
    }

    return *this;
}

void Curve::addPoint(const Point& point) {
    points.push_back(point);
}

void Curve::removePoint(const Point& point) {
    points.erase(std::remove(points.begin(), points.end(), point), points.end());
}

void Curve::movePoint(const Point& point, const Point& newPoint) {
    std::replace(points.begin(), points.end(), point, newPoint);
}

void Curve::moveVertex(const int index, const Point& newPoint) {
    points[index] = newPoint;
}
