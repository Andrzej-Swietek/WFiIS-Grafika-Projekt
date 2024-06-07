#pragma once

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#include "Shape.hpp"

class PolygonShape : public Shape {
    int n;

    std::vector<Point> points;

public:
    PolygonShape(int n, int stroke, std::string outline, std::string fill, std::vector<Point> points);

    PolygonShape(int n, std::vector<Point> points);

    PolygonShape(std::vector<Point> points);

    ~PolygonShape() = default;

    /// VIRTUAL METHODS
    void draw() const override;

    Point getCenter() const override;

    /// GETTERS & SETTERS
    std::vector<Point> getPoints() const;

    void setPoints(const std::vector<Point>& points);

    int getN() const;

    void setN(int n);

    /// OPERATORS
    PolygonShape& operator=(const PolygonShape& other);

    /// METHODS
    void addPoint(const Point& point);

    void removePoint(const Point& point);

    void movePoint(const Point& point, const Point& newPoint);

    void moveVertex(const int index, const Point& newPoint);
};