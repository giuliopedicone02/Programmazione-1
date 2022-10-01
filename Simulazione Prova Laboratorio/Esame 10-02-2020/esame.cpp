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
    char *h;
    short size;

public:
    A(short n) : size(n)
    {
        h = new char[size];

        for (int i = 0; i < size; i++)
        {
            h[i] = rand() % ('z' - 'a' + 1) + 'a';
        }
    }

    virtual double comp(short a) = 0;

    short getSize()
    {
        return size;
    }

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name() << ", h = ";

        for (int c = 0; c < getSize(); c++)
        {
            os << h[c];
        }

        return os;
    }

protected:
    char get(short j)
    {
        return h[j % size];
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
    B(short n, int x) : A(n), p(x){};

    double comp(short a)
    {
        int C = 0, V = 0;

        for (int i = 0; i < getSize(); i++)
        {
            if (get(i) == 'a' || get(i) == 'e' || get(i) == 'i' || get(i) == 'o' || get(i) == 'u' || get(i) == 'A' || get(i) == 'E' || get(i) == 'I' || get(i) == 'O' || get(i) == 'U')
            {
                V++;
            }
            else
            {
                C++;
            }
        }

        return (double)log(V + 1) + log(C + 1);
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", p = " << p << ", comp(3) = " << comp(3) << endl;

        return os;
    }

protected:
    bool test(short k)
    {
        for (int i = 0; i < k; i++)
        {
            if (get(i) == 'a' || get(i) == 'e' || get(i) == 'i' || get(i) == 'o' || get(i) == 'u' || get(i) == 'A' || get(i) == 'E' || get(i) == 'I' || get(i) == 'O' || get(i) == 'U')
            {
                return true;
            }
        }

        return false;
    }
};

class C : public A
{
private:
    char x;

public:
    C(short n, char c) : A(n), x(c){};
    double comp(short r)
    {
        int counter = 0;
        for (int i = r % getSize(); i < getSize(); i++)
        {
            if (get(i) < x)
            {
                counter++;
            }
        }

        return counter * getSize();
    }

    string g(char c)
    {
        string ret = "";

        ret += x;
        ret += c;

        return ret;
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", x = " << x << ", comp(3) = " << comp(3) << endl;

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
            vett[i] = new B(n, rand() % 10 + 1);
        else
            vett[i] = new C(n, (char)(rand() % ((int)'z' - (int)'a' + 1) + (int)'a'));
    }

    // Punto 1

    for (int i = 0; i < DIM; i++)
    {
        cout << i << ") " << *vett[i];
    }

    // Punto 2

    double avg = 0.0;
    int counter = 0;
    string result = "";

    for (int i = 0; i < DIM; i++)
    {
        avg += vett[i]->comp(3);
        counter++;

        if (typeid(C) == typeid(*vett[i]))
        {
            result += ((C *)vett[i])->g('Z');
        }
    }

    cout << "Media: " << (double)avg / counter << endl;
    cout << "Result: " << result;
}