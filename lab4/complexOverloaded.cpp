#include <iostream>
#include <cassert>
#include <string_view>

using namespace std;

class Complex
{

public:
    Complex(int real = 0, int imag = 0)
    {
        setReal(real);
        setImag(imag);
    }

    int setReal(int num)
    {
        real = num;
        return 0;
    }

    int getReal(void) const
    {
        return real;
    }

    int setImag(int num)
    {
        imag = num;
        return 0;
    }

    int getImag(void) const
    {
        return imag;
    }

    Complex operator+(const Complex &c) const
    {
        Complex res{getReal() + c.getReal(), getImag() + c.getImag()};
        return res;
    }

    Complex operator+(int num) const
    {
        Complex res{getReal() + num, getImag()};
        return res;
    }

    Complex operator-(const Complex &c) const
    {
        Complex res{getReal() - c.getReal(), getImag() - c.getImag()};
        return res;
    }

    Complex operator-(int num) const
    {
        Complex res{getReal() - num, getImag()};
        return res;
    }

    operator float()
    {
        return real;
    }

    void operator+=(const Complex &c)
    {
        *this = *this + c;
        return;
    }

    void operator-=(const Complex &c)
    {
        *this = *this - c;
        return;
    }

    // Prefix increment
    Complex &operator++()
    {
        setReal(getReal() + 1);
        return *this;
    }

    // Prefix decrement
    Complex &operator--()
    {
        setReal(getReal() - 1);
        return *this;
    }

    // Postfix increment
    Complex operator++(int)
    {
        Complex oldComp{*this};
        setReal(getReal() + 1);
        return oldComp;
    }

    // Postfix decrement
    Complex operator--(int)
    {
        Complex oldComp{*this};
        setReal(getReal() - 1);
        return oldComp;
    }

    // Comparison Operator
    bool operator==(const Complex &c) const
    {
        return (getReal() == c.getReal() && getImag() == c.getImag());
    }

    // Subscript Overload
    int &operator[](int idx)
    {
        assert((0 == idx || 1 == idx) && "Need to provide Exceptions for Index out of range error");

        if (0 == idx)
        {
            return real;
        }

        return imag;
    }

    int &operator[](std::string_view str)
    {
        assert(("real" == str || "Real" == str || "imag" == str || "Imag" == str) && "Need to provide Exceptions for Index out of range error");

        if ("real" == str || "Real" == str)
        {
            return real;
        }

        return imag;
    }

private:
    int imag;
    int real;
};

std::ostream &operator<<(std::ostream &out, const Complex &c)
{
    out << c.getReal();
    if (c.getImag() > 0)
    {
        out << "+" << c.getImag() << "j"
            << "\n";
    }
    else if (c.getImag() < 0)
    {
        out << c.getImag() << "j"
            << "\n";
    }
    else
    {
        out << "\n";
    }

    return out;
}

std::istream &operator>>(std::istream &in, Complex &c)
{
    int real = 0, imag = 0;
    in >> real >> imag;
    c.setReal(real);
    c.setImag(imag);

    return in;
}

Complex operator+(int num, const Complex &c)
{
    return c + num;
}

Complex operator-(int num, const Complex &c)
{
    Complex res{num - c.getReal(), c.getImag()};
    return res;
}

int main()
{
    Complex c1{5, 6}, c2{9, 8};

    // Complex c3 = 10 + c1;
    // c3.print();

    // c1 += c2;
    // c1.print();

    // c1 -= c2;
    // c1.print();

    // std::cout << (c1 == c2) << "\n";

    // std::cout << (float)c1 << "\n";

    // (c1 - c2).print();
    // (c1 - 10).print();

    // (10 - c1).print();

    // c1 = c1--;
    // c1.print();

    // ++c1;
    // std::cout << c1 << "\n";

    // std::cout << "real : " << c1[0] << ", Imag : " << c1[1] << "\n";
    // std::cout << "real : " << c1["real"] << ", Imag : " << c1["imag"] << "\n";
    std::cout << "Enter Complex number (real imag) : ";
    std::cin >> c1;
    std::cout << c1;

    return 0;
}