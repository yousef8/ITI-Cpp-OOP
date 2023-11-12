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

    void operator=(const Stack &s)
    {
        size = s.getSize();
        top = 0;
        delete[] arr;
        arr = new int[s.getSize() + 1];

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

int testCase1(Stack s)
{
    std::cout << "\nTest Case 1\n";
    std::cout << "current stack\n";
    s.print();
    std::cout << "\nPop " << s.pop() << "\n";
    std::cout << "\nPop " << s.pop() << "\n";

    return 0;
}

void assignmentCopyTestCase()
{
    std::cout << "==========Stack 1=========\n";
    Stack s1{10};
    s1.push(7);
    s1.push(5);
    s1.push(4);
    s1.push(9);

    std::cout << "Size is " << s1.getSize() << "\n";
    s1.print();

    std::cout << "==========Stack 2===========\n";
    Stack s2{5};
    s2.push(3);
    s2.push(4);
    s2.push(11);

    std::cout << "Size is " << s2.getSize() << "\n";
    s2.print();

    std::cout << "==============Stack 1 = Stack 2==============\n";
    s1 = s2;
    std::cout << "Size is " << s1.getSize() << "\n";
    s1.print();

    return;
}

int main()
{

    assignmentCopyTestCase();
    return 0;
}
