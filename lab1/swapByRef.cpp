#include <iostream>

using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{

    int x {5}, y {6};

    cout << "Before Swap\n";
    cout << "X\ty\n" << x << "\t" << y << "\n";

    swap(x, y);

    cout << "\nAfter Swap\n";
    cout << "X\ty\n" << x << "\t" << y << "\n";

    return 0;

}