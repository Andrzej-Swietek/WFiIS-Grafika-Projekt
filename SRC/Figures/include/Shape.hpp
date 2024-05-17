#pragma once

#include <iostream>
#include <string>
#include "Point.hpp"

class Shape {
public:
    /// CONSTRUCTORS & DESTRUCTORS

    /**
     * @brief Default Constructor Construct a new Shape object
     * @return no return
    */
    Shape();


    /**
     * @brief Construct a new Shape object
     * @param stroke stroke width
     * @param outline - outline style and color
     * @param fill fill color / transparent
     * @return no return
    */
    Shape(int stroke, std::string outline, std::string fill);


    /**
     * @brief Destroy the Shape object
     * @return no return
    */
    virtual ~Shape() = default;

    /// VIRTUAL METHODS


    /**
     * @brief Draw the shape
     * @return no return
    */
    virtual void draw() const = 0;


    /// GETTERS & SETTERS

    /**
     * @brief Get the Center object
     * @return Point center
    */
    virtual Point getCenter() const = 0;


    /**
     * @brief Get the Stroke object
     * @return int stroke
    */
    int getStroke() const;


    /**
     * @brief Get the Outline object
     * @return std::string outline
    */
    std::string getOutline() const;


    /**
     * @brief Get the Fill object
     * @return std::string fill color 
    */
    std::string getFill() const;


    /**
     * @brief Set the Stroke object
     * @param stroke - stroke width
     * @return no return
    */
    void setStroke(int stroke);


    /**
     * @brief Set the Outline object
     * @param outline - outline style and color
     * @return no return
    */
    void setOutline(const std::string& outline);


    /**
     * @brief Set the Fill object
     * @param fill - fill color
     * @return no return
    */
    void setFill(const std::string& fill);

protected:
    int stroke;
    std::string outline;
    std::string fill;
};

