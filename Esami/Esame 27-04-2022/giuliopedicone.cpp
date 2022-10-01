#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <climits>
using namespace std;

#define DIM 15

class Wheel
{
private:
    int value;
    int default_value;
    int num_faces;

public:
    Wheel(int initial_value, int num_faces) : value(initial_value), default_value(initial_value), num_faces(num_faces){};

    void rotate(int turns)
    {
        value += turns;
        value = value % num_faces; // Se value è maggiore di num_faces effettuiamo il modulo
    };

    int getValue() { return value; };

    void reset() { value = default_value; };
};

class AbstractSlotMachine
{
protected:
    Wheel **wheels;
    int num_wheels;
    int prize;
    int num_spins;
    int num_wins;

public:
    AbstractSlotMachine(int num_wheels, int num_faces) : prize(0), num_spins(0), num_wins(0), num_wheels(num_wheels)
    {
        wheels = new Wheel *[num_wheels];

        for (int i = 0; i < num_wheels; i++)
        {
            wheels[i] = new Wheel(rand() % num_faces - 1, num_faces);
        }
    };

    virtual int spin() = 0;

    int getPrize() { return prize; }

    double getWinRate() { return (double)num_wins / num_spins; };

    void reset()
    {
        for (int i = 0; i < num_wheels; i++)
        {
            wheels[i]->reset();
        }
    };

    virtual ostream &put(ostream &os)
    {
        os << "Class = " << typeid(*this).name() << ", num_wheels = " << num_wheels << ", prize = " << prize << ", num_spins = " << num_spins << ", num_wins = " << num_wins << ", winrate = " << getWinRate();

        return os;
    }
};

ostream &operator<<(ostream &os, AbstractSlotMachine &obj)
{
    return obj.put(os);
}

class ThreeWheelsSlotMachine : public AbstractSlotMachine
{
private:
    int num_max;

public:
    ThreeWheelsSlotMachine() : AbstractSlotMachine(3, 6), num_max(0){};

    int spin()
    {
        int temp = wheels[0]->getValue(), cont = 0, temp_prize = 0;
        num_spins++;

        for (int i = 0; i < 3; i++)
        {
            wheels[i]->rotate(rand() % (10 - 3 + 1) + 3);
            prize += wheels[i]->getValue();

            if (temp == wheels[i]->getValue())
            {
                temp = wheels[i]->getValue();
                cont++;
            }
        }

        if (cont == 2)
        {
            num_wins++;
            temp_prize = prize;
            prize = 0;

            if (prize == num_max)
            {
                num_max++;
                return temp_prize * 2;
            }

            return temp_prize;
        }

        return 0;
    }

    int getNumMax()
    {
        return num_max;
    }

    ostream &put(ostream &os)
    {
        AbstractSlotMachine::put(os);

        os << ", num_max = " << num_max;

        return os;
    }
};

class TenWheelsSlotMachine : public AbstractSlotMachine
{
public:
    TenWheelsSlotMachine() : AbstractSlotMachine(5, 10){};

    int spin()
    {
        int num = 0;
        int valori[5];
        bool duplicato = false;
        num_spins++;

        for (int i = 0; i < 5; i++)
        {
            if (i == 0)
            {
                num = rand() % (10 - 3 + 1) + 3;
            }
            else
            {
                num = (rand() % (10 - 3 + 1) + 3) + round(num / 3);
            }

            wheels[i]->rotate(num);

            prize += wheels[i]->getValue();

            valori[i] = wheels[i]->getValue();
        }

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (valori[i] == valori[j] && i != j)
                {
                    duplicato = true;
                    break;
                }
            }
        }

        if (duplicato == false)
        {
            num_wins++;
            int temp_prize = prize;

            prize = 0;
            return temp_prize;
        }

        return 0;
    }

    ostream &put(ostream &os)
    {
        AbstractSlotMachine::put(os);

        return os;
    }
};

int main()
{
    srand(424242);

    AbstractSlotMachine *vec[DIM];

    for (int i = 0; i < DIM; i++)
    {
        if (rand() % 2)
        {
            vec[i] = new ThreeWheelsSlotMachine();
        }
        else
        {
            vec[i] = new TenWheelsSlotMachine();
        }
    }

    for (int i = 0; i < DIM * 100; i++)
    {
        vec[rand() % DIM]->spin();

        if (rand() % 5 == 0)
        {
            vec[rand() % DIM]->reset();
        }
    }

    // Punto 1

    for (int i = 0; i < DIM; i++)
    {
        cout << i + 1 << ") " << *vec[i] << endl;
    }

    // Punto 2

    double max = INT_MIN;

    for (int i = 0; i < DIM; i++)
    {
        if (vec[i]->getWinRate() > max)
        {
            max = vec[i]->getWinRate();
        }
    }

    cout << endl
         << "max win rate = " << max;

    // Punto 3

    double avg = 0.0;
    int cont = 0;

    for (int i = 0; i < DIM; i++)
    {
        if (typeid(*vec[i]) == typeid(ThreeWheelsSlotMachine))
        {
            avg += (dynamic_cast<ThreeWheelsSlotMachine *>(vec[i]))->getNumMax();
            cont++;
        }
    }

    cout << endl
         << "mean num max = " << (double)avg / cont;
}