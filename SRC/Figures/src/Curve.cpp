#include "Curve.hpp"
#include <Logger.hpp>

Curve::Curve(int stroke, std::string outline, std::string fill, std::vector<Point> points)
    : Shape(stroke, outline, fill), points(points) 
{
    this->setShapeType(ShapeType::CURVE);
}

Curve::Curve(std::vector<Point> points)
    : Shape(), points(points) 
{
    this->setShapeType(ShapeType::CURVE);
}

Curve::Curve()
    : Shape() 
{
    this->setShapeType(ShapeType::CURVE);
}

void Curve::draw(wxDC* dc, int canvWidth, int canvHeight) const
{
    int scaler = (canvWidth < canvHeight) ? canvWidth : canvHeight;


    //wxColour lineColor = *wxGREEN;
    std::array<int, 3> rgb = Shape::getRGB(outline);

    wxColour lineColor(rgb.at(0), rgb.at(1), rgb.at(2));

    int strokeWidth = stroke;

    wxPen pen(lineColor, strokeWidth);
    dc->SetPen(pen);

    //
    // creating the rotation matrix
    Matrix rotM;
    rotM.data[0][0] = cos(rotationAngle);
    rotM.data[0][1] = -sin(rotationAngle);
    rotM.data[1][0] = sin(rotationAngle);
    rotM.data[1][1] = cos(rotationAngle);

    Point center = getCenter();


    std::vector<wxPoint> controlPoints;
    for (Point pt : points)
    {
        //
        // applying the rotation matrix
        Vector a;

        a.Set(pt.x - center.x, pt.y - center.x);

        Vector a_ = rotM * a;

        pt.setX(a_.GetX() + center.x);
        pt.setY(a_.GetY() + center.x);

        //
        // scalling transformed point based on window size
        controlPoints.push_back(wxPoint(pt.getX() * scaler / 100, pt.getY() * scaler / 100));
    }

    dc->DrawSpline(controlPoints.size(), controlPoints.data());


    //
    // ALTERNATIVE: manual Bezier curve computing algorithm no 1
    /*const int segments = 100;
    for (int i = 0; i < segments; i++)
    {
        double t1 = static_cast<double>(i) / segments;
        double t2 = static_cast<double>(i + 1) / segments;

        wxPoint p1 = CalculateBezierPoint(t1);
        wxPoint p2 = CalculateBezierPoint(t2);

        p1.x = p1.x * scaler / 100;  p1.y = p1.y * scaler / 100;
        p2.x = p2.x * scaler / 100;  p2.y = p2.y * scaler / 100;

        dc->DrawLine(p1, p2);
    }*/

    //
    // ALTERNATIVE: manual Bezier curve computing algorithm no 2
    //const int segments = 10000;
    //for (int i = 0; i < segments; i++)
    //{
    //    double t1 = static_cast<double>(i) / segments;
    //    double t2 = static_cast<double>(i + 1) / segments;

    //    Point p1 = DeCasteljau(t1);
    //    Point p2 = DeCasteljau(t2);

    //    //dc->DrawLine(wxPoint(p1.x * scaler / 100, p1.y * scaler / 100), wxPoint(p2.x*scaler / 100, p2.y * scaler /100));
    //    dc->DrawLine(wxPoint(p1.x, p1.y), wxPoint(p2.x, p2.y));

    //}
}

//
// ALTERNATIVE: manual Bezier curve computing algorithm no 1
//wxPoint Curve::CalculateBezierPoint(double t) const
//{
//    std::vector<Point> myPoints = points;
//    size_t n = myPoints.size() - 1;
//    wxPoint point(0, 0);
//
//    for (size_t i = 0; i <= n; ++i)
//    {
//        double binomialCoeff = tgamma(n + 1) / (tgamma(i + 1) * tgamma(n - i + 1));
//        double term = binomialCoeff * pow(t, i) * pow(1 - t, n - i);
//        point.x += static_cast<int>(term * myPoints[i].x);
//        point.y += static_cast<int>(term * myPoints[i].y);
//    }
//
//    return point;
//}

//
// ALTERNATIVE: manual Bezier curve computing algorithm no 2
//Point Curve::DeCasteljau(double t) const
//{
//    std::vector<Point> myPoints = points;
//    size_t n = myPoints.size();
// 
//
//    for (size_t k = 1; k < n; ++k)
//    {
//        for (size_t i = 0; i < n - k; ++i)
//        {
//            myPoints[i].x = static_cast<int>((1 - t) * myPoints[i].x + t * myPoints[i + 1].x);
//            myPoints[i].y = static_cast<int>((1 - t) * myPoints[i].y + t * myPoints[i + 1].y);
//        }
//    }
//    return myPoints[0];
//}

void Curve::rotate()
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

        a.Set(points[i].x-center.x, points[i].y-center.x);

        Vector a_ = M * a;

        points[i].setX(a_.GetX()+center.x);
        points[i].setY(a_.GetY()+center.x);
    }
}

Point Curve::getCenter() const {
    return std::accumulate(
        points.begin(), points.end(), Point(0, 0),
        [](Point sum, Point point) { return sum + point; }
    ) / points.size();

}

std::vector<Point> Curve::getPoints() const {
    return points;
}

void Curve::setPoints(const std::vector<Point>& points) {
    this->points = points;
}

int Curve::getN() const {
    return n;
}

void Curve::setN(int n) {
    points.resize(n);
    this->n = n;
}

Curve& Curve::operator=(const Curve& other) {
    if (this != &other) {
        points = other.points;
    }

    return *this;
}

void Curve::addPoint(const Point& point) {
    points.push_back(point);
}

void Curve::removePoint(const Point& point) {
    points.erase(std::remove(points.begin(), points.end(), point), points.end());
}

void Curve::movePoint(const Point& point, const Point& newPoint) {
    std::replace(points.begin(), points.end(), point, newPoint);
}

void Curve::moveVertex(const int index, const Point& newPoint) {
    points[index] = newPoint;
}

std::string Curve::toString()
{
    std::stringstream ss;
    ss << "Curve: {"
        << "Stroke: " << getStroke() << ", "
        << "Outline Color: " << getOutline() << ", "
        << "Fill Color: " << getFill() << ", "
        << "Shape Type: " << (getShapeType() == ShapeType::CURVE ? "CURVE" : "UNKNOWN")
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
