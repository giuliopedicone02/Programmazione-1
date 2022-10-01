#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
using namespace std;

#define DIM 10

class AbstractRandomVec
{
protected:
    int *vec;
    int num;

public:
    AbstractRandomVec(int n, int min, int max) : num(n)
    {
        vec = new int[n];
        for (int c = 0; c < n; c++)
        {
            vec[c] = rand() % (max - min + 1) + min;
        }
    }

    virtual int count() = 0;

    int *get(int i)
    {
        if (vec[i])
        {
            return vec;
        }
        else
        {
            return nullptr;
        }
    }

    int numel()
    {
        return num;
    }

    float mean()
    {
        return 0.0;
    }

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name() << ", num = " << num << ", vec = [ ";

        for (int i = 0; i < numel(); i++)
        {
            os << vec[i] << " ";
        }

        os << "]";

        return os;
    }
};

ostream &operator<<(ostream &os, AbstractRandomVec &obj)
{
    return obj.put(os);
}
class TernaryVec : public AbstractRandomVec
{
public:
    TernaryVec(int n) : AbstractRandomVec(n, 0, 2) {}

    int count()
    {
        int counter = 0;
        for (int c = 0; c < numel(); c++)
        {
            if (vec[c] > 0)
            {
                counter++;
            }
        }

        return counter;
    }

    ostream &put(ostream &os)
    {
        AbstractRandomVec::put(os);

        os << endl;

        return os;
    }
};

class MultiVec : public AbstractRandomVec
{
private:
    double midpoint;

public:
    MultiVec(int n, int min, int max, int mul) : AbstractRandomVec(n, min, max)
    {
        int gen = 0;
        for (int c = 0; c < numel(); c++)
        {
            gen = rand() % (max - min + 1) + min;
            if (gen % mul == 0)
            {
                vec[c] = gen;
            }
        }
        midpoint = (double)min + max / 2;
    }

    int count()
    {
        int counter = 0;
        for (int c = 0; c < numel(); c++)
        {
            if (vec[c] > midpoint)
            {
                counter++;
            }
        }

        return counter;
    }

    int countEven()
    {
        int counter = 0;
        for (int c = 0; c < numel(); c++)
        {
            if (vec[c] % 2 == 0)
            {
                counter++;
            }
        }

        return counter;
    }

    ostream &put(ostream &os)
    {
        AbstractRandomVec::put(os);

        os << ", midpoint = " << midpoint << endl;

        return os;
    }
};

int main()
{
    srand(424242);

    AbstractRandomVec *vett[DIM];

    for (int i = 0; i < DIM; i++)
    {
        int n = 5 + rand() % 5;
        int m = 5 + rand() % 5;
        int min = rand() % 10 + 5;
        int max = min + rand() % 20;

        switch (rand() % 2)
        {
        case 0:
            vett[i] = new TernaryVec(n);
            break;
        case 1:
            vett[i] = new MultiVec(n, min, max, m);
        }
    }

    // Punto 1

    for (int c = 0; c < DIM; c++)
    {
        cout << c << ") " << *vett[c];
    }

    // Punto 2

    int max = vett[0]->count();
    for (int c = 0; c < DIM; c++)
    {
        if (vett[c]->count() > max)
        {
            max = vett[c]->count();
        }
    }
    cout << endl;
    cout << "Max: " << max << endl;

    // Punto 3

    int counter = 0;
    double avg = 0.0;
    for (int c = 0; c < DIM; c++)
    {
        if (typeid(*vett[c]) == typeid(MultiVec))
        {
            avg += ((MultiVec *)vett[c])->countEven();
            counter++;
        }
    }

    cout << "Media: " << (double)avg / counter;
}