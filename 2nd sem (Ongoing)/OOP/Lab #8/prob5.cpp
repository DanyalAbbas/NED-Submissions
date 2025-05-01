#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string type;
    string make;
    string model;
    string color;
    int year;
    double milesDriven;

public:
    Vehicle(string type, string make, string model, string color, int year, double milesDriven) {
        this->type = type;
        this->make = make;
        this->model = model;
        this->color = color;
        this->year = year;
        this->milesDriven = milesDriven;
    }

    virtual void display() {
        cout << "Vehicle Type: " << type << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
        cout << "Miles Driven: " << milesDriven << endl;
    }
};

class GasVehicle : public Vehicle {
protected:
    double fuelTankSize;

public:
    GasVehicle(string type, string make, string model, string color, int year, 
               double milesDriven, double fuelTankSize) 
        : Vehicle(type, make, model, color, year, milesDriven) {
        this->fuelTankSize = fuelTankSize;
    }

    void display() override {
        Vehicle::display();
        cout << "Fuel Tank Size: " << fuelTankSize << " gallons" << endl;
    }
};

class ElectricVehicle : public Vehicle {
protected:
    double energyStorage;

public:
    ElectricVehicle(string type, string make, string model, string color, int year, 
                    double milesDriven, double energyStorage) 
        : Vehicle(type, make, model, color, year, milesDriven) {
        this->energyStorage = energyStorage;
    }

    void display() override {
        Vehicle::display();
        cout << "Energy Storage: " << energyStorage << " kWh" << endl;
    }
};

class HighPerformance : public GasVehicle {
protected:
    int horsePower;
    int topSpeed;

public:
    HighPerformance(string type, string make, string model, string color, int year, 
                    double milesDriven, double fuelTankSize, int horsePower, int topSpeed) 
        : GasVehicle(type, make, model, color, year, milesDriven, fuelTankSize) {
        this->horsePower = horsePower;
        this->topSpeed = topSpeed;
    }

    void display() override {
        GasVehicle::display();
        cout << "Horse Power: " << horsePower << endl;
        cout << "Top Speed: " << topSpeed << " mph" << endl;
    }
};

class HeavyVehicle : public GasVehicle {
protected:
    double maxWeight;
    int numWheels;
    double length;

public:
    HeavyVehicle(string type, string make, string model, string color, int year, 
                 double milesDriven, double fuelTankSize, double maxWeight, 
                 int numWheels, double length) 
        : GasVehicle(type, make, model, color, year, milesDriven, fuelTankSize) {
        this->maxWeight = maxWeight;
        this->numWheels = numWheels;
        this->length = length;
    }

    void display() override {
        GasVehicle::display();
        cout << "Maximum Weight: " << maxWeight << " tons" << endl;
        cout << "Number of Wheels: " << numWheels << endl;
        cout << "Length: " << length << " feet" << endl;
    }
};

class SportsCar : public HighPerformance {
private:
    string gearbox;
    string driveSystem;

public:
    SportsCar(string make, string model, string color, int year, double milesDriven, 
              double fuelTankSize, int horsePower, int topSpeed, string gearbox, string driveSystem) 
        : HighPerformance("Sports Car", make, model, color, year, milesDriven, fuelTankSize, horsePower, topSpeed) {
        this->gearbox = gearbox;
        this->driveSystem = driveSystem;
    }

    void display() override {
        HighPerformance::display();
        cout << "Gearbox: " << gearbox << endl;
        cout << "Drive System: " << driveSystem << endl;
    }
};

class ConstructionTruck : public HeavyVehicle {
private:
    string cargo;

public:
    ConstructionTruck(string make, string model, string color, int year, double milesDriven, 
                     double fuelTankSize, double maxWeight, int numWheels, double length, string cargo) 
        : HeavyVehicle("Construction Truck", make, model, color, year, milesDriven, fuelTankSize, maxWeight, numWheels, length) {
        this->cargo = cargo;
    }

    void display() override {
        HeavyVehicle::display();
        cout << "Cargo: " << cargo << endl;
    }
};

class Bus : public HeavyVehicle {
private:
    int numSeats;

public:
    Bus(string make, string model, string color, int year, double milesDriven, 
        double fuelTankSize, double maxWeight, int numWheels, double length, int numSeats) 
        : HeavyVehicle("Bus", make, model, color, year, milesDriven, fuelTankSize, maxWeight, numWheels, length) {
        this->numSeats = numSeats;
    }

    void display() override {
        HeavyVehicle::display();
        cout << "Number of Seats: " << numSeats << endl;
    }
};

int main() {
    Bus schoolBus("Blue Bird", "All American", "Yellow", 2020, 15000, 60, 15, 6, 40, 72);
    
    cout << "Bus Information:" << endl;
    cout << "----------------" << endl;
    schoolBus.display();
    
    return 0;
}