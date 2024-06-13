#pragma once

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#include "Shape.hpp"
#include "Point.hpp"


/**
 * @class Curve
 * @brief Class representing a curve shape derived from Shape.
 *
 * This class inherits from Shape and represents a curve defined by its stroke width,
 * outline style and color, fill color, and a vector of points that define the curve's path.
 * It provides methods to draw the curve on a device context, rotate it, retrieve its center,
 * manipulate its points, and convert it to a string representation.
 */
class Curve : public Shape {
public:
    /// CONSTRUCTORS & DESTRUCTOR
    
    /**
     * @brief Construct a new Curve object
     * @param stroke stroke width
     * @param outline outline style and color
     * @param fill fill color / transparent
     * @param points vector of points representing the curve
     * @return no return
    */
    Curve(int stroke=1, std::string outline="solid #000", std::string fill="transparent", std::vector<Point> points = {});

    /**
     * @brief Construct a new Curve object
     * @param points vector of points representing the curve
     * @return no return
    */
    Curve(std::vector<Point> points);


    /**
     * @brief Default constructor for Curve object
     * @return no return
    */
    Curve();


    /**
     * @brief Destroy the Curve object
     * @return no return
    */
    ~Curve() = default;

    /// VIRTUAL METHODS

    /**
     * @brief Draw the curve
     * @param dc device context for drawing
     * @param canvWidth width of the canvas
     * @param canvHeight height of the canvas
     * @return no return
    */
    void draw(wxDC* dc, int canvWidth, int canvHeight) const override;


    /**
     * @brief Rotate the curve
     * @return no return
    */
    void rotate() override;


    /// GETTERS & SETTERS
    
    /**
     * @brief Get the center point of the curve
     * @return Point center
    */
    Point getCenter() const override;

    /**
     * @brief Get the points of the curve
     * @return std::vector<Point> points
    */
    std::vector<Point> getPoints() const;

    /**
     * @brief Set the points of the curve
     * @param points vector of points representing the curve
     * @return no return
    */
    void setPoints(const std::vector<Point>& points);


    /**
     * @brief Get the number of points in the curve
     * @return int number of points
    */
    int getN() const;


    /**
     * @brief Set the number of points in the curve
     * @param n number of points
     * @return no return
    */
    void setN(int n);

    /// OPERATORS
   
    /**
     * @brief Assignment operator for Curve
     * @param other another Curve object
     * @return Curve&
    */
    Curve& operator=(const Curve& other);

    /// METHODS

    /**
     * @brief Add a point to the curve
     * @param point point to be added
     * @return no return
    */
    void addPoint(const Point& point);


    /**
     * @brief Remove a point from the curve
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


    //
    // ALTERNATIVE: manual Bezier curve computing algorithms
    //wxPoint CalculateBezierPoint(double t) const;
    //Point DeCasteljau(double t) const;



    virtual std::string toString();

private:
    std::vector<Point> points;
    int n;
};