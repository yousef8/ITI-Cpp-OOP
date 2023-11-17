#ifndef SHAPE_HPP_INCLUDED
#define SHAPE_HPP_INCLUDED

#include <iostream>
#include "inputValidation.hpp"

class Shape
{
public:
    Shape(int color = 15): color {color}
    {
    }

    void setColor(int _color)
    {
        color = _color;
    }

    int getColor()const
    {
        return color;
    }
    virtual void draw() const = 0;
    virtual std::ostream& print(std::ostream& out) const
    {
        out << "Shape";
        return out;
    };

    virtual std::istream& getInput(std::istream& in)
    {
        std::cout << "Color (BLACK 0 ~ WHITE 15)\n";
        int color = 0;
        getIntInput(color, "Color : ");
        while (0 > color || color > 15)
        {
            std::cout << "Must be positive integer between 0 and 15\n";
            getIntInput(color, "Color : ");
        }
        setColor(color);

        return in;
    }

    friend std::istream& operator >> (std::istream& in, Shape& s);
    friend std::ostream& operator << (std::ostream& out, const Shape& s);
private:
    int color;
};

std::istream& operator >> (std::istream& in, Shape& s)
{
    return s.getInput(in);
}

std::ostream& operator << (std::ostream& out, const Shape& s)
{
    return s.print(out);
}

#endif // SHAPE_HPP_INCLUDED
