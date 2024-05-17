#pragma once  
#include <iostream>

#include "Point.hpp"
#include "Shape.hpp"

class Line : public Shape {    
public:
    /// CONSTRUCTORS & DESTRUCTORS

    /**
     * @brief Construct a new Line object
     * @return no return
    */
    Line() = default;

    Line(const Line&);
    
    Line(const Point& start, const Point& end);

    Line(const Point& start, const Point& end, int stroke=1, std::string outline="", std::string fill="transparent");
    
   ~Line() = default;

    /// OPERATORS
    Line& operator=(const Line& other);
    Line& operator=(Line&& other) noexcept;

    /// VIRTUAL METHODS
    Point getCenter() const override;
    void draw() const override;


    /// GETTERS & SETTERS
    Point getStart() const;
    Point getEnd() const;

    void setStart(const Point& start);
    void setEnd(const Point& end);

private:
    Point start;
    Point end;
};