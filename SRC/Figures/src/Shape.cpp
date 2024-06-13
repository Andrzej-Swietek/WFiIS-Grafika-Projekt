#include "Shape.hpp"

Shape::Shape(): stroke(1), outline("black"), fill("transparent"), rotationAngle(0), scale(100), visible(true) {}

Shape::Shape(int stroke, std::string outline, std::string fill)
: stroke(stroke), outline(outline), fill(fill), rotationAngle(0), scale(100), visible(true)
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
    Logger::getInstance()->log("setFill", fill);

}

void Shape::setScale(const int& scale) {
    this->scale = scale;
    Logger::getInstance()->log("setScale", scale);

}

ShapeType Shape::getShapeType() const {
    return shape_type;
}

void Shape::setShapeType(ShapeType shape_type) {
    this->shape_type = shape_type;
}


std::string Shape::shapeTypeToString(ShapeType shape_type) {
    switch (shape_type) {
        case ShapeType::CIRCLE:
            return "CIRCLE";
        case ShapeType::CURVE:
            return "CURVE";
        case ShapeType::LINE:
            return "LINE";
        case ShapeType::POLYGON:
            return "POLYGON";
        default:
            return "UNKNOWN";
    }
}

std::array<int,3> Shape::getRGB(const std::string& color)
{
    std::array<int, 3> rgb;
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    std::string colorCopy = color;
    int i = 0;

    while ((pos = colorCopy.find(delimiter)) != std::string::npos && i < 3) {
        token = colorCopy.substr(0, pos);
        rgb[i] = std::stoi(token);
        colorCopy.erase(0, pos + delimiter.length());
        i++;
    }
    if (i < 3) {
        rgb[i] = std::stoi(colorCopy);
    }

    return rgb;
}

void Shape::setRotationAngle(const double rotationAngle) {
    this->rotationAngle = rotationAngle;
}

double Shape::getRotationAngle() const {
    return rotationAngle;
}

int Shape::getScale() const {
    return scale;
}

void Shape::setVisible(const bool visible) {
    this->visible = visible;
}

bool Shape::getVisible() const {
    return visible;
}