#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
#define DIM 15

class Wheel
{
private:
    int value;
    int default_value;
    int num_faces;

public:
    Wheel(int initial_value, int num_faces) : default_value(initial_value), value(initial_value), num_faces(num_faces) {}
    void rotate(int turns)
    {
        value = (value + turns) % num_faces;
    }
    int getValue()
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
    virtual int spin() = 0;
    int getPrize()
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
            wheels[i]->reset();
    }
    AbstractSlotMachine(int num_wheels, int num_faces) : prize(0), num_spins(0), num_wins(0), num_wheels(num_wheels)
    {
        this->wheels = new Wheel *[num_wheels];
        for (int i = 0; i < num_wheels; i++)
            wheels[i] = new Wheel(rand() % num_faces, num_faces);
    }
    virtual ostream &print(ostream &os)
    {
        os << ", num_wheels=" << num_wheels << ", prize=" << prize << ", num_spins=" << num_spins << ", num_wins=" << num_wins << ", winrate=" << getWinRate();
        return os;
    }
};

ostream &operator<<(ostream &os, AbstractSlotMachine &w)
{
    return w.print(os);
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
        int vals[3];
        for (int i = 0; i < num_wheels; i++)
        {
            wheels[i]->rotate(rand() % 8 + 3); // 3-10
            vals[i] = wheels[i]->getValue();
            prize += vals[i];
        }
        if (vals[0] == vals[1] && vals[0] == vals[2])
        {
            if (vals[0] == 5)
            {
                prize *= 2;
                num_max++;
            }
            num_wins++;
            int ret_prize = prize;
            prize = 0;
            return ret_prize;
        }
        else
            return 0;
    }
    int getNumMax()
    {
        return num_max;
    }

    ostream &print(ostream &os)
    {
        os << "Class=" << typeid(this).name();
        AbstractSlotMachine::print(os) << ", num_max=" << num_max;
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
        int vals[10];
        int last_turns = 0;
        for (int i = 0; i < num_wheels; i++)
        {
            int num_turns = rand() % 8 + 3 + round(last_turns / 3);
            last_turns = num_turns;
            wheels[i]->rotate(num_turns);
            vals[i] = wheels[i]->getValue();
            prize += vals[i];
        }
        bool duplicates = false;
        for (int i = 0; i < num_wheels; i++)
        {
            for (int j = i + 1; j < num_wheels; j++)
            {
                if (vals[i] == vals[j])
                    duplicates = true;
            }
        }
        if (duplicates)
        {
            return 0;
        }
        else
        {
            num_wins++;
            int ret_prize = prize;
            prize = 0;
            return ret_prize;
        }
    }
    ostream &print(ostream &os)
    {
        os << "Class=" << typeid(this).name();
        AbstractSlotMachine::print(os);
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
    double max = INT_MIN; // max = vec[0]
    for (int i = 0; i < DIM; i++)
    {
        if (vec[i]->getWinRate() > max)
        {
            max = vec[i]->getWinRate();
        }
    }

    cout << "max win rate " << max << endl;

    // Punto 3
    int cont = 0;
    double avg = 0.0;
    for (int i = 0; i < DIM; i++)
    {
        if (typeid(*vec[i]) == typeid(ThreeWheelsSlotMachine))
        {
            // ((ThreeWheelsSlotMachine *)vec[i])->getNumMax();
            avg += dynamic_cast<ThreeWheelsSlotMachine *>(vec[i])->getNumMax();
            cont++;
        }
    }

    cout << "mean num max " << (double)avg / cont << endl;
}