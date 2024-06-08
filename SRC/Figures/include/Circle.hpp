#pragma once

#include <iostream>
#include "Shape.hpp"

class Circle : public Shape {
    int x, y, r;


public:
    Circle(int x, int y, int r);
    Circle(int x, int y, int r, int stroke, std::string outline, std::string fill);
    void draw(wxDC* dc, int canvWidth, int canvHeight) const override;
    void rotate() override;
    Point getCenter() const override;

    int getX() const;
    int getY() const;
    int getR() const;

    void setX(int x);
    void setY(int y);
    void setR(int r);

    virtual std::string toString();
};
