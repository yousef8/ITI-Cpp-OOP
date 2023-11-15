#include <iostream>
#include "point.h"
#include "line.h"
#include "circle.h"
/*
class Rectangle {
public:
    Rectangle(Point& topLeft, Point& bottomRight) : topLeft{topLeft}, bottomRight {bottomRight}
    {
    }

    const Point& getTopLeft() const {
        return topLeft;
    }

    const Point& getBottomRight() const {
        return bottomRight;
    }

private:
    Point topLeft;
    Point bottomRight;
};

std::ostream& operator << (std::ostream& cout, Rectangle& r)
{
    cout << "Rectangle : " << r.getTopLeft() << " " <<  r.getBottomRight();
    return cout;
}
*/

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");

    std::cout << "Hello world!\n";

    Point p {3, 3};
    Point p2 {100, 100};

    //LineAgg li {&p};
    //std::cout << li << "\n";

    //LineAss li{};
    //li.print(&p, &p2);

    //Circle c {50, p2};
    //c.draw();
    //std::cout << c << "\n";

    //CircleAgg c {5, &p2};
    //c.draw();
    //std::cout << c << "\n";

    //CircleAgg c {};
    //c.draw();
    //std::cout << c << "\n";

    //CircleAss c {};
    //c.draw(30, &p2);
    //c.print(30, &p2);

    CircleAss c {};
    c.draw(30, &p2);
    c.print(30, nullptr);

    getch();
    closegraph();
    return 0;
}
