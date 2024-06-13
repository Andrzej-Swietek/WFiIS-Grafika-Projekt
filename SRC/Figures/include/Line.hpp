#pragma once  
#include <iostream>

#include "Point.hpp"
#include "Shape.hpp"


/**
 * @class Line
 * @brief Class representing a line shape derived from Shape.
 *
 * This class inherits from Shape and represents a line defined by its starting and ending points,
 * stroke width, outline style and color, and fill color. It provides methods to draw the line on
 * a device context, rotate it, retrieve its center, manipulate its start and end points, and
 * convert it to a string representation.
 */
class Line : public Shape {
public:
    /// CONSTRUCTORS & DESTRUCTORS

    /**
     * @brief Construct a new Line object with default values
     * @return no return
    */
    Line() = default;

    /**
     * @brief Construct a new Line object by copying another Line
     * @param other Line object to copy from
     * @return no return
    */
    Line(const Line& other);

    /**
     * @brief Construct a new Line object with start and end points
     * @param start starting point of the line
     * @param end ending point of the line
     * @return no return
    */
    Line(const Point& start, const Point& end);

    /**
     * @brief Construct a new Line object with start and end points, stroke width, outline, and fill
     * @param start starting point of the line
     * @param end ending point of the line
     * @param stroke stroke width
     * @param outline outline style and color
     * @param fill fill color / transparent
     * @return no return
    */
    Line(const Point& start, const Point& end, int stroke = 1, std::string outline = "", std::string fill = "transparent");

    /**
     * @brief Destroy the Line object
     * @return no return
    */
    ~Line() = default;

    /// OPERATORS

    /**
     * @brief Assignment operator for Line
     * @param other another Line object
     * @return Line&
    */
    Line& operator=(const Line& other);

    /**
     * @brief Move assignment operator for Line
     * @param other another Line object to move from
     * @return Line&
    */
    Line& operator=(Line&& other) noexcept;

    /// VIRTUAL METHODS

    /**
     * @brief Get the center point of the line
     * @return Point center
    */
    Point getCenter() const override;

    /**
     * @brief Draw the line
     * @param dc device context for drawing
     * @param canvWidth width of the canvas
     * @param canvHeight height of the canvas
     * @return no return
    */
    void draw(wxDC* dc, int canvWidth, int canvHeight) const override;

    /**
     * @brief Rotate the line
     * @return no return
    */
    void rotate() override;

    /// GETTERS & SETTERS

    /**
     * @brief Get the start point of the line
     * @return Point start point
    */
    Point getStart() const;

    /**
     * @brief Get the end point of the line
     * @return Point end point
    */
    Point getEnd() const;

    /**
     * @brief Set the start point of the line
     * @param start start point
     * @return no return
    */
    void setStart(const Point& start);

    /**
     * @brief Set the end point of the line
     * @param end end point
     * @return no return
    */
    void setEnd(const Point& end);

    /**
     * @brief Convert the Line to a string representation
     * @return std::string string representation of the line
    */
    virtual std::string toString();

private:
    Point start;
    Point end;
};
