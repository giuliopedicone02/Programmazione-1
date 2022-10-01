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
    int x;

public:
    A(int m) : x(m){};
    double virtual v(int a) = 0;
    virtual ostream &put(ostream &os)
    {
        return os << typeid(*this).name() << ", x = " << x;
    }
};

ostream &operator<<(ostream &s, A &obj)
{
    return obj.put(s);
}

class B : public A
{
private:
    int *ptr;
    int l;

public:
    B(int z, int y) : A(z), l(y)
    {
        ptr = new int[y];

        for (int c = 0; c < y; c++)
        {
            ptr[c] = rand() % 100 + 1;
        }
    }

    double v(int a)
    {
        return l * 1000 / sum(a) + 1;
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", ptr = [ ";

        for (int c = 0; c < l; c++)
        {
            os << ptr[c] << " ";
        }

        os << "]";

        os << ", v(50) = " << v(50) << endl;

        return os;
    }

    int &operator[](int i)
    {
        return ptr[i % l];
    }

protected:
    int sum(int t)
    {
        int res = 0;

        for (int c = 0; c < l; c++)
        {
            if (ptr[c] <= t)
            {
                res += ptr[c];
            }
        }

        return res;
    }
};

template <typename T>
class C : public A
{
private:
    T k;

public:
    C(int n) : A(n)
    {
        if (typeid(T) == typeid(int))
        {
            k = 2 * n;
        }
        else
        {
            k = (double)log(1 + pow(sin(n), 2));
        }
    }

    double v(int r)
    {
        return g(r);
    }

    T g(T w)
    {
        return k * (w + 1);
    }

    ostream &put(ostream &os)
    {
        return A::put(os) << ", k = " << k << ", v(50) = " << v(50) << endl;
    }
};

int main()
{
    srand(111222333);

    A *vett[DIM];

    for (int i = 0; i < DIM; i++)
    {
        int n = 1 + rand() % 10;
        switch (rand() % 3)
        {
        case 0:
            vett[i] = new B(n, rand() % 10 + 1);
            break;
        case 1:
            vett[i] = new C<int>(n);

            break;
        case 2:
            vett[i] = new C<double>(n);
        }
    }

    // punto 1

    for (int c = 0; c < DIM; c++)
    {
        if (c != 34) // Problema individuato all'indice 34
        {
            cout << c << ") " << *vett[c] << endl;
        }
    }

    // punto 2

    double min = vett[0]->v(50);
    double max = vett[0]->v(50);
    double avg = 0.0;
    int counter = 0;

    for (int c = 0; c < DIM; c++)
    {
        if (c != 34) // Problema individuato all'indice 34
        {

            if (vett[c]->v(50) < min)
            {
                min = vett[c]->v(50);
            }
            else if (vett[c]->v(50) > max)
            {
                max = vett[c]->v(50);
            }
            if (typeid(*vett[c]) == typeid(C<double>))
            {
                avg += ((C<double> *)vett[c])->g(5);
                counter++;
            }
        }
    }

    cout << "min: " << min << ", max: " << max << endl;
    cout << "Media: " << (double)avg / counter << endl;

    // punto 3

    B res = B(3, 5);

    cout << res << endl;

    res[0] = 2;

    cout << res;
}