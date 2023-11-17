#include <iostream>
#include <string>
#include <utility>

#include "headers/rectangle.hpp"
#include "headers/circle.hpp"
#include "headers/line.hpp"
#include "headers/inputValidation.hpp"

void recTestCase(void);
void circleTestCase(void);
void lineTestCase(void);

int main()
{
    //recTestCase();
    //circleTestCase();
    //lineTestCase();

    int numOfShapes = 0;
    do
    {
        getIntInput(numOfShapes, "Enter number of shapes you want (0 quit): ");
        if (0 == numOfShapes)
        {
            return 0;
        }

        if(numOfShapes < 0)
        {
            std::cout << "Must be Positive Integer\n";
        }
    }
    while(numOfShapes < 0);


    Shape* shapes[numOfShapes];
    int cnt {0};

    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");

    for(int i {0}; i < numOfShapes; ++i)
    {
        int choice {0};
        getIntInput(choice, std::string {"Shape " + std::to_string(i+1) + " what will be ( Circle 0, Rectangle 1, Line 2) : "});

        switch (choice)
        {
        case 0:
        {
            Circle* c {new Circle};
            std::cin >> *c;
            shapes[cnt++] = c;
            shapes[cnt-1]->draw();
            break;
        }
        case 1:
        {
            Rect * r {new Rect};
            std::cin >> *r;
            shapes[cnt++] = r;
            shapes[cnt-1]->draw();
            break;
        }

        case 2:
        {
            Line* l {new Line};
            std::cin >> *l;
            shapes[cnt++] = l;
            shapes[cnt-1]->draw();
            break;
        }

        default:
            std::cout << "Wrong Choice\n";
            --i;
            break;
        }
    }

    getch();
    closegraph();

    for (auto& s : shapes)
        delete s;

    return 0;
}
void recTestCase()
{

    std::cout << "=========Testing Rectangle========\n";
    Point p1 {56, 89};
    Point p2 {100, 100};

    Rect rec {p1, p2};
    std::cout << "Draw " << rec << "\n";

    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");

    rec.draw();

    getch();
    closegraph();

    //Rect rec2 {};
    std::cin >> rec;

    std::cout << "Draw " << rec << "\n";

    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");

    rec.draw();

    getch();
    closegraph();

    return;
}

void circleTestCase()
{

    std::cout << "=========Testing Rectangle========\n";
    Point p1 {56, 89};
    Point p2 {100, 100};

    Circle c {50, p2};
    std::cout << "Draw " << c << "\n";

    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");

    c.draw();

    getch();
    closegraph();



    std::cout << "Enter your own coordinates\n";
    std::cin >> c;
    std::cout << "Draw " << c << "\n";

    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");

    c.draw();

    getch();
    closegraph();


    return;
}

void lineTestCase()
{
    Point p1 {56, 89};
    Point p2 {100, 100};

    Line l {p1, p2};
    std::cout << "Draw " << l << "\n";

    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
    l.draw();
    getch();
    closegraph();



    std::cout << "Enter your own coordinates\n";
    std::cin >> l;
    std::cout << "Draw " << l << "\n";

    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");

    l.draw();

    getch();
    closegraph();


    return;
}
