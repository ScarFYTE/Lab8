#include <iostream>
#include <string>


using namespace std;

class PoweredSystem {
    public:
    PoweredSystem() {
        cout << "PoweredSystem constructor called." << endl;
    }
    ~PoweredSystem() {
        cout << "PoweredSystem destructor called." << endl;
    }

        virtual void powerOn() = 0;
        virtual void powerOff() = 0;
};

class Vehicle : public PoweredSystem {
    public:
        Vehicle() {
            cout << "Vehicle constructor called." << endl;
        }

        ~Vehicle() {
            cout << "Vehicle destructor called." << endl;
        }

        void powerOn() override {
            cout << "Vehicle is powered on." << endl;
        }
        
        void powerOff() override {
            cout << "Vehicle is powered off." << endl;
        }
};

class Engine : public PoweredSystem {
    public:
        Engine() {
            cout << "Engine constructor called." << endl;
        }

        ~Engine() {
            cout << "Engine destructor called." << endl;
        }

        void powerOn() override {
            cout << "Engine is powered on." << endl;
        }
        
        void powerOff() override {
            cout << "Engine is powered off." << endl;
        }
};

class Car : virtual public Vehicle, virtual public Engine {
    public:
        Car() {
            cout << "Car constructor called." << endl;
        }

        ~Car() {
            cout << "Car destructor called." << endl;
        }
        void powerOn() override {
            Vehicle::powerOn();
            Engine::powerOn();
        }
        void powerOff() override {
            Vehicle::powerOff();
            Engine::powerOff();
        }
};

void TestDiamondProblem() {
    Car myCar;
    myCar.powerOn();
    myCar.powerOff();
}

int main() {
    cout<<"Testing the Diamond Problem with virtual inheritance:" << endl;
    TestDiamondProblem();
    return 0;
}
