#ifndef SHAPE_HPP_INCLUDED
#define SHAPE_HPP_INCLUDED

class Shape
{
public:
    Shape(int color = 0) : color{color}
    {
    }

    void setColor(int _color)
    {
        color = _color;
    }

    int getColor()
    {
        return color;
    }
    virtual void draw() const = 0;

private:
    int color;
};

#endif // SHAPE_HPP_INCLUDED
