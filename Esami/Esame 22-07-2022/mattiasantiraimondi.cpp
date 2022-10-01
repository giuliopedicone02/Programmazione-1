#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <climits>
using namespace std;

#define DIM 10

class Tank
{
private:
    double capacity;
    double fuelLevel;

public:
    Tank(double capacity, double fuelLevel) : capacity(capacity), fuelLevel(fuelLevel){};

    double getCapacity()
    {
        return capacity;
    }

    double fill(double fuel)
    {
        if (fuel + fuelLevel > capacity)
        {
            fuelLevel = capacity;
            return (fuel + fuelLevel) - capacity;
        }

        fuelLevel += fuel;
        return 0;
    }

    bool consume(double fuel)
    {
        if (fuelLevel - fuel > 0)
        {
            fuelLevel = fuelLevel - fuel;
            return true;
        }

        return false;
    }

    double getTankLevel()
    {
        return (double)fuelLevel / capacity;
    }

    bool hasFuel(double fuel)
    {
        if (fuelLevel >= fuel)
        {
            return true;
        }

        return false;
    }
};

class Vehicle
{
protected:
    int wheels;
    Tank tank;
    double chilometers;

public:
    Vehicle(int wheels, double chilometers, double tankCapacity, double fuelLevel) : wheels(wheels), chilometers(chilometers), tank(tankCapacity, fuelLevel) {}

    bool virtual drive(double km) = 0;

    double getTankLevel()
    {
        return tank.getTankLevel();
    }

    virtual ostream &put(ostream &os)
    {
        os << "Class=" << typeid(*this).name(); //...

        os << ", wheels = " << wheels << ", chilometers= " << chilometers << ", tank.getCapacity()=" << tank.getCapacity();

        return os;
    }
};

ostream &operator<<(ostream &os, Vehicle &obj)
{
    return obj.put(os);
}
class Car : public Vehicle
{
protected:
    int times;

public:
    Car(double chilometers) : Vehicle(4, chilometers, 55, 25), times(0) {}

    bool drive(double km)
    {
        double carburanteNecessario = km * 0.075;

        if (getTankLevel() < 0.5)
        {
            double percentuale = (double)(5 / 100) * carburanteNecessario;
            carburanteNecessario = carburanteNecessario - percentuale;
        }

        if (tank.hasFuel(carburanteNecessario))
        {
            tank.consume(carburanteNecessario);
            chilometers += km;
            times++;
            return true;
        }

        return false;
    }

    int getTimes()
    {
        return times;
    }

    ostream &put(ostream &os)
    {
        Vehicle::put(os);

        os << ", times = " << times;

        return os;
    }
};

class Truck : public Vehicle
{

public:
    Truck(double chilometers) : Vehicle(6, chilometers, 110, 50) {}

    bool drive(double km)
    {
        double carburanteNecessario = km * 0.4;
        if (Vehicle::chilometers > 200000)
        {
            double percentuale = (double)(20 / 100) * carburanteNecessario;
            carburanteNecessario = carburanteNecessario + percentuale;
        }

        if (tank.hasFuel(carburanteNecessario))
        {
            tank.consume(carburanteNecessario);
            chilometers += km;
            return true;
        }

        return false;
    }

    ostream &put(ostream &os)
    {
        Vehicle::put(os);

        //...

        return os;
    }
};

int main()
{
    srand(424242);

    Vehicle *vec[DIM];

    for (int i = 0; i < DIM; i++)
    {
        int chilometers = rand() % 200000;
        if (rand() % 2)
        {
            vec[i] = new Car(chilometers);
        }
        else
        {
            vec[i] = new Truck(chilometers);
        }
    }

    for (int i = 0; i < DIM * 5; i++)
    {
        int x = rand() % 100;
        vec[x % DIM]->drive(x);
    }

    // Punto 1

    for (int i = 0; i < DIM; i++)
    {
        cout << i << ") " << *vec[i] << endl;
    }

    // Punto 2

    double avg = 0.0;
    int cont = 0;

    for (int i = 0; i < DIM; i++)
    {
        avg += vec[i]->getTankLevel();
        cont++;
    }

    cout << "media getTankLevel(): " << (double)avg / cont << endl;

    // Punto 3

    int max = INT_MIN;

    for (int i = 0; i < DIM; i++)
    {
        if (typeid(*vec[i]) == typeid(Car))
        {
            if (dynamic_cast<Car *>(vec[i])->getTimes() > max)
            {
                max = dynamic_cast<Car *>(vec[i])->getTimes();
            }
        }
    }

    cout << "max getTimes(): " << max;
}