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
    char *base;
    short len;

public:
    A(short m) : len(m)
    {
        base = new char[m];

        for (int c = 0; c < len; c++)
        {
            base[c] = rand() % ('z' - 'a' + 1) + 'a';
        }
    }

    virtual string extract(short x) = 0;

    short getLen()
    {
        return len;
    }

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name() << ", base = [ ";

        for (int c = 0; c < getLen(); c++)
        {
            os << base[c] << " ";
        }
        os << "]";

        return os;
    }

protected:
    char get(short i)
    {
        return base[i % len];
    }
};

ostream &operator<<(ostream &os, A &obj)
{
    return obj.put(os);
}
class B : public A
{
private:
    string str;
    double k;

public:
    B(short m, double p) : A(m)
    {
        for (int c = 0; c < getLen(); c++)
        {
            if (get(c) == 'a' || get(c) == 'e' || get(c) == 'i' || get(c) == 'o' || get(c) == 'u')
            {
                str += get(c);
            }
        }
    }

    double foo(short s)
    {
        return (double)sin(k + s) / log(s + 1);
    }

    string extract(short x)
    {
        string result = "";

        for (int c = 0; c < x; c++)
        {
            result += get(rand());
        }

        return result;
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", str = " << str << ", k = " << k << ", extract(3) = " << extract(3) << endl;

        return os;
    }
};

class C : public A
{
private:
    int y;

public:
    C(short n, int k) : A(n), y(k) {}

    string extract(short x)
    {
        string result = "";
        int counter = 1;
        for (int c = 0; c < getLen(); c++)
        {
            if (get(c) != 'a' || get(c) != 'e' || get(c) != 'i' || get(c) != 'o' || get(c) != 'u')
            {
                result += get(c);
                counter++;
            }

            if (counter > x)
            {
                return result;
            }
        }

        return result;
    }

    short g(short w)
    {
        return sin(w + y);
    }
    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", y = " << y << ", extract(3) = " << extract(3) << endl;

        return os;
    }

    C operator++(int)
    {
        C aux = *this;
        y++;
        return aux;
    }
};

int main()
{
    A *vett[DIM];

    for (int i = 0; i < DIM; i++)
    {
        short n = 10 + rand() % 10;
        switch (rand() % 2)
        {
        case 0:
            vett[i] = new C(n, rand() % 20 + 1);
            break;
        case 1:
            vett[i] = new B(n, rand() / (double)RAND_MAX);
            break;
        }
    }

    // Punto 1

    for (int c = 0; c < DIM; c++)
    {
        cout << c << ") " << *vett[c];
    }

    // punto 2

    int counterB = 0, counterC = 0;
    double avgB = 0.0, avgC = 0.0;

    for (int c = 0; c < DIM; c++)
    {
        if (typeid(*vett[c]) == typeid(B))
        {
            avgB += ((B *)vett[c])->foo(5);
            counterB++;
        }

        if (typeid(*vett[c]) == typeid(C))
        {
            avgC += ((C *)vett[c])->g(5);
            counterC++;
        }
    }

    cout << endl
         << endl
         << "Media foo(5) = " << (double)avgB / counterB;
    cout << endl
         << "Media g(5) = " << (double)avgC / counterC << endl;

    // Punto 3 - non funzionante

    C res = C(4, 3);
    cout << res;
    res++;
    cout << res;
}