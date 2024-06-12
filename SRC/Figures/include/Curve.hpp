#pragma once

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#include "Shape.hpp"
#include "Point.hpp"

class Curve : public Shape {
public:
    /// CONSTRUCTORS & DESTRUCTOR
    Curve(int stroke=1, std::string outline="solid #000", std::string fill="transparent", std::vector<Point> points = {});

    Curve(std::vector<Point> points);

    Curve();

    ~Curve() = default;

    /// VIRTUAL METHODS
    void draw(wxDC* dc, int canvWidth, int canvHeight) const override;

    void rotate() override;


    Point getCenter() const override;

    /// GETTERS & SETTERS
    std::vector<Point> getPoints() const;
    void setPoints(const std::vector<Point>& points);
    int getN() const;
    void setN(int n);

    /// OPERATORS
    Curve& operator=(const Curve& other);

    /// METHODS
    void addPoint(const Point& point);

    void removePoint(const Point& point);

    void movePoint(const Point& point, const Point& newPoint);

    void moveVertex(const int index, const Point& newPoint);


    //
    // ALTERNATIVE: manual Bezier curve computing algorithms
    //wxPoint CalculateBezierPoint(double t) const;
    //Point DeCasteljau(double t) const;
    virtual std::string toString();

private:
    std::vector<Point> points;
    int n;
};