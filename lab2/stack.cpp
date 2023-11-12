#include <iostream>

class Stack
{
public:
    Stack(int size) : size{size}, top{0}, arr{new int[size + 1]}
    {
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return top > 0;
    }

    void push(int num)
    {
        if (top < size)
        {
            arr[++top] = num;
            return;
        }
        std::cout << "\nStack is full!!!!\n";
        return;
    }

    int pop()
    {
        if (top > 0)
        {
            return arr[top--];
        }

        std::cout << "\nStack is empty\n";
        return 0;
    }

    void print()
    {
        std::cout << "Top\n";
        for (int i = 1; i <= top; ++i)
        {
            std::cout << arr[i] << "\n";
        }
        std::cout << "\n";
    }

    ~Stack()
    {
        delete[] arr;
        std::cout << "\nStack Deleted\n";
    }

private:
    int size;
    int top;
    int *arr;
};

int main()
{
    // Stack s{5};
    // std::cout << "\n=============Initialized=============\n";

    // std::cout << "Size is " << s.getSize() << "\n";
    // for (int i = 1; i <= 10; ++i)
    // {
    //     s.push(i);
    // }
    // s.print();

    // std::cout << "\n=============POP=============\n";

    // for (int i = 1; i <= 10; ++i)
    // {
    //     std::cout << s.pop() << "\n";
    // }

    // std::cout << "\n=============REFIL=============\n";
    // for (int i = 1; i <= 10; ++i)
    // {
    //     s.push(i);
    // }

    // s.print();

    // std::cout << "\n=============2nd POP=============\n";

    // for (int i = 1; i <= 10; ++i)
    // {
    //     std::cout << s.pop() << "\n";
    // }

    // std::cout << "\n=============REFIL=============\n";
    // for (int i = 1; i <= 10; ++i)
    // {
    //     s.push(i);
    // }

    // s.print();

    // std::cout << "\n=============2nd POP=============\n";

    // for (int i = 1; i <= 10; ++i)
    // {
    //     std::cout << s.pop() << "\n";
    // }

    Stack s{5};
    std::cout << s.pop() << "\n"; // empty
    s.push(1);
    s.push(5);
    s.push(6);
    std::cout << s.pop() << "\n"; // 1
    std::cout << s.pop() << "\n"; // 5
    s.push(7);
    std::cout << s.pop() << "\n"; // 6
    std::cout << s.pop() << "\n"; // 7
    std::cout << s.pop() << "\n"; // Empty
    s.push(7);
    std::cout << s.pop() << "\n"; // 7
    // 1567Empty7
    return 0;
}
