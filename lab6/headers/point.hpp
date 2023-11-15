#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

#include <iostream>
#include "inputValidation.hpp"

class Point
{
public:
    Point(int x = 0, int y = 0) : x{x}, y{y}
    {
    }

    void setX(int _x)
    {
        x = _x;
        return;
    }

    int getX() const
    {
        return x;
    }

    void setY(int _y)
    {
        y = _y;
        return;
    }

    int getY() const
    {
        return y;
    }

    void setXY(int _x, int _y)
    {
        setX(_x);
        setY(_y);
    }

private:
    int x;
    int y;
};

std::ostream &operator<<(std::ostream &cout, const Point &p)
{
    cout << "(" << p.getX() << " , " << p.getY() << ")";
    return cout;
}

std::istream &operator>>(std::istream &in, Point &p)
{
    // To-Do : Handle Input Validation
    int x = 0;
    // in >> x;
    getIntInput(x, "x ");
    while (x < 0)
    {
        std::cout << "Must be Positive Integer\n";
        getIntInput(x, "x ");
    }

    int y = 0;
    // in >> y;
    getIntInput(y, "y ");
    while (y < 0)
    {
        std::cout << "Must be Positive Integer\n";
        getIntInput(y, "y ");
    }

    p.setXY(x, y);
    return in;
}
#endif // POINT_HPP_INCLUDED
