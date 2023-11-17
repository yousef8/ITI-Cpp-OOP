#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED

#include <iostream>
#include "shape.hpp"
#include "point.hpp"
#include "graphics.h"

class Line : public Shape
{
public:
    Line(Point& start, Point& finish, int color = 15):Shape {color}, start{start}, finish {finish}
    {
    }

    Line()
    {
    }

    void setStart(Point& p)
    {
        start = p;
    }

    void setFinish(Point& p)
    {
        finish = p;
    }

    const Point& getStart() const
    {
        return start;
    }

    const Point& getFinish() const
    {
        return finish;
    }

    void draw() const override
    {
        setcolor(getColor());
        line(start.getX(), start.getY(), finish.getX(), finish.getY());
    }

    std::ostream& print(std::ostream& out) const override
    {
        out << getStart() << "----------" <<  getFinish();
        return out;
    }

    std::istream& getInput(std::istream& in) override
    {
        std::cout << "Enter Line\nStart Point Coordinates\n";
        Point p;
        in >> p;
        setStart(p);
        std::cout << "Finish Point Coordinates\n";
        in >> p;
        setFinish(p);
        Shape::getInput(in);

        return in;
    }
private:
    Point start;
    Point finish;
};

#endif // LINE_HPP_INCLUDED
