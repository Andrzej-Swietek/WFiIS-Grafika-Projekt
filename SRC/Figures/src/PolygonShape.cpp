#include "PolygonShape.hpp"
#include "vecmat.h"


PolygonShape::PolygonShape(int n, int stroke, std::string outline, std::string fill, std::vector<Point> points)
    : n(n), points(points), Shape(stroke, outline, fill)
{
    this->setShapeType(ShapeType::POLYGON);
}


PolygonShape::PolygonShape(int n, std::vector<Point> points)
    : n(n), points(points), Shape()
{
    this->setShapeType(ShapeType::POLYGON);
}


PolygonShape::PolygonShape(std::vector<Point> points)
    : n(points.size()), points(points), Shape()
{
    this->setShapeType(ShapeType::POLYGON);
}


void PolygonShape::draw(wxDC* dc, int canvWidth, int canvHeight) const
{
    int scaler = (canvWidth < canvHeight) ? canvWidth : canvHeight;

    std::array<int, 3> rgb = Shape::getRGB(outline);

    wxColour outlineColor(rgb.at(0), rgb.at(1), rgb.at(2));
    
    int strokeWidth = stroke;

    wxPen pen(outlineColor, strokeWidth);
    dc->SetPen(pen);


    rgb = Shape::getRGB(fill);

    wxColour fillColor(rgb.at(0), rgb.at(1), rgb.at(2));
    wxBrush brush(fillColor);
    dc->SetBrush(brush);

    //
    // creating the rotation matrix
    Matrix rotM;
    rotM.data[0][0] = cos(rotationAngle);
    rotM.data[0][1] = -sin(rotationAngle);
    rotM.data[1][0] = sin(rotationAngle);
    rotM.data[1][1] = cos(rotationAngle);

    Point center = getCenter();


    double scaleFactor = static_cast<double>(scale) / 100.0;

    std::vector<wxPoint> vertices;
    for (Point pt : points)
    {
        //
        // applying the rotation matrix
        Vector a;

        a.Set(pt.x - center.x, pt.y - center.x);

        Vector a_ = rotM * a;

        pt.setX(a_.GetX() * scaleFactor + center.x);
        pt.setY(a_.GetY() * scaleFactor + center.x);

        //
        // scalling transformed point based on window size
        vertices.push_back(wxPoint(pt.getX() * scaler / 100, pt.getY() * scaler / 100));
    }

    dc->DrawPolygon(vertices.size(), vertices.data());
}

// can be refactored to something like GetRotatedVertices()
void PolygonShape::rotate()
{
    Matrix M;
    M.data[0][0] = cos(rotationAngle);
    M.data[0][1] = -sin(rotationAngle);
    M.data[1][0] = sin(rotationAngle);
    M.data[1][1] = cos(rotationAngle);

    for (int i = 0; i < points.size(); i++)
    {
        Point center = getCenter();
        Vector a;

        a.Set(points[i].x - center.x, points[i].y - center.x);

        Vector a_ = M * a;

        points[i].setX(a_.GetX() + center.x);
        points[i].setY(a_.GetY() + center.x);
    }
}



Point PolygonShape::getCenter() const {
    return Point(
        std::accumulate(points.begin(), points.end(), 0, [](int sum, Point point) { return sum + point.getX(); }) / n,
        std::accumulate(points.begin(), points.end(), 0, [](int sum, Point point) { return sum + point.getY(); }) / n
    );
}


std::vector<Point> PolygonShape::getPoints() const {
    return points;
}


void PolygonShape::setPoints(const std::vector<Point>& points) {
    this->points = points;
    this->n = points.size();
}


int PolygonShape::getN() const {
    return n;
}


void PolygonShape::setN(int n) {
    this->n = n;
}


PolygonShape& PolygonShape::operator=(const PolygonShape& other) {
    if (this != &other) {
        this->n = other.n;
        this->points = other.points;
        this->stroke = other.stroke;
        this->outline = other.outline;
        this->fill = other.fill;
    }

    return *this;
}


void PolygonShape::addPoint(const Point& point) {
    points.push_back(point);
    n++;
}


void PolygonShape::removePoint(const Point& point) {
    points.erase(std::remove(points.begin(), points.end(), point), points.end());
    n--;
}


void PolygonShape::movePoint(const Point& point, const Point& newPoint) {
    std::replace(points.begin(), points.end(), point, newPoint);
}


void PolygonShape::moveVertex(const int index, const Point& newPoint) {
    points[index] = newPoint;
}

std::string PolygonShape::toString()
{
    std::stringstream ss;
    ss << "PolygonShape: {"
        << "Vertices: " << n << ", "
        << "Stroke: " << getStroke() << ", "
        << "Outline Color: " << getOutline() << ", "
        << "Fill Color: " << getFill() << ", "
        << "Shape Type: " << (getShapeType() == ShapeType::POLYGON ? "POLYGON" : "UNKNOWN")
        << ", Points: [";

    for (size_t i = 0; i < points.size(); ++i) {
        ss << "(" << points[i].getX() << ", " << points[i].getY() << ")";
        if (i != points.size() - 1) {
            ss << ", ";
        }
    }

    ss << "]}";
    return ss.str();
}
