#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED

#include <iostream>
#include "shape.hpp"
#include "point.hpp"
#include "graphics.h"

class Line : public Shape
{
public:
    Line(Point &start, Point &finish) : start{start}, finish{finish}
    {
    }

    Line()
    {
    }

    void setStart(Point &p)
    {
        start = p;
    }

    void setFinish(Point &p)
    {
        finish = p;
    }

    const Point &getStart() const
    {
        return start;
    }

    const Point &getFinish() const
    {
        return finish;
    }

    void draw() const override
    {
        // int gdriver = DETECT, gmode, errorcode;
        // initgraph(&gdriver,&gmode,"d:\\tc\\bgi");

        line(start.getX(), start.getY(), finish.getX(), finish.getY());

        // getch();
        // closegraph();
    }
    friend std::istream &operator>>(std::istream &in, Line &l);

private:
    Point start;
    Point finish;
};

std::ostream &operator<<(std::ostream &cout, const Line &l)
{
    cout << l.getStart() << "----------" << l.getFinish();
    return cout;
}

std::istream &operator>>(std::istream &in, Line &l)
{

    std::cout << "Enter Line\nStart Point Coordinates\n";
    Point p;
    in >> p;
    l.setStart(p);
    std::cout << "Finish Point Coordinates\n";
    in >> p;
    l.setFinish(p);

    return in;
}

#endif // LINE_HPP_INCLUDED