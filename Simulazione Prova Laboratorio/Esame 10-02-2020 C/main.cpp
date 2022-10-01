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
    int *v;
    short len;

public:
    A(short k, short n) : len(k)
    {
        v = new int[k];

        for (int i = 0; i < k; i++)
        {
            v[i] = rand() % n;
        }
    }

    double virtual doit(short a) = 0;

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name();

        os << ", v=[ ";

        for (int i = 0; i < len; i++)
        {
            os << v[i] << " ";
        }

        os << "]";

        return os;
    }

protected:
    double mat(short i)
    {
        int S = 0;
        for (int j = 0; j < i; j++)
        {
            S += v[i];
        }

        return sin(S);
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
    B(short k, short n, int p) : A(k, n), p(p) {}

    double doit(short a)
    {

        double n1 = A::mat(a);
        double n2 = (double)log(p * rand() % 100);

        return n1 * n2;
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", p=" << p << ", doit(3)=" << doit(3);

        return os;
    }

    B &operator++()
    {
        p++;
        return *this;
    }

protected:
    bool test(short i)
    {
        if (mat(i) > 0)
        {
            return true;
        }

        return false;
    }
};

class C : public A
{
private:
    double x;

public:
    C(short k, short n, double c) : A(k, n), x(c) {}

    double doit(short r)
    {
        double n1 = (double)mat(r) + 1;
        return x * n1;
    }

    int g(int c)
    {
        double r = ((double)rand()) / RAND_MAX;

        return round(x + c * r);
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", x=" << x << ", doit(3)=" << doit(3);

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
        short k = 1 + rand() % 10;
        if (rand() % 2 == 0)
        {
            vett[i] = new B(k, n, (int)rand() % 10 + 1);
        }
        else
        {
            vett[i] = new C(k, n, (double)(rand() % 10 + 1));
        }
    }

    // Punto 1

    for (int i = 0; i < DIM; i++)
    {
        cout << i << ") " << *vett[i] << endl;
    }

    // Punto 2

    double max = INT_MIN;
    double avg = 0.0;
    int cont = 0;

    for (int i = 0; i < DIM; i++)
    {
        if (vett[i]->doit(3) > max)
        {
            max = vett[i]->doit(3);
        }

        if (typeid(*vett[i]) == typeid(C))
        {
            avg += ((C *)vett[i])->g(5);
            cont++;
        }
    }

    cout << "max doit(3) = " << max << endl;
    cout << "avg g(5) = " << (double)avg / cont << endl
         << endl;

    // Punto 3

    cout << *vett[0] << endl;

    ++(*(B *)vett[0]);

    ++(*(dynamic_cast<B *>(vett[0])));

    cout << *vett[0] << endl;
}