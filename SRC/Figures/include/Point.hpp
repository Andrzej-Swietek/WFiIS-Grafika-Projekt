#pragma once

struct Point {
    int x, y;

    Point(int x=0, int y=0) : x(x), y(y) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    Point operator+(Point const& other) {
        Point p;
        p.x = this->x + other.x;
        p.y = this->y + other.y;
        return p;
    }

    Point operator-(Point const& other) {
        Point p;
        p.x = this->x - other.x;
        p.y = this->y - other.y;
        return p;
    }

    bool operator == (const Point& p) {
        return this->x == p.x && this->y == p.y;
    }


    Point operator / (const int n) {
        Point p;
        p.x = this->x / n;
        p.y = this->y / n;
        return p;
    }
};