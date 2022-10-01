#include <iostream>
#include <cstdlib>
#include <string>
#include <typeinfo>
#include <cmath>
#define DIM 10
// NO PUNTI 2 E 3
// Omesso TankFuelLevel()
using namespace std;

class Tank
{

    double capacity;
    double fuelLevel;

public:
    Tank(double capacity, double fuelLevel)
    {
        this->capacity = capacity;
        this->fuelLevel = fuelLevel;
    }
    double getCapacity() { return capacity; }
    double fill(double fuel)
    {
        if (capacity > fuel && fuelLevel < fuel)
        {
            fuelLevel += fuel;
            return 0;
        }
        else
        {
            fuelLevel = capacity;
            double exccess= fuel - capacity;
            return exccess;
        }
    }
    bool consume(double fuel)
    {
        if (fuelLevel > fuel)
        {
            fuelLevel = fuelLevel - fuel;
            return true;
        }
        else
        {
            return false;
        }
    }

    double getTankLevel()
    {
        return (fuelLevel / capacity);
    }

    bool hasFuel(double fuel)
    {
        if (fuelLevel > fuel)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Vehicle
{
protected:
    int wheels;
    Tank tank;
    double chilometers;

public:
   Vehicle(int wheels, double chilometers, double tankCapacity, double fuelLevel): wheels(wheels), chilometers(chilometers), tank{tankCapacity, fuelLevel}{}

   virtual bool drive(double km) = 0;
    double getTankLevel() { return tank.getTankLevel(); }
    virtual ostream& put(ostream& os) {
            os << "Class=" << typeid(*this).name() << ", wheels=" << wheels << ", chilometers = "<<chilometers<<" tank.getCapacity()= "<<tank.getCapacity();
            return os;
        }
};
class Car : public Vehicle
{
    protected:
    int times;
    public:
    Car(double chilometers) : Vehicle(4,chilometers,55,25)
    {
        this->times=0;
    }

    bool drive(double km)
    {
        double carb= 0.0;
        carb=km*0.075;
        double livello = Vehicle::getTankLevel();
        if(livello<27.5)
        {
         carb= (carb  * 95.00) /100.00;
        }
        if(Vehicle::tank.hasFuel(carb))
        {
            Vehicle::tank.consume(carb);
            chilometers+=km;
            times++;
            return true;
        }else
        {
            return false;
        }
        return false;
    }

    int getTimes(){return times;}
    ostream& put(ostream& os) {
         Vehicle::put(os);
            os << ", times=" << times;
            return os;
    }
};


class Truck : public Vehicle
{
public:
Truck(double chilometers) : Vehicle(6,chilometers,110,50){}

bool drive(double km)
{
  double carb= 0.0;
        carb=km*0.4;  
                double livello = Vehicle::getTankLevel();
        if(km>200000)
        {
            carb=(carb*120.00)/100.00;
            if(Vehicle::tank.hasFuel(carb))
            {
                            Vehicle::tank.consume(carb);
                chilometers+=km;
                return true;
            }
        }
return false;
}
 ostream& put(ostream& os) {
         Vehicle::put(os);
            return os;
    }
};
ostream& operator<<(ostream& os, Vehicle& obj) {
    return obj.put(os);
}
int main()
{
    srand(424242);
        Vehicle* vec[DIM];

    for(int i=0; i<DIM; i++)
    {
        int chilometers = rand()%200000;
        if(rand()%2)
        {
            vec[i] = new Car(chilometers);
        }else
        {
            vec[i] = new Truck (chilometers);
        }
    }

    for(int i=0; i<DIM*5; i++)
    {
        int x = rand()%100;
        vec[x%DIM]->drive(x);
    }

    for(int i=0; i<DIM; i++)
    {
      cout<<i<<" ) " <<*   vec[i] <<endl;
    }
}