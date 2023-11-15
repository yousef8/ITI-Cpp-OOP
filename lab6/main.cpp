#include <iostream>
#include <string>

#include "headers/rectangle.hpp"
#include "headers/circle.hpp"
#include "headers/line.hpp"
#include "headers/inputValidation.hpp"

void recTestCase(void);
void circleTestCase(void);
void lineTestCase(void);

int main()
{
    // recTestCase();
    // circleTestCase();
    // lineTestCase();

    int shapes = 0;
    do
    {
        getIntInput(shapes, "Enter number of shapes you want (0 quit): ");
        if (0 == shapes)
        {
            return 0;
        }

        if (shapes < 0)
        {
            std::cout << "Must be Positive Integer\n";
        }
    } while (shapes < 0);

    Rect recs[shapes]{};
    int recIdx{0};

    Circle circles[shapes]{};
    int circIdx{0};

    Line lines[shapes]{};
    int lineIdx{0};

    for (int i{0}; i < shapes; ++i)
    {
        int choice{0};
        getIntInput(choice, std::string{"Shape " + std::to_string(i + 1) + " what will be ( Circle 0, Rectangle 1, Line 2) : "});

        switch (choice)
        {
        case 0:
            std::cin >> circles[circIdx++];
            break;
        case 1:
            std::cin >> recs[recIdx++];
            break;
        case 2:
            std::cin >> lines[lineIdx++];
            break;
        default:
            std::cout << "Wrong Choice\n";
            --i;
            break;
        }
    }

    // Draw Shapes
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "d:\\tc\\bgi");

    for (int i{0}; i < recIdx; ++i)
    {
        recs[i].draw();
    }

    for (int i{0}; i < circIdx; ++i)
    {
        circles[i].draw();
    }

    for (int i{0}; i < lineIdx; ++i)
    {
        lines[i].draw();
    }

    getch();
    closegraph();

    return 0;
}

void recTestCase()
{

    std::cout << "=========Testing Rectangle========\n";
    Point p1{56, 89};
    Point p2{100, 100};

    Rect rec{p1, p2};
    std::cout << "Draw " << rec << "\n";

    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "d:\\tc\\bgi");

    rec.draw();

    getch();
    closegraph();

    // Rect rec2 {};
    std::cin >> rec;

    std::cout << "Draw " << rec << "\n";

    initgraph(&gdriver, &gmode, "d:\\tc\\bgi");

    rec.draw();

    getch();
    closegraph();

    return;
}

void circleTestCase()
{

    std::cout << "=========Testing Rectangle========\n";
    Point p1{56, 89};
    Point p2{100, 100};

    Circle c{50, p2};
    std::cout << "Draw " << c << "\n";

    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "d:\\tc\\bgi");

    c.draw();

    getch();
    closegraph();

    std::cout << "Enter your own coordinates\n";
    std::cin >> c;
    std::cout << "Draw " << c << "\n";

    initgraph(&gdriver, &gmode, "d:\\tc\\bgi");

    c.draw();

    getch();
    closegraph();

    return;
}

void lineTestCase()
{
    Point p1{56, 89};
    Point p2{100, 100};

    Line l{p1, p2};
    std::cout << "Draw " << l << "\n";

    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "d:\\tc\\bgi");
    l.draw();
    getch();
    closegraph();

    std::cout << "Enter your own coordinates\n";
    std::cin >> l;
    std::cout << "Draw " << l << "\n";

    initgraph(&gdriver, &gmode, "d:\\tc\\bgi");

    l.draw();

    getch();
    closegraph();

    return;
}
