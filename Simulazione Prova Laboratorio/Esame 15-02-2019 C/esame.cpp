#include <iostream>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
using namespace std;

#define DIM 50

class A
{
private:
    char *str;
    short len;

public:
    A(short m) : len(m)
    {
        str = new char[len];

        for (int c = 0; c < m; c++)
        {
            str[c] = rand() % ('z' - 'a' + 1) + 'a';
        }
    }

    double virtual elab(short a) = 0;

    short getLen()
    {
        return len;
    }

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name() << ", w = ";
        for (int c = 0; c < len; c++)
        {
            os << str[c];
        }
        return os;
    }

protected:
    char get(short i)
    {
        return str[i % len];
    }
};

ostream &operator<<(ostream &s, A &obj)
{
    return obj.put(s);
}

class B : public A
{
private:
    int p;

public:
    B(short m, int x) : A(m), p(x){};
    double elab(short a)
    {
        short *result = new short[getLen()];
        result = map();
        int sum = 0;
        double div = (double)p / a;
        for (int c = 0; c < getLen(); c++)
        {
            sum += result[c];
        }

        return (double)sum / div;
    }

    ostream &put(ostream &os)
    {
        A::put(os);
        os << ", p = " << p << ", elab(3) = " << elab(3);
        return os;
    }

    friend B operator++(B &, int);

protected:
    short *map()
    {
        short *res = new short[getLen()];

        for (int c = 0; c < getLen(); c++)
        {
            if (get(c) == 'a' || get(c) == 'e' || get(c) == 'i' || get(c) == 'o' || get(c) == 'u' || get(c) == 'A' || get(c) == 'E' || get(c) == 'I' || get(c) == 'O' || get(c) == 'U')
            {
                res[c] = 0;
            }
            else
            {
                res[c] = 1;
            }
        }

        return res;
    }
};

B operator++(B &obj, int)
{
    B aux = obj;
    obj.p++;
    return aux;
}

class C : public A
{
private:
    char x;

public:
    C(short m, char c) : A(m), x(c){};
    double elab(short r)
    {
        int counter;
        for (int c = r % getLen(); c < getLen(); c++)
        {
            if (get(c) >= x)
            {
                counter++;
            }
        }

        return (double)counter / getLen();
    }
    string g(char c)
    {
        string s = "";
        s += x;
        s += c;
        return s;
    }
    ostream &put(ostream &os)
    {
        A::put(os);
        os << ", x = " << x << ", elab(3)= " << elab(3);
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
        {
            vett[i] = new B(n, rand() % 10 + 1);
        }

        else
        {
            vett[i] = new C(n, (char)(rand() % ('z' - 'a' + 1) + 'a'));
        }
    }

    // Punto 1
    for (int c = 0; c < DIM; c++)
    {
        cout << c << ") " << *vett[c] << endl;
    }

    // Punto 2
    double avg = 0.0;
    string str = "";
    for (int c = 0; c < DIM; c++)
    {
        avg += vett[c]->elab(3);

        if (typeid(*vett[c]) == typeid(C))
        {
            str += ((C *)vett[c])->g('h');
        }
    }

    cout << "Media valori: " << (double)avg / DIM << endl;
    cout << "Stringa concatenazione: " << str << endl;

    // Punto 3

    cout << *vett[0] << endl;
    (*(B *)vett[0])++;
    cout << *vett[0]++;

    /*B var = B(3, 5);

    cout << var << endl;
    var++;
    cout << var << endl;*/
}
