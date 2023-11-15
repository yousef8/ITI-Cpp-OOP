#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

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
        return x;
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

#endif // POINT_H_INCLUDED