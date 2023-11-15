#ifndef RECTANGLE_HPP_INCLUDED
#define RECTANGLE_HPP_INCLUDED

#include "shape.hpp"
#include "graphics.h"
#include "point.hpp"

class Rect : public Shape
{
public:
    Rect(const Point &topLeft, const Point &bottomRight, int color = 0) : Shape{color}, topLeft{topLeft}, bottomRight{bottomRight}
    {
    }

    Rect() : Shape{}, topLeft{}, bottomRight{}
    {
    }

    void setTopLeft(const Point &tl)
    {
        topLeft = tl;
    }

    void setBottomRight(const Point &br)
    {
        bottomRight = br;
    }

    const Point &getTopLeft() const
    {
        return topLeft;
    }

    const Point &getBottomRight() const
    {
        return bottomRight;
    }

    void draw() const override
    {
        rectangle(getTopLeft().getX(), getTopLeft().getY(), getBottomRight().getX(), getBottomRight().getY());
    }

    friend std::istream &operator>>(std::istream &in, Rect &r);

private:
    Point topLeft;
    Point bottomRight;
};

std::ostream &operator<<(std::ostream &out, const Rect &rec)
{
    out << "Rectangle upper-left " << rec.getTopLeft() << "\tlower-right " << rec.getBottomRight();

    return out;
}

std::istream &operator>>(std::istream &in, Rect &r)
{

    std::cout << "Enter Rectangle\nUpper Left point\n";
    in >> r.topLeft;

    std::cout << "Lower Right point\n";
    in >> r.bottomRight;

    return in;
}

#endif // RECTANGLE_HPP_INCLUDED
