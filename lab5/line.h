#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include <iostream>
#include <graphics.h>
#include <cassert>
#include "point.h"

// ========================Composition==============================================
class Line
{
public:
    Line(Point &start, Point &finish) : start{start}, finish{finish}
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

    void draw()
    {
        line(start.getX(), start.getY(), finish.getX(), finish.getY());
    }

private:
    Point start;
    Point finish;
};

std::ostream &operator<<(std::ostream &cout, const Line &l)
{
    cout << l.getStart() << "----------" << l.getFinish();
    return cout;
}

// ======================================Aggregation=================================================
class LineAgg
{
public:
    LineAgg(Point *start = nullptr, Point *finish = nullptr) : start{start}, finish{finish}
    {
    }

    void setStart(Point *p)
    {
        start = p;
    }

    void setFinish(Point *p)
    {
        finish = p;
    }

    Point *const getStart() const
    {
        return start;
    }

    Point *const getFinish() const
    {
        return finish;
    }

    void draw()
    {
        assert((nullptr != start && nullptr != finish) && "One of the points are nullptr");
        line(start->getX(), start->getY(), finish->getX(), finish->getY());
    }

private:
    Point *start;
    Point *finish;
};

std::ostream &operator<<(std::ostream &out, const LineAgg &l)
{
    if (l.getStart() == nullptr)
    {
        out << "NULL";
    }
    else
    {
        out << *(l.getStart());
    }

    out << "----------";

    if (nullptr == l.getFinish())
    {
        out << "NULL";
    }
    else
    {
        out << *(l.getFinish());
    }
    return out;
}

// ===============================Association==============================
class LineAss
{
public:
    LineAss()
    {
    }

    void print(Point *const start, Point *const finish)
    {
        if (nullptr == start)
        {
            std::cout << "NULL";
        }
        else
        {
            std::cout << *(start);
        }

        std::cout << "----------";

        if (nullptr == finish)
        {
            std::cout << "NULL";
        }
        else
        {
            std::cout << *(finish);
        }
    }

    void draw(Point *const start, Point *const finish)
    {
        assert((nullptr != start && nullptr != finish) && "One of the points are nullptr");
        line(start->getX(), start->getY(), finish->getX(), finish->getY());
    }
};
#endif // LINE_H_INCLUDED