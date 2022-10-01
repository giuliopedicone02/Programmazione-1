#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <typeinfo>
using namespace std;

#define DIM 50

class A
{
private:
    short *arr;
    short len;

public:
    A(short m) : len(m)
    {
        arr = new short[m];

        for (int c = 0; c < m; c++)
        {
            arr[c] = rand() % 10 + 1;
        }
    }

    virtual double f(short a) = 0;

    short getLen()
    {
        return len;
    }

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name() << ", w = [ ";

        for (int c = 0; c < len; c++)
        {
            os << arr[c] << " ";
        }

        os << "]";

        return os;
    }

    short &operator[](short i)
    {
        return arr[i % len];
    }

protected:
    short get(short i)
    {
        return arr[i % len];
    }
};

ostream &operator<<(ostream &s, A &obj)
{
    return obj.put(s);
}

template <typename T>
class B : public A
{
private:
    T x;

public:
    B(short m, char c) : A(m)
    {
        if (typeid(T) == typeid(char))
        {
            x = c;
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                x += c;
            }
        }
    }

    double foo(short s)
    {
        return log(s) + sin(f(s));
    }

    double f(short a)
    {
        int counter = 0;
        double avg = 0.0;

        for (int c = a % getLen(); c < getLen(); c++)
        {
            avg += get(c);
            counter++;
        }

        return (double)avg / counter;
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", x = " << x << ", foo(3) = " << foo(3) << endl;

        return os;
    }
};

class C : public A
{
private:
    int y;

public:
    C(short n, int k) : A(n), y(k) {}
    double f(short a)
    {
        short r = get(rand());

        return (double)(a + y) / r;
    }

    short g(short w)
    {
        return sin(w + y);
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", y = " << y << ", f(3) = " << f(3) << ", g(3) = " << g(3) << endl;

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
            vett[i] = new C(n, rand() % 10 + 1);
            break;
        case 1:
            vett[i] = new B<string>(n, rand() % ('z' - 'a' + 1) + 'a');
            break;
        case 2:
            vett[i] = new B<char>(n, rand() % ('z' - 'a' + 1) + 'a');
        }
    }

    // punto 1

    for (int c = 0; c < DIM; c++)
    {
        cout << c << ") " << *vett[c];
    }

    // Punto 2
    double max = ((B<char> *)vett[0])->foo(3), avg = 0.0;
    int counter = 0;
    for (int c = 0; c < DIM; c++)
    {
        if (typeid(*vett[c]) == typeid(B<char>))
        {
            max = ((B<char> *)vett[c])->foo(3);
        }
        if (typeid(*vett[c]) == typeid(B<string>))
        {
            max = ((B<string> *)vett[c])->foo(3);
        }
        else if (typeid(*vett[c]) == typeid(C)) // C<double> ?!
        {
            avg += ((C *)vett[c])->g(5);
            counter++;
        }
    }

    cout << "Max: " << max << endl;
    cout << "Media: " << (double)avg / counter << endl;

    // Punto 3

    cout << *vett[0] << endl;
    (*vett[0])[0] = 10;
    cout << *vett[0];
}