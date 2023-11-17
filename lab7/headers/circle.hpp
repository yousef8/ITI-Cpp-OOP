#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED

#include <iostream>
#include "point.hpp"
#include "graphics.h"

class Circle : public Shape
{
public:
    Circle(int rad, const Point& center, int color = 15):Shape {color}, rad {rad}, center{center}
    {
    }

    Circle()
    {
    }

    void setRad(int _rad)
    {
        rad = _rad;
    }

    void setCenter(const Point& _center)
    {
        center = _center;
    }

    int getRad() const
    {
        return rad;
    }

    const Point& getCenter() const
    {
        return center;
    }

    void draw() const override
    {
        setcolor(getColor());
        circle(center.getX(), center.getY(), rad);
    }

    std::ostream& print (std::ostream& out) const override
    {
        out << "Circle Rad : " << getRad() << "\tCenter : " << getCenter();
        return out;
    }

    std::istream& getInput(std::istream& in) override
    {
        std::cout << "Enter Circle\n";
        getIntInput(rad, "Radius : ");
        while (rad < 0)
        {
            std::cout << "Must be positive integer\n";
            getIntInput(rad, "Radius : ");
        }

        std::cout << "Center Point Coordinates\n";
        in >> center;

        Shape::getInput(in);

        return in;
    }

private:
    int rad;
    Point center;
};



#endif // CIRCLE_HPP_INCLUDED
