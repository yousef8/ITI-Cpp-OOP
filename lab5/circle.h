#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include <iostream>
#include "graphics.h"
#include "point.h"

// ===========================Composition======================
class Circle
{
public:
    Circle(int rad, Point &center) : rad{rad}, center{center}
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

    void draw() const
    {
        circle(center.getX(), center.getY(), rad);
    }

private:
    int rad;
    Point center;
};

std::ostream &operator<<(std::ostream &out, const Circle &c)
{
    out << "Rad : " << c.getRad() << "\tCenter " << c.getCenter();

    return out;
}

// =================================Aggregation=========================

class CircleAgg
{
public:
    CircleAgg(int rad = 0, Point *center = nullptr) : rad{rad}, center{center}
    {
    }

    void setRad(int _rad)
    {
        rad = _rad;
    }

    void setCenter(Point *_center)
    {
        center = _center;
    }

    int getRad() const
    {
        return rad;
    }

    Point *const getCenter() const
    {
        return center;
    }

    void draw() const
    {
        assert((nullptr != center) && "No Center Point coordinates exist");
        circle(center->getX(), center->getY(), rad);
    }

private:
    int rad;
    Point *center;
};

std::ostream &operator<<(std::ostream &out, const CircleAgg &c)
{
    out << "Rad : " << c.getRad();
    if (nullptr != c.getCenter())
    {
        out << "\tCenter " << *(c.getCenter());
    }
    else
    {
        out << "\tCenter : Null\n";
    }

    return out;
}

// ======================================Association===================================

class CircleAss
{
public:
    CircleAss() = default;

    void print(int rad, Point *const center) const
    {
        std::cout << "Rad : " << rad;
        if (nullptr != center)
        {
            std::cout << "\tCenter " << *center;
        }
        else
        {
            std::cout << "\tCenter : Null\n";
        }
    }

    void draw(int rad, Point *const center) const
    {
        assert((nullptr != center) && "No Center Point coordinates exist");
        circle(center->getX(), center->getY(), rad);
    }

private:
    int rad;
    Point *center;
};

#endif // CIRCLE_H_INCLUDED