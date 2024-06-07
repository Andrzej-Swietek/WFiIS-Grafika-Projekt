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


void Circle::draw(wxDC* dc, int canvWidth, int canvHeight) const {
    std::cout << "Drawing a circle at (" << x << ", " << y << ") with radius " << r << std::endl;


    //dc->SetPen(*wxBLACK);  // outline
    //dc->SetBrush(wxBrush(*wxBLUE_BRUSH));  // fill

    // TODO: shape scaling policy is??
    //dc->DrawCircle(wxPoint(x*canvWidth/100, y*canvHeight/100), r*canvWidth/100);
    int scaler = (canvWidth < canvHeight) ? canvWidth : canvHeight;

    int centerX = x * scaler / 100;
    int centerY = y * scaler / 100;
    int radius = r * scaler / 100;
    wxColour outlineColor = *wxBLUE;
    int strokeWidth = stroke /** canvWidth / 100*/;
    wxColour fillColor = *wxYELLOW;

    wxPen pen(outlineColor, strokeWidth);
    dc->SetPen(pen);
    wxBrush brush(fillColor);
    dc->SetBrush(brush);

    dc->DrawCircle(centerX, centerY, radius);
}

//
// does rotating a circle make sense??
void Circle::rotate()
{
    /*Vector a;

    a.Set(pt.x, pt.y);

    Vector a_ = rotationMatrix * a;

    pt.x = a_.GetX();
    pt.y = a_.GetY();*/
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