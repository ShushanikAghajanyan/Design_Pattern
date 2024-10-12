#include <iostream>

class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle created" << s;
    delete vehicle1;
    delete carfactory;td::endl;
    }
    virtual ~Vehicle() = default;
    virtual void Drive() = 0;
};

class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car created" << std::endl;
    }
    void Drive() override {
        std::cout << "Car is driving" << std::endl;
    }
};

class Bike : public Vehicle {
public:
    Bike() {
        std::cout << "Bike created" << std::endl;
    }
    void Drive() override {
        std::cout << "Bike is driving" << std::endl;
    }
};

class Truck : public Vehicle {
public:
    Truck() {
        std::cout << "Truck created" << std::endl;
    }
    void Drive() override {
        std::cout << "Truck is driving" << std::endl;
    }
};

class VehicleFactory {
public:
    virtual ~VehicleFactory() = default;
    virtual Vehicle* create() = 0;
};

class CarFactory : public VehicleFactory {
public:
    Vehicle* create() override {
        return new Car();
    }
};

class BikeFactory : public VehicleFactory {
public:
    Vehicle* create() override {
        return new Bike();
    }
};

class TruckFactory : public VehicleFactory {
public:
    Vehicle* create() override {
        return new Truck();
    }
};

int main() {
    VehicleFactory* carFactory = new CarFactory();
    Vehicle* vehicle1 = carFactory->create();
    vehicle1->Drive();
    delete vehicle1;
    delete carFactory;

    VehicleFactory* bikeFactory = new BikeFactory();
    Vehicle* vehicle2 = bikeFactory->create();
    vehicle2->Drive();
    delete vehicle2;
    delete bikeFactory;

    VehicleFactory* truckFactory = new TruckFactory();
    Vehicle* vehicle3 = truckFactory->create();
    vehicle3->Drive();
    delete vehicle3;
    delete truckFactory;

    return 0;
}
