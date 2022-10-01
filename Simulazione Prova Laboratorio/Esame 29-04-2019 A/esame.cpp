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
    double *ptr;
    short len;

public:
    A(short m) : len(m)
    {
        ptr = new double[m];
        for (int c = 0; c < m; c++)
        {
            ptr[c] = rand() % 2;
        }
    }

    virtual double f(short i) = 0;

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name() << ",ptr = [ "; //...
        for (int c = 0; c < len; c++)
        {
            os << ptr[c] << " ";
        }

        os << "]";

        return os;
    }

    double &operator[](int i)
    {
        return ptr[i % len];
    }

    short getLen()
    {
        return len;
    }

protected:
    double get(short i)
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
    int p;

public:
    B(short m, int y) : A(m), p(y) {}
    double f(short i)
    {
        double result = 0.0;
        for (int c = 0; c < i; c++)
        {
            result += get(c);
        }

        return (double)result / p;
    }
    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", p = " << p << ", f(3) = " << f(3) << endl;

        return os;
    }
};

class C : public A
{
private:
    char x;

public:
    C(short n, char c) : A(n), x(c) {}

    double f(short i)
    {
        double sum = 0.0;
        for (int c = 0; c < getLen(); c++)
        {
            sum += get(c);
        }

        return (double)get(i) / sum;
    }

    string g(char c)
    {
        string result = "";
        result += x;
        result += c;
        return result;
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", x = " << x << ", f(3) = " << f(3) << endl;

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
        if (rand() % 2 == 0)
            vett[i] = new B(n, rand() % 10);
        else
            vett[i] = new C(n, (char)(rand() % ('z' - 'a' + 1) + 'a'));
    }

    // Punto 1

    for (int c = 0; c < DIM; c++)
    {
        cout << c << ") " << *vett[c];
    }

    // Punto 2

    int counter = 0;
    double avg = 0.0;
    string result = "";

    for (int c = 0; c < DIM; c++)
    {
        avg += vett[c]->f(3);
        counter++;

        if (typeid(*vett[c]) == typeid(C))
        {
            result += ((C *)vett[c])->g('h');
        }
    }

    cout << endl
         << "Media: " << (double)avg / counter;

    cout << endl
         << "Stringa: " << result << endl;

    // Punto 3

    cout << *vett[0] << endl;

    (*vett[0])[0] = 3.0;

    cout << *vett[0];
}