#pragma once

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>

#include "Shape.hpp"



/**
 * @class PolygonShape
 * @brief Class representing a polygon shape derived from Shape.
 *
 * This class inherits from Shape and represents a polygon defined by its number of sides,
 * stroke width, outline style and color, fill color, and a vector of points representing its vertices.
 * It provides methods to draw the polygon on a device context, rotate it, retrieve its center,
 * manipulate its vertices, and convert it to a string representation.
 */
class PolygonShape : public Shape {
    int n;

    std::vector<Point> points;

public:
    /// CONSTRUCTORS & DESTRUCTORS

    /**
     * @brief Construct a new PolygonShape object
     * @param n number of sides
     * @param stroke stroke width
     * @param outline outline style and color
     * @param fill fill color / transparent
     * @param points vector of points representing the vertices
     * @return no return
     */
    PolygonShape(int n, int stroke, std::string outline, std::string fill, std::vector<Point> points);


    /**
    * @brief Construct a new PolygonShape object
    * @param n number of points
    * @param points vector of points 
    * @return no return
    */
    PolygonShape(int n, std::vector<Point> points);


    /**
     * @brief Construct a new PolygonShape object
     * @param points vector of points   
     * @return no return
     */
    PolygonShape(std::vector<Point> points);


    /**
     * @brief Destroy the PolygonShape object
     * @return no return
    */
    ~PolygonShape() = default;

    /// VIRTUAL METHODS
    
    /**
     * @brief Draw the shape
     * @param dc device context for drawing
     * @param canvWidth width of the canvas
     * @param canvHeight height of the canvas
     * @return no return
     */
    void draw(wxDC* dc, int canvWidth, int canvHeight) const override;


    /**
     * @brief Rotate the shape
     * @return no return
    */
    void rotate() override;


    /**
     * @brief Get the center point of the polygon
     * @return Point center
     */
    Point getCenter() const override;

    /// GETTERS & SETTERS
    
    /**
     * @brief Get the points of the polygon
     * @return std::vector<Point> points
     */
    std::vector<Point> getPoints() const;


    /**
     * @brief Set the points of the polygon
     * @param points vector of points representing the vertices
     * @return no return
     */
    void setPoints(const std::vector<Point>& points);


    /**
     * @brief Get the number of sides of the polygon
     * @return int number of sides
     */
    int getN() const;


    /**
     * @brief Set the number of sides of the polygon
     * @param n number of sides
     * @return no return
     */
    void setN(int n);

    /// OPERATORS
    
    /**
     * @brief Assignment operator for PolygonShape
     * @param other another PolygonShape object
     * @return PolygonShape&
     */
    PolygonShape& operator=(const PolygonShape& other);

    /// METHODS
    
    /**
     * @brief Add a point to the polygon
     * @param point point to be added
     * @return no return
     */
    void addPoint(const Point& point);

    /**
     * @brief Remove a point from the polygon
     * @param point point to be removed
     * @return no return
     */
    void removePoint(const Point& point);


    /**
     * @brief Move a point to a new location
     * @param point current point location
     * @param newPoint new point location
     * @return no return
     */
    void movePoint(const Point& point, const Point& newPoint);


    /**
     * @brief Move a vertex to a new location
     * @param index index of the vertex to be moved
     * @param newPoint new location of the vertex
     * @return no return
     */
    void moveVertex(const int index, const Point& newPoint);


    /**
     * @brief Convert the PolygonShape to a string representation
     * @return std::string string representation of the polygon
     */
    virtual std::string toString();
};