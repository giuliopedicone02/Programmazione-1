#include <iostream>
#include <cstdlib>
#include <string>
#include <typeinfo>
#include <cmath>

using namespace std;

int *input_dice = new int[6]{1, 2, 3, 4, 5, 6};
string *input_coin = new string[2]{"H", "T"};

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
    AbstractRandomGenerator(T value, int num_values, T *input_values) : tossed(0)
    {
        this->value = value;
        this->num_values = num_values;
        values = new T[num_values];

        for (int i = 0; i < num_values; i++)
            values[i] = input_values[i];

        this->accumulated_value = value;
    }

    virtual T toss()
    {
        this->value = values[rand() % num_values];
        this->tossed++;
        this->accumulated_value += this->value;

        return this->value;
    }

    T getValue()
    {
        return this->value;
    }

    int getTossed()
    {
        return this->tossed;
    }

    virtual void nudge() = 0;

    virtual ostream &print(ostream &os)
    {
        os << "Class = " << typeid(*this).name() << ", values = { ";
        for (int i = 0; i < this->num_values; i++)
            os << this->values[i] << ' ';

        os << "}, value = " << this->value << ", accumulated value = " << this->accumulated_value << ", tossed = " << this->tossed;
        return os;
    }
};

class Dice : public AbstractRandomGenerator<int>
{
private:
    int doubles;

public:
    Dice() : AbstractRandomGenerator<int>(1, 6, input_dice), doubles(0) {}

    void nudge()
    {
        AbstractRandomGenerator<int>::value += (double(rand()) / (double(RAND_MAX) * 2) - 1);
        if (AbstractRandomGenerator<int>::value > 6)
            AbstractRandomGenerator<int>::value = 6;
        else if (AbstractRandomGenerator<int>::value < 1)
            AbstractRandomGenerator<int>::value = 1;
    }

    int toss()
    {
        int previous = AbstractRandomGenerator<int>::getValue();
        int current = AbstractRandomGenerator<int>::toss();

        if (previous == current)
            this->doubles++;

        return AbstractRandomGenerator<int>::getValue();
    }

    double getDoubleRate()
    {
        double tmp_tossed = double(AbstractRandomGenerator<int>::tossed);
        return (double(this->doubles) / tmp_tossed);
    }

    ostream &print(ostream &os)
    {
        AbstractRandomGenerator<int>::print(os);
        return os;
    }
};

class Coin : public AbstractRandomGenerator<string>
{
private:
    int nudge_prob;

public:
    Coin(int nudge_prob) : AbstractRandomGenerator<string>("H", 2, input_coin)
    {
        this->nudge_prob = nudge_prob;
    }

    void nudge()
    {
        int tmp = rand() % nudge_prob;
        if (tmp == 0)
            if (AbstractRandomGenerator<string>::value == "H")
                AbstractRandomGenerator<string>::value = "T";
            else
                AbstractRandomGenerator<string>::value = "H";
    }

    ostream &print(ostream &os)
    {
        AbstractRandomGenerator<string>::print(os);
        return os;
    }
};

template <typename T>
ostream &operator<<(ostream &os, AbstractRandomGenerator<T> &obj)
{
    return obj.print(os);
}

int main()
{
    srand(424242);
    int const DIM = 7;

    AbstractRandomGenerator<int> **vec1 = new AbstractRandomGenerator<int> *[DIM];
    AbstractRandomGenerator<string> **vec2 = new AbstractRandomGenerator<string> *[DIM];

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

    cout << "PUNTO 1" << endl;
    for (int i = 0; i < DIM; i++)
    {
        cout << i + 1 << ") " << vec1[i][0] << endl;
        cout << i + 1 << ") " << vec2[i][0] << endl;
    }

    cout << "\nPUNTO 2" << endl;
    int min_tossed = vec2[0]->getTossed();
    for (int i = 0; i < DIM; i++)
        if (min_tossed > vec2[i]->getTossed())
            min_tossed = vec2[i]->getTossed();

    cout << "min tossed = " << min_tossed << endl;

    cout << "\nPUNTO 3" << endl;
    double max_double_rate = (dynamic_cast<Dice *>(vec1[0]))->getDoubleRate();
    for (int i = 0; i < DIM; i++)
        if (max_double_rate < (dynamic_cast<Dice *>(vec1[i]))->getDoubleRate())
            max_double_rate = (dynamic_cast<Dice *>(vec1[i]))->getDoubleRate();

    cout << "max double rate = " << max_double_rate << endl;
}