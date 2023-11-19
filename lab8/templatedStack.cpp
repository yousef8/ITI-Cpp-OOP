#include <iostream>
#include <string>
#include <utility>

template <class T>
class Stack
{
public:
	Stack(int cap = 10) : capacity{(cap <= 0) ? 10 : cap},
												tos{-1}, arr{new T[capacity]}
	{
	}

	~Stack()
	{
		delete[] arr;
	}

	int getSize() const
	{
		return tos + 1;
	}

	bool isEmpty() const
	{
		if (0 == getSize())
		{
			return true;
		}
		return false;
	}

	const T &top() const
	{
		if (isEmpty())
		{
			throw "Empty Stack";
		}
		return arr[tos];
	}

	void push(const T &elem)
	{
		if (getSize() == capacity)
		{
			expand();
		}

		arr[++tos] = elem;

		return;
	}

	T pop()
	{
		if (isEmpty())
		{
			throw "Empty Stack";
		}

		return std::move(arr[tos--]);
	}

	void expand()
	{
		int newCapacity = capacity * 2;
		T *newArr = new T[newCapacity];

		for (int i{0}; i < getSize(); ++i)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;
		capacity = newCapacity;

		return;
	}

	friend std::ostream &operator<<(std::ostream &out, const Stack<T> &s)
	{
		for (int i{0}; i < s.tos; ++i)
		{
			out << s.arr[i] << " ";
		}

		if (!s.isEmpty())
		{
			out << "[" << s.arr[s.tos] << "]";
		}
		else
		{
			out << "Empty";
		}

		out << " \tSize : " << s.getSize() << " \t Capacity : " << s.capacity;

		return out;
	}

private:
	int tos;
	int capacity;
	T *arr;
};

int main()
{
	std::cout << "======================Main================\n";
	std::cout << "============Integer Stack=======\n";
	Stack<int> s{1};
	std::cout << s << "\n";
	try
	{
		s.pop();
	}
	catch (const char *e)
	{
		std::cout << "Trying to pop Empty Stack\n";
	}

	s.push(5);
	s.push(7);
	s.push(20);

	std::cout << s << "\n";

	std::cout << "\n============String Stack=======\n";
	Stack<std::string> ss{1};
	std::cout << ss << "\n";
	ss.push("yousef");
	ss.push("elsayed");
	ss.push("sobhy");
	std::cout << ss << "\n";
	std::cout << "Top of the stack is [" << ss.top() << "]\n";
	std::cout << "Pop : " << ss.pop() << "\n";
	std::cout << ss << "\n";

	return 0;
}