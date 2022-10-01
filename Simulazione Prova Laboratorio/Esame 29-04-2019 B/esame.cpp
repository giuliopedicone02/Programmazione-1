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
    int *vec;
    short len;

public:
    A(short m, int a, int b) : len(m)
    {
        vec = new int[m];

        for (int c = 0; c < m; c++)
        {
            vec[c] = rand() % (b - a + 1) + a;
        }
    }

    virtual double foo(short a) = 0;

    short getLen()
    {
        return len;
    }

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name() << ", vec = [ "; //...

        for (int c = 0; c < len; c++)
        {
            os << vec[c] << " ";
        }

        os << "]";
        return os;
    }

    int &operator[](int i)
    {
        return vec[i % len];
    }

protected:
    int get(short i)
    {
        return vec[i % len];
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
    B(short m, int x, int y) : A(m, x, y) { p = get(rand()); }

    double foo(short a)
    {
        return prod(a) / p;
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", p = " << p << ", foo(3) = " << foo(3) << endl;

        return os;
    }

protected:
    int prod(short s)
    {
        int result = 0;

        for (int i = s % getLen(); i < getLen(); i++)
        {
            result *= get(i);
        }

        return result;
    }
};

template <typename T>
class C : public A
{
private:
    T x;

public:
    C(short n, int a, int b) : A(n, a, b)
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
            vett[i] = new B(n, rand() % 5 + 1, rand() % 10 + 5);
            break;
        case 1:
            vett[i] = new C<double>(n, rand() % 5 + 1, rand() % 10 + 5);
            break;
        case 2:
            vett[i] = new C<short>(n, rand() % 5 + 1, rand() % 10 + 5);
        }
    }

    // Punto 1

    for (int c = 0; c < DIM; c++)
    {
        cout << c << ") " << *vett[c];
    }

    // Punto 2
    int max = vett[0]->foo(3), counter = 0;
    double avg = 0.0;
    for (int c = 0; c < DIM; c++)
    {
        if (vett[c]->foo(3) > max)
        {
            max = vett[c]->foo(3);
        }

        if (typeid(*vett[c]) == typeid(C<short>))
        {
            avg += ((C<short> *)vett[c])->g(5);
            counter++;
        }
    }

    cout << "Max: " << max << endl;
    cout << "Media: " << (double)avg / counter << endl;

    cout << *vett[0] << endl;

    (*vett[0])[0] = 10;

    cout << *vett[0];
}