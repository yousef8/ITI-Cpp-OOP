#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED

#include <iostream>
#include "point.hpp"
#include "graphics.h"

class Circle : public Shape
{
public:
    Circle(int rad, const Point &center, int color = 0) : Shape{color}, rad{rad}, center{center}
    {
    }

    Circle()
    {
    }

    void setRad(int _rad)
    {
        rad = _rad;
    }

    void setCenter(const Point &_center)
    {
        center = _center;
    }

    int getRad() const
    {
        return rad;
    }

    const Point &getCenter() const
    {
        return center;
    }

    void draw() const override
    {
        circle(center.getX(), center.getY(), rad);
    }

    friend std::istream &operator>>(std::istream &in, Circle &c);

private:
    int rad;
    Point center;
};

std::ostream &operator<<(std::ostream &out, const Circle &c)
{
    out << "Circle Rad : " << c.getRad() << "\tCenter : " << c.getCenter();
    return out;
}

std::istream &operator>>(std::istream &in, Circle &c)
{
    std::cout << "Enter Circle\n";
    getIntInput(c.rad, "Radius : ");
    while (c.rad < 0)
    {
        std::cout << "Must be positive integer\n";
        getIntInput(c.rad, "Radius : ");
    }

    std::cout << "Center Point Coordinates\n";
    in >> c.center;

    return in;
}

#endif // CIRCLE_HPP_INCLUDED
