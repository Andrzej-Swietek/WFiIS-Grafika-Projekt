#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Curve.hpp"
#include "PolygonShape.hpp"


/**
 * @class ShapeBuilder
 * @brief Builder class for creating various types of shapes.
 *
 * This class provides a fluent interface for configuring and building different types of shapes,
 * including Circle, Curve, PolygonShape, and Line. It allows setting parameters such as stroke width,
 * outline style and color, fill color or transparency, center coordinates, radius, and points for
 * polygons and curves. Each setter method returns a reference to the builder object, enabling method
 * chaining to facilitate easy configuration. The builder methods for each shape type return the
 * corresponding fully configured shape object.
 */
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


    /**
     * @brief Get the builder instance
     * @return ShapeBuilder*
    */
    ShapeBuilder* builder() {
        return this;
    }

    /// METHODS
 
    /**
     * @brief Set the number of sides (for polygons)
     * @param n number of sides
     * @return ShapeBuilder*
    */
    ShapeBuilder* setN(int n) {
        this->n = n;
        return this;
    }


    /**
     * @brief Set the stroke width
     * @param stroke stroke width
     * @return ShapeBuilder*
    */
    ShapeBuilder* setStroke(int stroke) {
        this->stroke = stroke;
        return this;
    }


    /**
     * @brief Set the outline style and color
     * @param outline outline style and color
     * @return ShapeBuilder*
    */
    ShapeBuilder* setOutline(const std::string& outline) {
        this->outline = outline;
        return this;
    }


    /**
     * @brief Set the fill color or transparency
     * @param fill fill color / transparent
     * @return ShapeBuilder*
    */
    ShapeBuilder* setFill(const std::string& fill) {
        this->fill = fill;
        return this;
    }


    /**
     * @brief Set the points of the shape
     * @param points vector of points
     * @return ShapeBuilder*
    */
    ShapeBuilder* setPoints(const std::vector<Point>& points) {
        this->points = points;
        return this;
    }

    /**
     * @brief Set the x-coordinate of the center
     * @param x x-coordinate
     * @return ShapeBuilder*
    */
    ShapeBuilder* setX(int x) {
        this->x = x;
        return this;
    }


    /**
     * @brief Set the y-coordinate of the center
     * @param y y-coordinate
     * @return ShapeBuilder*
    */
    ShapeBuilder* setY(int y) {
        this->y = y;
        return this;
    }


    /**
     * @brief Set the radius
     * @param r radius
     * @return ShapeBuilder*
    */
    ShapeBuilder* setR(int r) {
        this->r = r;
        return this;
    }


    /**
     * @brief Build a Circle object
     * @return Circle
    */

    Circle buildCircle(){
        return Circle(x, y, r, stroke, outline, fill);
    }


    /**
     * @brief Build a Curve object
     * @return Curve
    */
    Curve buildCurve(){
        return Curve(stroke, outline, fill, points);
    }


    /**
     * @brief Build a PolygonShape object
     * @return PolygonShape
    */
    PolygonShape buildPolygonShape(){
        return PolygonShape(n, stroke, outline, fill, points);
    }


    /**
     * @brief Build a Line object
     * @return Line
    */
    Line buildLine() const {
        return Line(points[0], points[1], stroke, outline, fill);
    }



    /**
     * @brief Build a PolygonShape object (duplicate method, could be removed or renamed)
     * @return PolygonShape
    */
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