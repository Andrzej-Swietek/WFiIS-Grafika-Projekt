#pragma once

#include <iostream>
#include "Shape.hpp"


/**
 * @class Circle
 * @brief Class representing a circle shape derived from Shape.
 *
 * This class inherits from Shape and represents a circle defined by its center coordinates (x, y)
 * and radius (r). It provides methods to draw the circle on a device context, retrieve its center,
 * and manipulate its attributes.
 */

class Circle : public Shape {
    int x, y, r;


public:

    /// CONSTRUCTORS & DESTRUCTORS

   /**
     * @brief Construct a new Circle object
     * @x value x of a center point
     * @y value x of a center point
     * @r length of radius
     * @return no return
    */
    Circle(int x, int y, int r);


    /**
      * @brief Construct a new Circle object
      * @x value x of a center point
      * @y value x of a center point
      * @r length of radius
      * @param stroke stroke width
      * @param outline - outline style and color
      * @param fill fill color / transparent
      * @return no return
    */    
    Circle(int x, int y, int r, int stroke, std::string outline, std::string fill);


    /// OVERRIDE METHODS
   
    /**
     * @brief Draw the shape
     * @return no return
    */
    void draw(wxDC* dc, int canvWidth, int canvHeight) const override;


    /* OUTDATED and not used for now - rotation implemented directly in Shape::Draw() methods */
    /**
     * @brief Rotate the shape
     * @param rotationMatrix - rotation matrix
     * @return no return
    */
    void rotate() override;

    /// GETTERS & SETTERS
    
    /**
     * @brief Get the Center object
     * @return Point center
    */
    Point getCenter() const override;


    /**
     * @brief Get the x value of a center
     * @return int x
    */
    int getX() const;

    /**
     * @brief Get the y value of a center
     * @return int y
    */
    int getY() const;

    /**
     * @brief Get the length of radius
     * @return int r
    */
    int getR() const;


    /**
     * @brief Set the x value of a center
     * @return no return
    */
    void setX(int x);


    /**
     * @brief Set the y value of a center
     * @return no return
    */
    void setY(int y);


    /**
     * @brief Set the y value of a center
     * @return no return
    */
    void setR(int r);

    virtual std::string toString();
};
