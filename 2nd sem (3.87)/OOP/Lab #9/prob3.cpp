#include<iostream>
using namespace std;

class Vehicle {
private:
    int car_id;
    string brand;
    int model;

public:
    Vehicle() {
        car_id = 0;
        brand = " ";
        model = 0;
    }

    Vehicle(int c, string b, int m) {
        car_id = c;
        brand = b;
        model = m;
    }

    int getc() {
        return car_id;
    }

    string getb() {
        return brand;
    }

    int getm() {
        return model;
    }

    virtual bool isavailable() = 0;
    virtual void rent() = 0;
    virtual void returncar() = 0;

    void cardetails() {
        cout << "CAR ID: " << car_id << endl;
        cout << "BRAND: " << brand << endl;
        cout << "MODEL: " << model << endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    bool available;

public:
    Car(int c, string b, int m) : Vehicle(c, b, m) {
        available = true;
    }

    bool isavailable() override {
        return available;
    }

    void rent() override {
        if (available) {
            available = false;
            cout << "CAR HAS BEEN RENTED!" << endl;
        } else {
            cout << "CAR IS ALREADY RENTED!" << endl;
        }
    }

    void returncar() override {
        if (!available) {
            available = true;
            cout << "CAR HAS BEEN RETURNED!" << endl;
        } else {
            cout << "CAR WAS NOT RENTED!" << endl;
        }
    }
};

class RentalSystem {
public:
    void rentvehicle(Vehicle* v) {
        if (v->isavailable()) {
            v->rent();
        } else {
            cout << "THIS CAR HAS ALREADY BEEN RENTED!" << endl;
        }
    }

    void returnvehicle(Vehicle* v) {
        if (!v->isavailable()) {
            v->returncar();
        } else {
            cout << "THIS CAR WAS NOT RENTED!" << endl;
        }
    }
};

class Customer {
public:
    void rentvehicle(Vehicle* v, RentalSystem* r) {
        r->rentvehicle(v);
    }

    void returnvehicle(Vehicle* v, RentalSystem* r) {
        r->returnvehicle(v);
    }
};

int main() {
    Vehicle* vehicles[2];

    vehicles[0] = new Car(100, "HONDA", 2010);
    vehicles[1] = new Car(101, "BMW", 2009);

    RentalSystem rs;
    Customer c;

    cout << "\nTRYING TO RENT VEHICLE 1" << endl;
    c.rentvehicle(vehicles[0], &rs);

    cout << "\nTRYING TO RENT VEHICLE 2" << endl;
    c.rentvehicle(vehicles[1], &rs);

    cout << "\nRETURNING VEHICLE 1" << endl;
    c.returnvehicle(vehicles[0], &rs);

    cout << "\nRETURNING VEHICLE 2" << endl;
    c.returnvehicle(vehicles[1], &rs);

    delete vehicles[0];
    delete vehicles[1];

    return 0;
}