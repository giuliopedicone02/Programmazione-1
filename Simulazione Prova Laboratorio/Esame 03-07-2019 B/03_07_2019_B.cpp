#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#define DIM 50
using namespace std;

class A
{
private:
    char *s;
    short len;

public:
    A(short m) : len(m)
    {
        s = new char[m];
        for (int i = 0; i < m; i++)
        {
            s[i] = rand() % ('z' - 'a' + 1) + 'a';
        }
    };

    double virtual elab(short a) = 0;

    short getLen()
    {
        return len;
    }

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name();
        os << ", s= " << s << ", ";

        return os;
    }

protected:
    char get(short i)
    {
        return s[i % len];
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

    double elab(short a)
    {
        short V = 0, C = 0;
        for (int i = 0; i < getLen(); i++)
        {
            if (get(i) == 'A' && get(i) == 'a' && get(i) == 'E' && get(i) == 'e' && get(i) == 'I' && get(i) == 'i' && get(i) == 'O' && get(i) == 'o' && get(i) == 'U' && get(i) == 'u')
            {
                V++;
            }
            else
            {
                C++;
            }
        }
        return (double)V / (C + 1);
    }
    ostream &put(ostream &os)
    {
        A::put(os);

        os << "p=" << p << ", elab(3)=" << elab(3);

        return os;
    }

    // friend B operator++(B &, int);

    B operator++(int)
    {
        B aux = *this;
        p++;
        return aux;
    }

protected:
    bool test()
    {
        for (int i = 0; i < 4; i++)
        {
            if (get(i) == 'A' && get(i) == 'a' && get(i) == 'E' && get(i) == 'e' && get(i) == 'I' && get(i) == 'i' && get(i) == 'O' && get(i) == 'o' && get(i) == 'U' && get(i) == 'u')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

/*B operator++(B &obj, int)
{
    B aux = obj;
    obj.p++;
    return aux;
}*/

class C : public A
{
private:
    char x;

public:
    C(short n, char c) : A(n), x(c){};

    double elab(short r)
    {
        short cont = 0;
        for (int i = r; i < getLen(); i++)
        {
            if (get(i) >= x)
            {
                cont++;
            }
        }
        return (double)cont / getLen();
    }

    string g(char c)
    {
        string t = "";
        t += x;
        t += c;
        return t;
    }

    ostream &put(ostream &os)
    {
        A::put(os);

        os << "x=" << x << ", elab(3)=" << elab(3);

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

    // PUNTO 1
    for (int i = 0; i < DIM; i++)
    {
        cout << i << ")" << *vett[i] << endl;
    }
    cout << endl;
    // PUNTO 2
    double avg = 0.0;
    string s = "";
    for (int i = 0; i < DIM; i++)
    {
        avg += vett[i]->elab(3);
        if (typeid(*vett[i]) == typeid(C))
        {
            // s += ((C *)vett[i])->g('h');
            s += (dynamic_cast<C *>(vett[i])->g('h'));
        }
    }
    cout << "Avg= " << avg / DIM << ", concat=" << s << endl;

    // PUNTO 3

    cout << *vett[0] << endl;
    // (*(B *)vett[0])++;
    (*dynamic_cast<B *>(vett[0]))++;
    cout << *vett[0] << endl
         << endl;
}
