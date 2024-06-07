#include "Shape.hpp"

Shape::Shape(): stroke(1), outline("black"), fill("transparent"), rotationAngle(0) {}

Shape::Shape(int stroke, std::string outline, std::string fill)
: stroke(stroke), outline(outline), fill(fill), rotationAngle(0)
{}

int Shape::getStroke() const {
    return stroke;
}

std::string Shape::getOutline() const {
    return outline;
}

std::string Shape::getFill() const {
    return fill;
}

void Shape::setStroke(int stroke) {
    this->stroke = stroke;
}

void Shape::setOutline(const std::string& outline) {
    this->outline = outline;
}

void Shape::setFill(const std::string& fill) {
    this->fill = fill;
}

void Shape::setRotationAngle(const double rotationAngle) {
    this->rotationAngle = rotationAngle;
}