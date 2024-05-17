#include "ShapeBuilder.hpp"

ShapeBuilder::ShapeBuilder(){};

ShapeBuilder* ShapeBuilder::setN(int n) {
    this->n = n;
    return this;
}

ShapeBuilder* ShapeBuilder::setStroke(int stroke) {
    this->stroke = stroke;
    return this;
}

ShapeBuilder* ShapeBuilder::setOutline(const std::string& outline) {
    this->outline = outline;
    return this;
}

ShapeBuilder* ShapeBuilder::setFill(const std::string& fill) {
    this->fill = fill;
    return this;
}

ShapeBuilder* ShapeBuilder::setPoints(const std::vector<Point>& points) {
    this->points = points;
    return this;
}

ShapeBuilder* ShapeBuilder::setX(int x) {
    this->x = x;
    return this;
}

ShapeBuilder* ShapeBuilder::setY(int y) {
    this->y = y;
    return this;
}

ShapeBuilder* ShapeBuilder::setR(int r) {
    this->r = r;
    return this;
}