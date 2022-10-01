#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
using namespace std;

#define DIM 50

class A
{
private:
    char *ptr;
    short len;

public:
    A(short m, char c) : len(m)
    {
        ptr = new char[m];
        for (int i = 0; i < len; i++)
        {
            ptr[i] = rand() % (c - 'a' + 1) + 'a';
        }
    }

    string virtual elab(short a, char c) = 0;

    short getLen()
    {
        return len;
    }

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name() << ", ptr = [ ";

        for (int i = 0; i < getLen(); i++)
        {
            os << ptr[i] << " ";
        }

        os << "]";

        return os;
    }

    char &operator[](char c)
    {
        return ptr[c % len];
    }

protected:
    char get(short i)
    {
        return ptr[i % len];
    }
};

ostream &operator<<(ostream &os, A &obj)
{
    return obj.put(os);
}
class B : public A
{
private:
    double x;

public:
    B(short m, double y, char c) : A(m, c), x(y) {}

    double foo(short s)
    {
        return (double)sin(x + s) / log(x + s);
    }

    string elab(short a, char c)
    {
        string result = "";
        for (int i = 0; i < getLen(); i++)
        {
            if (abs(get(i) - c) <= a)
            {
                result += get(i);
            }
        }

        return result;
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", x = " << x << ", elab(5,z) = " << elab(5, 'z') << endl;

        return os;
    }
};

template <typename T>
class C : public A
{
private:
    T y;

public:
    C(short n, double k, char c) : A(n, c)
    {
        if (typeid(T) == typeid(short))
        {
            y = round(100 * k);
        }
        else
        {
            y = k;
        }
    }

    string elab(short a, char c)
    {
        string result = "";

        if (getLen() >= a)
        {
            for (int i = 0; i < a; i++)
            {
                result += c;
            }

            return result;
        }
        else
        {

            for (int i = 0; i < getLen(); i++)
            {
                result += get(i);
            }

            return result;
        }
    }

    double g(short w)
    {
        return sin(w + y);
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", y = " << y << ", elab(5,z) = " << elab(5, 'z') << endl;

        return os;
    }
};

int main()
{
    srand(111222333);

    A *vett[DIM];

    for (int i = 0; i < DIM; i++)
    {
        short n = 1 + rand() % 10;
        switch (rand() % 3)
        {
        case 0:
            vett[i] = new B(n, (double)rand() / RAND_MAX, rand() % ('z' - 'a' + 1) + 'a');
            break;
        case 1:
            vett[i] = new C<double>(n, (double)rand() / RAND_MAX, rand() % ('z' - 'a' + 1) + 'a');
            break;
        case 2:
            vett[i] = new C<short>(n, (double)rand() / RAND_MAX, rand() % ('z' - 'a' + 1) + 'a');
        }
    }

    // Punto 1

    for (int c = 0; c < DIM; c++)
    {
        cout << c << ") " << *vett[c];
    }

    // Punto 2

    int counterB = 0;
    int counterC = 0;
    double avgB = 0.0;
    double avgC = 0.0;
    for (int c = 0; c < DIM; c++)
    {
        if (typeid(*vett[c]) == typeid(B))
        {
            avgB += ((B *)vett[c])->foo(5);
            counterB++;
        }

        if (typeid(*vett[c]) == typeid(C<short>))
        {
            avgC += ((C<short> *)vett[c])->g(5);
            counterC++;
        }
    }

    cout << endl
         << endl;
    cout << "Media foo(5) = " << (double)avgB / counterB << endl;
    cout << "Media g(5) = " << (double)avgC / counterC << endl;

    // Punto 3

    cout << *vett[5] << endl;

    (*vett[5])[0] = 'R';

    cout << *vett[5] << endl;
}