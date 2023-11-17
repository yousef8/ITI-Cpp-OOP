#ifndef RECTANGLE_HPP_INCLUDED
#define RECTANGLE_HPP_INCLUDED

#include "shape.hpp"
#include "graphics.h"
#include "point.hpp"

class Rect : public Shape
{
public:
    Rect(const Point& topLeft, const Point& bottomRight, int color = 15): Shape{color}, topLeft{topLeft}, bottomRight {bottomRight}
    {
    }

    Rect():Shape{},topLeft{}, bottomRight{}
    {
    }

    void setTopLeft(const Point& tl)
    {
        topLeft = tl;
    }

    void setBottomRight(const Point& br)
    {
        bottomRight = br;
    }

    const Point& getTopLeft() const
    {
        return topLeft;
    }

    const Point& getBottomRight() const
    {
        return bottomRight;
    }

    void draw() const override
    {
        setcolor(getColor());
        rectangle(getTopLeft().getX(), getTopLeft().getY(), getBottomRight().getX(), getBottomRight().getY());
    }

    std::ostream& print (std::ostream& out) const override
    {
        out << "Rectangle upper-left " << getTopLeft() << "\tlower-right " << getBottomRight();

        return out;
    }

    std::istream& getInput(std::istream& in) override
    {
        std::cout << "Enter Rectangle\nUpper Left point\n";
        in >> topLeft;

        std::cout << "Lower Right point\n";
        in >> bottomRight;

        Shape::getInput(in);

        return in;
    }

private:
    Point topLeft;
    Point bottomRight;
};

#endif // RECTANGLE_HPP_INCLUDED
