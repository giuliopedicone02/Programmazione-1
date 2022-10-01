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
    char *str;
    short len;

public:
    A(short m, string source) : len(m)
    {
        str = new char[len];

        for (int c = 0; c < len; c++)
        {
            str[c] = source[rand() % source.length()];
        }
    }

    virtual char func(short i) = 0;

    short getLen()
    {
        return len;
    }

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name() << ", str = [ "; //...

        for (int c = 0; c < getLen(); c++)
        {
            os << get(c) << " ";
        }

        os << "]";

        return os;
    }

    string operator()(int i1, int i2)
    {
        string stringa = "";
        for (int c = i1; c <= i2; c++)
        {
            stringa += str[c];
        }

        return stringa;
    }

protected:
    char get(short i)
    {
        return str[i % len];
    }
};

ostream &operator<<(ostream &os, A &obj)
{
    return obj.put(os);
}
class B : public A
{
private:
    short p;

public:
    B(short m, string source) : A(m, source)
    {
        int counter = 1;
        for (int c = 0; c < getLen(); c++)
        {
            if (get(c) == 'a' || get(c) == 'e' || get(c) == 'i' || get(c) == 'o' || get(c) == 'u')
            {
                counter++;
            }
        }

        p = counter;
    }
    char func(short i)
    {
        for (int c = i; c < getLen(); c++)
        {
            if (get(c) != 'a' || get(c) != 'e' || get(c) != 'i' || get(c) != 'o' || get(c) != 'u')
            {
                return get(c);
            }
        }

        return 'X';
    }
    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", p = " << p << ", func(3) = " << func(3) << endl;

        return os;
    }
};

class C : public A
{
private:
    char x;

public:
    C(short n, string source, char y) : A(n, source), x(y) {}

    char func(short i)
    {
        for (int c = i; c < getLen(); c++)
        {
            if (get(c) > x)
            {
                return get(c);
            }
        }

        return x;
    }
    string g(char c)
    {
        string str = "";

        for (int c = 0; c < getLen(); c++)
        {
            str += get(c);
        }

        return x + str + c;
    }
    ostream &put(ostream &os)
    {
        A::put(os);

        os << ", x = " << x << ", func(3) = " << func(3) << endl;

        return os;
    }
};

int main()
{
    srand(111222333);
    A *vett[DIM];
    string S = "supercalifragilistichespiralidoso";
    for (int i = 0; i < DIM; i++)
    {
        short n = 3 + rand() % 10;
        if (rand() % 2 == 0)
            vett[i] = new B(n, S);
        else
            vett[i] = new C(n, S, (char)(rand() % ('z' - 'a' + 1) + 'a'));
    }

    // Punto 1

    for (int c = 0; c < DIM; c++)
    {
        cout << c << ") " << *vett[c] << endl;
    }

    // Punto 2
    string result = "";
    for (int c = 0; c < DIM; c++)
    {
        if (typeid(*vett[c]) == typeid(C))
        {
            result += ((C *)vett[c])->g('h');
        }
    }

    cout << "Stringa: " << result << endl;

    cout << "Funzione (): " << (*vett[0])(0, 2);
}