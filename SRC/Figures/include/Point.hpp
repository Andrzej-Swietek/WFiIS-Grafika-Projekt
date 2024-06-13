#pragma once


/**
 * @brief A structure representing a point in 2D space.
 */
struct Point {
    int x, y;


    /**
     * @brief Construct a new Point object
     * @param x x-coordinate (default 0)
     * @param y y-coordinate (default 0)
     */
    Point(int x=0, int y=0) : x(x), y(y) {}


    /**
     * @brief Get the x-coordinate of the point.
     * @return int x-coordinate
     */
    int getX() const {
        return x;
    }


    /**
     * @brief Get the y-coordinate of the point.
     * @return int y-coordinate
     */
    int getY() const {
        return y;
    }


    /**
     * @brief Set the x-coordinate of the point.
     * @param x new x-coordinate
     * @return no return
     */
    void setX(int x) {
        this->x = x;
    }


    /**
     * @brief Set the y-coordinate of the point.
     * @param y new y-coordinate
     * @return no return
     */
    void setY(int y) {
        this->y = y;
    }


    /**
     * @brief Addition operator for adding two points.
     * @param other the other point to add
     * @return Point resulting point
     */
    Point operator+(Point const& other) {
        Point p;
        p.x = this->x + other.x;
        p.y = this->y + other.y;
        return p;
    }


    /**
     * @brief Subtraction operator for subtracting two points.
     * @param other the other point to subtract
     * @return Point resulting point
     */
    Point operator-(Point const& other) {
        Point p;
        p.x = this->x - other.x;
        p.y = this->y - other.y;
        return p;
    }



Sure, here is the documentation added to the Point struct, following a similar style as used for the classes:

cpp
Skopiuj kod
#pragma once

/**
 * @brief A structure representing a point in 2D space.
 */
struct Point {
    int x, y;

    /**
     * @brief Construct a new Point object with given coordinates.
     * @param x x-coordinate of the point (default is 0)
     * @param y y-coordinate of the point (default is 0)
     */
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    /**
     * @brief Get the x-coordinate of the point.
     * @return int x-coordinate
     */
    int getX() const {
        return x;
    }

    /**
     * @brief Get the y-coordinate of the point.
     * @return int y-coordinate
     */
    int getY() const {
        return y;
    }

    /**
     * @brief Set the x-coordinate of the point.
     * @param x new x-coordinate
     * @return no return
     */
    void setX(int x) {
        this->x = x;
    }

    /**
     * @brief Set the y-coordinate of the point.
     * @param y new y-coordinate
     * @return no return
     */
    void setY(int y) {
        this->y = y;
    }

    /**
     * @brief Addition operator for adding two points.
     * @param other the other point to add
     * @return Point resulting point
     */
    Point operator+(Point const& other) {
        Point p;
        p.x = this->x + other.x;
        p.y = this->y + other.y;
        return p;
    }

    /**
     * @brief Subtraction operator for subtracting two points.
     * @param other the other point to subtract
     * @return Point resulting point
     */
    Point operator-(Point const& other) {
        Point p;
        p.x = this->x - other.x;
        p.y = this->y - other.y;
        return p;
    }

    /**
     * @brief Equality operator to check if two points are equal.
     * @param p the other point to compare
     * @return bool true if points are equal, false otherwise
     */
    bool operator == (const Point& p) {
        return this->x == p.x && this->y == p.y;
    }


    /**
     * @brief Division operator to divide point coordinates by a scalar.
     * @param n the scalar to divide by
     * @return Point resulting point
     */
    Point operator / (const int n) {
        Point p;
        p.x = this->x / n;
        p.y = this->y / n;
        return p;
    }
};