#pragma once

#include <iostream>
#include <string>
#include "Point.hpp"
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include "vecmat.h"
#include <array>
#include <sstream>
#include "Logger.hpp"


enum class ShapeType {
    CIRCLE,
    CURVE,
    LINE,
    POLYGON
};


/**
 * @class Shape
 * @brief Base class representing a shape with stroke, outline, and fill properties.
 *
 * This class defines basic properties and methods for a shape, including stroke width,
 * outline style and color, fill color, rotation angle, scale, visibility, and shape type.
 * It provides virtual methods for drawing the shape on a device context and retrieving
 * its center. Additionally, utility methods for converting shape types to strings and
 * extracting RGB values from color strings are provided.
 */
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
    virtual void draw(wxDC* dc, int canvWidth, int canvHeight) const = 0;

    /* OUTDATED and not used for now - rotation implemented directly in Shape::Draw() methods */
    /**
     * @brief Rotate the shape
     * @param rotationMatrix - rotation matrix
     * @return no return
    */
    virtual void rotate() = 0;

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


    /**
     * @brief Set the scale
     * @param scale - scale
     * @return no return
    */
    void setScale(const int& scale);


    /**
     * @brief Get the scale
     * @return scale
    */
    int getScale() const;

    /**
     * @brief Set the visible
     * @param visible - visible
     * @return no return
    */
    void setVisible(const bool visible);


    /**
     * @brief Get the visible
     * @return visible
    */
    bool getVisible() const;


    /**
     * @brief Set the RotationAngle
     * @param rotationAngle - rotation angle
     * @return no return
    */
    void setRotationAngle(const double rotationAngle);


    /**
     * @brief Get the rotation angle
     * @return rotation angle
    */
    double getRotationAngle() const;


    /**
     * @brief Get the Shape Type object
     * @return ShapeType shape type
    */
    ShapeType getShapeType() const;


    /**
     * @brief Set the Shape Type object
     * @param shape_type - shape type
     * @return no return
    */
    void setShapeType(ShapeType shape_type);


    /**
     * @brief Convert shape type to string
     * @param shape_type - shape type
     * @return std::string shape type
    */
    static std::string shapeTypeToString(ShapeType shape_type);

    /**
     * @brief get an array of RGB int values based on RGB string
     * @param color - RGB string
     * @return RGB array
    */
    static std::array<int,3> getRGB(const std::string& color);


    /**
     * @brief get a string representation of a class
     * @return string representaion of a class
    */
    virtual std::string toString() = 0;

protected:
    int stroke;
    std::string outline;
    std::string fill;
    double rotationAngle;
    int scale;

    bool visible;

    ShapeType shape_type;
};
