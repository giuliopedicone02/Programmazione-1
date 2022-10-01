#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

#define DIM 10

using namespace std;

class Tank{
    private:
        double capacity;
        double fuelLevel;

    public:
        Tank(double capacity, double fuelLevel){
            this->capacity=capacity;
            this->fuelLevel=fuelLevel;
        }
        double getCapacity(){
            return capacity;
        }
        double fill(double fuel){
			if(fuelLevel+fuel <= capacity){
				fuelLevel += fuel;
				return 0;
			}else{
                double fuelLevel2 = fuelLevel;
                fuelLevel=capacity;
			    return (fuelLevel2+fuel)-(capacity);
            }
		}
        bool consume(double fuel){
            if(fuelLevel-fuel >= 0){
                fuelLevel-=fuel;
                return true;
            }else{
                return false;
            }
        }
        double getTankLevel(){
            return fuelLevel/capacity;
        }
        bool hasFuel(double fuel){
            if(fuelLevel >= fuel){
                return true;
            }else{
                return false;
            }
        }
};

class Vehicle{
    protected:
        int wheels;
        Tank tank;
        double chilometers;

    public:
        Vehicle(int wheels, double chilometers, double tankCapacity, double fuelLevel) : tank(tankCapacity, fuelLevel){
            this->wheels=wheels;
            this->chilometers=chilometers;
        }
        virtual bool drive(double km)=0;
        double getTankLevel(){
            return tank.getTankLevel();
        }
        virtual ostream& put(ostream& os){
            os << "Class=" << typeid(*this).name() << " wheels=" << wheels << ", chilometers=" << chilometers << " tank.getCapacity()=" << tank.getCapacity(); 
            return os;
        }
};

ostream& operator<<(ostream& os, Vehicle& obj){
    return obj.put(os);
}

class Car : public Vehicle{
    protected:
        int times;

    public:
        Car(double chilometers) : Vehicle(4, chilometers, 55, 25){
            times=0;
        }
        bool drive(double km){
            double carburante_necessario=km*0.075;
            if(tank.getTankLevel() < 0.5){
                carburante_necessario-=(5/(double)100)*carburante_necessario;
            }
            if(tank.hasFuel(carburante_necessario)){
                tank.consume(carburante_necessario);
                chilometers+=km;
                times++;
                return true;
            }else{
                return false;
            }
        }
        int getTimes(){
            return times;
        }
        ostream &put(ostream &os){
            Vehicle::put(os);
            os << " times=" << times;
            return os;
        }
};

class Truck : public Vehicle{
    public:
        Truck(double chilometers) : Vehicle(6, chilometers, 110, 50){}
        bool drive(double km){
            double carburante_necessario=km*0.4;
            if(chilometers > 200000){
                carburante_necessario+=(20/(double)100)*carburante_necessario;
            }
            if(tank.hasFuel(carburante_necessario)){
                tank.consume(carburante_necessario);
                chilometers+=km;
                return true;
            }else{
                return false;
            }
        }
        ostream &put(ostream &os){
            Vehicle::put(os);
            return os;
        }
};

int main(){
    srand(424242);

    Vehicle** vec=new Vehicle*[DIM];

    for(int i=0; i<DIM; i++) {
        int chilometers = rand()%200000;
        if(rand()%2){
            vec[i] = new Car(chilometers);
        } else {
            vec[i] = new Truck(chilometers);
        }
    }

    for(int i=0; i<DIM*5; i++) {
        int x = rand()%100;
        vec[x%DIM]->drive(x);
    }

    cout << "Punto 2" << endl;
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vec[i] << endl;
    }

    return 0;
}