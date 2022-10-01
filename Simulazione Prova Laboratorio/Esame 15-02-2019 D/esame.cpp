#include <iostream>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
using namespace std;

#define DIM 50

class A
{
private:
    int *ptr;
    short len;

public:
    A(short m, short k) : len(m)
    {
        ptr = new int[len];

        for (int c = 0; c < len; c++)
        {
            ptr[c] = rand() % (k - 1 + 1) + 1;
        }
    }
    virtual double const f() = 0;

    int get(short i)
    {
        return ptr[i % len];
    }

    short getLen()
    {
        return len;
    }

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name() << ", ptr = [ ";

        for (int c = 0; c < len; c++)
        {
            os << ptr[c] << " ";
        }

        os << "]";

        return os;
    }

    int &operator[](int i)
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
    double p;

public:
    B(short m, short k, double y) : A(m, k), p(y) {}

    double const f()
    {
        double result = 0.0;
        for (int c = 0; c < getLen(); c++)
        {
            if (get(c) % 2 == 0)
            {
                result += get(c);
            }
        }

        return (double)result / p;
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", p = " << p << ", f() = " << f();

        return os;
    }
};

class C : public A
{
private:
    char x;

public:
    C(short n, short k, char c) : A(n, k), x(c){};
    double const f()
    {
        int counter = 0;
        double avg = 0.0;
        for (int c = 0; c < getLen(); c++)
        {
            if (get(c) % 2 != 0)
            {
                counter++;
                avg += get(c);
            }
        }

        if (counter == 0)
        {
            return 0.0;
        }
        else
        {
            return (double)avg / counter;
        }
    }

    string const g(char c)
    {
        string res = "";
        res += x;
        res += c;
        return res;
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", x = " << x << ", f() = " << f();
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
        short m = 1 + rand() % 8;
        if (rand() % 2 == 0)
            vett[i] = new B(n, m, rand() / (double)RAND_MAX + 0.05);
        else
            vett[i] = new C(n, m, (char)(rand() % ('z' - 'a' + 1) + 'a'));
    }

    // Punto 1

    for (int c = 0; c < DIM; c++)
    {
        cout << c << ") " << *vett[c] << endl;
    }

    // Punto 2

    double avg = 0.0;
    string res = "";
    for (int c = 0; c < DIM; c++)
    {
        avg += vett[c]->f();

        if (typeid(*vett[c]) == typeid(C))
        {
            res += ((C *)vett[c])->g('h');
        }
    }

    cout << "Media: " << avg / DIM << endl;
    cout << "Stringa: " << res << endl
         << endl;

    // Punto 3
    cout << *vett[5] << endl;
    (*vett[5])[0] = -1;
    cout << *vett[5] << endl;
}