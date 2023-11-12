#include <iostream>

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

    int getReal(void)
    {
        return real;
    }

    int setImag(int num)
    {
        imag = num;
        return 0;
    }

    int getImag(void)
    {
        return imag;
    }

    Complex add(Complex &c)
    {
        Complex res{};
        res.setImag(getImag() + c.getImag());
        res.setReal(getReal() + c.getReal());

        return res;
    }

    Complex sub(Complex &c);

    void print(void)
    {
        cout << getReal();
        if (getImag() > 0)
        {
            cout << "+" << getImag() << "j"
                 << "\n";
        }
        else if (getImag() < 0)
        {
            cout << getImag() << "j"
                 << "\n";
        }
        else
        {
            cout << "\n";
        }
    }

    friend Complex subFriend(Complex &c1, Complex &c2);

private:
    int imag;
    int real;
};

Complex Complex::sub(Complex &c)
{
    Complex res{};
    res.setImag(getImag() - c.getImag());
    res.setReal(getReal() - c.getReal());

    return res;
}

Complex addStandalone(Complex &c1, Complex &c2)
{
    Complex res{};
    res.setImag(c1.getImag() + c2.getImag());
    res.setReal(c1.getReal() + c2.getReal());

    return res;
}

Complex subFriend(Complex &c1, Complex &c2)
{
    Complex res{};
    res.setImag(c1.imag - c2.imag);
    res.setReal(c1.real - c2.real);

    return res;
}

int main()
{
    Complex c1{5, 6}, c2{9, 8};

    c1.sub(c2).print();
    // addStandalone(c1, c2).print();
    return 0;
}