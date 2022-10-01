#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <climits>
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

        for (int i = 0; i < n; i++)
        {
            vec[i] = rand() % (max - min + 1) + min;
        }
    }

    int virtual count() = 0;

    int *get(int i)
    {
        if (!vec[i])
        {
            return nullptr;
        }
        else
        {
            return &vec[i];
        }
    }

    int numel() { return num; }

    float mean()
    {
        float avg = 0.0;
        int count = 0;

        for (int i = 0; i < num; i++)
        {
            if (vec[i])
            {
                avg += vec[i];
                count++;
            }
        }

        return (float)avg / count;
    }

    virtual ostream &put(ostream &os)
    {

        os << typeid(*this).name(); //...

        os << ", num = " << num << ", vec = [";

        for (int i = 0; i < num; i++)
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
        for (int i = 0; i < numel(); i++)
        {
            if (vec[i])
            {
                counter++;
            }
        }

        return counter;
    }

    ostream &put(ostream &os)
    {
        AbstractRandomVec::put(os);

        //...

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
        for (int i = 0; i < n; i++)
        {
            int gen = rand() % (max - min + 1) + min;

            if (gen % mul == 0)
            {
                vec[i] = gen;
            }
        }

        midpoint = ((double)(min) + max) / 2;
    }

    int count()
    {
        int counter = 0;

        for (int i = 0; i < numel(); i++)
        {
            if (vec[i] && vec[i] % 2 == 0)
            {
                counter++;
            }
        }

        return counter;
    }

    int countEven()
    {
        int counter = 0;

        for (int i = 0; i < numel(); i++)
        {
            if (vec[i] > midpoint)
            {
                counter++;
            }
        }

        return counter;
    }

    ostream &put(ostream &os)
    {
        AbstractRandomVec::put(os);

        os << ", midpoint = " << midpoint;

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

    for (int i = 0; i < DIM; i++)
    {
        cout << "Class= " << i + 1 << ") " << *vett[i] << endl;
    }

    // Punto 2

    int max = INT_MIN;

    for (int i = 0; i < DIM; i++)
    {
        if (vett[i]->count() > max)
        {
            max = vett[i]->count();
        }
    }

    cout << "max count() = " << max << endl;

    // Punto 3

    float mean = 0;
    int count = 0;
    for (int i = 0; i < DIM; i++)
    {
        if (typeid(*vett[i]) == typeid(MultiVec))
        {
            mean += ((MultiVec *)vett[i])->countEven();
            count++;
        }
    }

    cout << "mean countEven(): " << mean / count << endl;
}