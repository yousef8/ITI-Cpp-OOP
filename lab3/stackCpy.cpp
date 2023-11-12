#include <iostream>
#include <limits>

class Stack
{
public:
    Stack(int size) : size{size}, top{0}, arr{new int[size + 1]}
    {
    }

    Stack(Stack &s) : Stack(s.getSize())
    {
        for (int i = 1; i <= s.top; ++i)
        {
            push(s.arr[i]);
        }
    }

    int getSize() const
    {
        return size;
    }

    bool isEmpty() const
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
        return INT_MIN;
    }

    void print() const
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

int testCase1(Stack s)
{
    std::cout << "\nTest Case 1\n";
    std::cout << "current stack\n";
    s.print();
    std::cout << "\nPop " << s.pop() << "\n";
    std::cout << "\nPop " << s.pop() << "\n";

    return 0;
}

int main()
{

    Stack s{10};
    s.push(7);
    s.push(5);
    s.push(4);
    s.push(9);
    std::cout << "Current Stack\n";
    s.print();

    testCase1(s);

    std::cout << "\n==============Main============\n";
    std::cout << "\nPop " << s.pop();

    // Stack s{5};
    // std::cout << s.pop() << "\n"; // empty
    // s.push(1);
    // s.push(5);
    // s.push(6);
    // std::cout << s.pop() << "\n"; // 1
    // std::cout << s.pop() << "\n"; // 5
    // s.push(7);
    // std::cout << s.pop() << "\n"; // 6
    // std::cout << s.pop() << "\n"; // 7
    // std::cout << s.pop() << "\n"; // Empty
    // s.push(7);
    // std::cout << s.pop() << "\n"; // 7
    // // 1567Empty7
    return 0;
}
