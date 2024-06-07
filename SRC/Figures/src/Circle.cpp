#include "Circle.hpp"

Circle::Circle(int x, int y, int r) 
: x(x), y(y), r(r), Shape(1, "black", "transparent")
{
    this->setShapeType(ShapeType::CIRCLE);
}

Circle::Circle(int x, int y, int r, int stroke, std::string outline, std::string fill)
: x(x), y(y), r(r), Shape(stroke, outline, fill)
{
    this->setShapeType(ShapeType::CIRCLE);
}


void Circle::draw() const {
    std::cout << "Drawing a circle at (" << x << ", " << y << ") with radius " << r << std::endl;
}

 Point Circle::getCenter() const
 {
    return Point(x, y);
 }

int Circle::getX() const {
    return x;
}

int Circle::getY() const {
    return y;
}

int Circle::getR() const {
    return r;
}

void Circle::setX(int x) {
    this->x = x;
}

void Circle::setY(int y) {
    this->y = y;
}

void Circle::setR(int r) {
    this->r = r;
}