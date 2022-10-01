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
    double *w;
    short len;

public:
    A(short m) : len(m)
    {
        w = new double[m];
        for (int c = 0; c < m; c++)
        {
            w[c] = (double)rand() / RAND_MAX;
        }
    }

    double virtual foo(short a) = 0;

    short getLen() { return len; }

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name() << ", w = [ ";

        for (int c = 0; c < len; c++)
        {
            os << w[c] << " ";
        }

        os << "]";

        return os;
    }

    double &operator[](int i)
    {
        return w[i % len];
    }

protected:
    double get(short i)
    {
        return w[i % len];
    }
};

ostream &operator<<(ostream &os, A &obj)
{
    return obj.put(os);
}

class B : public A
{
private:
    int p;

public:
    B(short m, int x) : A(m), p(x){};

    double foo(short a)
    {
        return sum(a) / p;
    }
    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", p = " << p << ", foo(3) = " << foo(3) << endl;

        return os;
    }

protected:
    double sum(short s)
    {
        double somma = 0;
        for (int c = s % getLen(); c < getLen(); c++)
        {
            somma += get(c);
        }

        return somma;
    }
};

template <typename T>
class C : public A
{
private:
    T x;

public:
    C(short n) : A(n)
    {
        if (typeid(T) == typeid(short))
        {
            x = n;
        }
        else
        {
            x = log(1 + pow(sin(n), 2));
        }
    }
    double foo(short r)
    {
        return g(r);
    }
    T g(T k)
    {
        return 2 * x * (k + 1);
    }
    ostream &put(ostream &os)
    {
        A::put(os);
        os << ", x = " << x << ", foo(3) = " << foo(3) << endl;
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
            vett[i] = new B(n, rand() % 10 + 1);
            break;
        case 1:
            vett[i] = new C<double>(n);
            break;
        case 2:
            vett[i] = new C<short>(n);
        }
    }

    // Punto 1

    for (int c = 0; c < DIM; c++)
    {
        cout << c << ") " << *vett[c];
    }

    // Punto 2

    double max = vett[0]->foo(3);
    double avg = 0.0;
    int counter = 0;

    for (int c = 0; c < DIM; c++)
    {
        if (vett[c]->foo(3) > max)
        {
            max = vett[c]->foo(3);
        }

        if (typeid(*vett[c]) == typeid(C<double>))
        {
            avg += ((C<double> *)vett[c])->g(5);
            counter++;
        }
    }

    cout << "Max: " << max << endl;
    cout << "Media: " << (double)avg / counter << endl;
    ;

    // Punto 3

    cout << *vett[0] << endl;

    (*vett[0])[0] = 4;

    cout << *vett[0];
}