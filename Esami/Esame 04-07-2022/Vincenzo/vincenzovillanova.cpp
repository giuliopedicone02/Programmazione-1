#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <climits>
using namespace std;

#define DIM 7

template <typename T>
class AbstractRandomGenerator
{
protected:
    int num_values;
    int tossed;
    T accumulated_value;
    T value;
    T *values;

public:
    AbstractRandomGenerator(T value, int num_values, T *input_values) : value(value), num_values(num_values)
    {
        values = new T[num_values];
        input_values = new T[num_values];

        for (int i = 0; i < num_values; i++)
        {
            values[i] = input_values[i];
        }
    }

    virtual T toss()
    {
        value = values[rand() % num_values];
        tossed++;
        accumulated_value += value;
        return value;
    }

    virtual void nudge() = 0;

    T getValue()
    {
        return value;
    }

    int getTossed()
    {
        return tossed;
    }

    virtual ostream &put(ostream &os)
    {
        os << "Class= " << typeid(*this).name(); //...

        os << ", values = [ ";

        for (int i = 0; i < num_values; i++)
        {
            os << values[i] << " ";
        }

        os << "]";

        os << ", value = " << value << ", accumulated_value = " << accumulated_value << ", tossed = " << tossed;

        return os;
    }
};

template <typename T>
ostream &operator<<(ostream &os, AbstractRandomGenerator<T> &obj)
{
    return obj.put(os);
}

class Dice : public AbstractRandomGenerator<int>
{
private:
    int doubles;

public:
    Dice() : AbstractRandomGenerator<int>(1, 6, values), doubles(0)
    {
        for (int i = 0; i < num_values; i++)
        {
            values[i] = i + 1;
        }
    }

    void nudge()
    {
        value += rand() % (1 - (-1) + 1) + (-1);

        int min = INT_MAX;
        int max = INT_MIN;

        for (int i = 0; i < num_values; i++)
        {
            if (values[i] < min)
            {
                min = values[i];
            }
            if (values[i] > max)
            {
                max = values[i];
            }
        }

        if (value > max)
        {
            value = max;
        }
        else if (value < min)
        {
            value = min;
        }
    }

    int toss()
    {
        int aux = AbstractRandomGenerator<int>::toss();

        if (aux == value)
        {
            doubles++;
        }

        return value;
    }

    double getDoubleRate()
    {
        return (double)doubles / tossed;
    }

    ostream &put(ostream &os)
    {
        AbstractRandomGenerator<int>::put(os);

        //...

        return os;
    }
};

class Coin : public AbstractRandomGenerator<string>
{
private:
    int nudge_prob;

public:
    Coin(int nudge_prob) : AbstractRandomGenerator<string>("H", 2, values), nudge_prob(nudge_prob)
    {
        values[0] = "H";
        values[1] = "T";
    }

    void nudge()
    {
        int random = rand() % nudge_prob;

        if (random == 0)
        {
            string aux = values[0];
            values[0] = values[1];
            values[1] = aux;
        }
    }

    ostream &put(ostream &os)
    {
        AbstractRandomGenerator<string>::put(os);

        //...

        return os;
    }
};

int main()
{
    srand(424242);

    AbstractRandomGenerator<int> *vec1[DIM];
    AbstractRandomGenerator<string> *vec2[DIM];

    for (int i = 0; i < DIM; i++)
    {
        vec1[i] = new Dice();
        vec2[i] = new Coin(rand() % 10 + 1);
    }

    for (int i = 0; i < 100; i++)
    {
        vec1[rand() % DIM]->toss();
        vec2[rand() % DIM]->toss();
        if (rand() % 5 == 0)
        {
            vec1[rand() % DIM]->nudge();
            vec2[rand() % DIM]->nudge();
        }
    }

    // Punto 1

    for (int i = 0; i < DIM; i++)
    {
        cout << i << ") " << *vec1[i] << endl;
        cout << i << ") " << *vec2[i] << endl;
    }

    // Punto 2

    int min = INT_MAX;

    for (int i = 0; i < DIM; i++)
    {
        if (vec2[i]->getTossed() < min)
        {
            min = vec2[i]->getTossed();
        }
    }

    cout << "min vec2[] getTossed() = " << min << endl;

    double max = INT_MIN;

    for (int i = 0; i < DIM; i++)
    {
        if (typeid(Dice) == typeid(*vec1[i]))
        {
            if ((dynamic_cast<Dice *>(vec1[i]))->getDoubleRate() > max)
            {
                max = (dynamic_cast<Dice *>(vec1[i]))->getDoubleRate();
            }
        }
    }

    cout << "max vec1[] getDoubleRate() = " << max;
}