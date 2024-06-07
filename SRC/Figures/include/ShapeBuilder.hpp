#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Curve.hpp"
#include "PolygonShape.hpp"

class ShapeBuilder {
public:
    /// CONSTRUCTORS & DESTRUCTORS

    /**
     * @brief Construct a new Shape Builder object
     * @return no return
    */
    ShapeBuilder()= default;

    
    /**
     * @brief Destroy the Shape Builder object
     * @return no return
    */
    ~ShapeBuilder() = default;

    ShapeBuilder* builder() {
        return this;
    }

    /// METHODS
    ShapeBuilder* setN(int n) {
        this->n = n;
        return this;
    }

    ShapeBuilder* setStroke(int stroke) {
        this->stroke = stroke;
        return this;
    }

    ShapeBuilder* setOutline(const std::string& outline) {
        this->outline = outline;
        return this;
    }

    ShapeBuilder* setFill(const std::string& fill) {
        this->fill = fill;
        return this;
    }

    ShapeBuilder* setPoints(const std::vector<Point>& points) {
        this->points = points;
        return this;
    }

    ShapeBuilder* setX(int x) {
        this->x = x;
        return this;
    }

    ShapeBuilder* setY(int y) {
        this->y = y;
        return this;
    }

    ShapeBuilder* setR(int r) {
        this->r = r;
        return this;
    }

    Circle buildCircle(){
        return Circle(x, y, r, stroke, outline, fill);
    }

    Curve buildCurve(){
        return Curve(stroke, outline, fill, points);
    }

    Line buildLine() const {
        return Line(points[0], points[1], stroke, outline, fill);
    }

    PolygonShape buildPolygon() const {
        return PolygonShape(n, stroke, outline, fill, points);
    }

    


private:
    int n = 0;
    int stroke = 1;

    std::string outline = "";
    std::string fill = "transparent";
    std::vector<Point> points;

    int x = 0;
    int y = 0;
    int r = 0;
};