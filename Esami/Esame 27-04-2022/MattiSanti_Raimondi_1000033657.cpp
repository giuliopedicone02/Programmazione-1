#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <climits>
using namespace std;

class Wheel
{
private:
    int value;
    int default_value;
    int num_faces;

public:
    Wheel(int initial_value, int num_faces) : value(initial_value), default_value(initial_value), num_faces(num_faces) {}

    void rotate(int turns)
    {
        value = (value + turns) % num_faces;
    }

    int getValue() const
    {
        return value;
    }

    void reset()
    {
        value = default_value;
    }
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
            wheels[i] = new Wheel(rand() % num_faces, num_faces);
        }
    }

    virtual int spin() = 0;

    int getPrize() const
    {
        return prize;
    }

    double getWinRate()
    {
        return (double)num_wins / num_spins;
    }

    void reset()
    {
        for (int i = 0; i < num_wheels; i++)
        {
            wheels[i]->reset();
        }
    }

    virtual ostream &put(ostream &os)
    {
        os << "Class=" << typeid(*this).name() << ", num_wheels" << num_wheels << ", prize=" << prize << ", num_spins=" << num_spins << ", num_wins" << num_wins << ", winrate=" << getWinRate();

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
    ThreeWheelsSlotMachine() : AbstractSlotMachine(3, 6), num_max(0) {}

    int spin()
    {
        num_spins++;
        int val[3];

        for (int i = 0; i < num_wheels; i++)
        {
            wheels[i]->rotate(rand() % (10 - 3 + 1) + 3);
            val[i] = wheels[i]->getValue();
            prize += val[i];
        }

        if (val[0] == val[1] && val[0] == val[2])
        {
            if (val[0] == 5)
            {
                prize *= 2;
                num_max++;
            }
            num_wins++;
            int temp_prize = prize;
            prize = 0;
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

        os << ", num_max=" << num_max;

        return os;
    }
};

class TenWheelsSlotMachine : public AbstractSlotMachine
{
public:
    TenWheelsSlotMachine() : AbstractSlotMachine(5, 10) {}

    int spin()
    {
        num_spins++;
        int val[10];
        int last_turns = 0;

        for (int i = 0; i < num_wheels; i++)
        {
            int num_turns = rand() % (10 - 3 + 1) + 3 + round(last_turns / 3);
            last_turns = num_turns;
            wheels[i]->rotate(num_turns);
            val[i] = wheels[i]->getValue();
            prize += val[i];
        }
        bool duplicates = false;
        for (int i = 0; i < num_wheels; i++)
        {
            for (int j = i + 1; i < num_wheels; j++)
            {
                if (val[i] == val[j])
                {
                    duplicates = true;
                }
            }
        }
        if (duplicates)
        {
            return 0;
        }
        else
        {
            num_wins++;
            int temp_prize = prize;
            prize = 0;
            return prize;
        }
    }

    ostream &put(ostream &os)
    {
        AbstractSlotMachine::put(os);

        return os;
    }
};

int main()
{
    int DIM = 15;
    AbstractSlotMachine **vec = new AbstractSlotMachine *[DIM];

    srand(424242);

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
            vec[rand() % DIM]->reset();
    }

    // Punto 1:

    for (int i = 0; i < DIM; i++)
    {
        cout << i + 1 << ") " << *vec[i] << endl;
    }

    // Punto 2:

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

    // Punto 3:

    double avg = 0.0;
    int cont = 0;

    for (int i = 0; i < DIM; i++)
    {
        if (typeid(*vec[i]) == typeid(ThreeWheelsSlotMachine))
        {
            avg +=
                dynamic_cast<ThreeWheelsSlotMachine *>(vec[i])->getNumMax();
            cont++;
        }
    }

    cout << endl
         << "mean num max = " << (double)avg / cont;
}