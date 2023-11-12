#include <iostream>
#include <limits>

class Queue
{
public:
    Queue(int capacity) : front{-1}, back{-1}, size{0}, capacity{capacity}, arr{new int[capacity]}
    {
    }

    bool isFull()
    {
        return size == capacity;
    }

    bool isEmpty()
    {
        return 0 == size;
    }

    void enqueue(int elem)
    {
        if (isFull())
        {
            std::cout << "Queue is full\n";
            return;
        }

        if (capacity - 1 == back)
        {
            back = -1;
        }

        if (-1 == front)
        {
            ++front;
        }

        arr[++back] = elem;
        ++size;
        return;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is Empty\n";
            return INT_MIN;
        }

        if (front == capacity)
        {
            front = 0;
        }

        --size;
        return arr[front++];
    }

private:
    int front;
    int back;
    int size;
    int capacity;
    int *arr;
};

int main()
{
    Queue q(5);
    // q.isEmpty();

    // std::cout << q.dequeue() << "\n"; //
    // q.enqueue(5);                     //
    // q.enqueue(7);                     //
    // q.enqueue(10);                    //
    // std::cout << q.dequeue() << "\n"; // 5
    // std::cout << q.dequeue() << "\n"; // 7
    // q.enqueue(11);                    //
    // std::cout << q.dequeue() << "\n"; // 10
    // std::cout << q.dequeue() << "\n"; // 11
    // std::cout << q.dequeue() << "\n"; // Empty

    std::cout << q.dequeue() << "\n"; //
    q.enqueue(5);                     //
    q.enqueue(7);                     //
    q.enqueue(10);                    //
    std::cout << q.dequeue() << "\n"; // 5
    std::cout << q.dequeue() << "\n"; // 7
    std::cout << q.dequeue() << "\n"; // 10
    std::cout << q.dequeue() << "\n"; // empty

    q.enqueue(11);                    //
    std::cout << q.dequeue() << "\n"; // 11
    std::cout << q.dequeue() << "\n"; // Empty
    std::cout << q.dequeue() << "\n"; // Empty
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    std::cout << q.dequeue() << "\n"; // 1
    std::cout << q.dequeue() << "\n"; // 2
    std::cout << q.dequeue() << "\n"; // 3
    std::cout << q.dequeue() << "\n"; // 4
    std::cout << q.dequeue() << "\n"; // 5
    std::cout << q.dequeue() << "\n"; // empty

    return 0;
}