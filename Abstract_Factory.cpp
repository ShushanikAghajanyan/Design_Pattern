#include <iostream>

class Car {
public:
    virtual void drive() = 0;
};

class Bike {
public:
    virtual void ride() = 0;
};

class ElectricCar : public Car {
public:
    void drive() override {
        std::cout << "Driving electric car" << std::endl;
    }
};

class ElectricBike : public Bike {
public:
    void ride() override {
        std::cout << "Riding electric bike" << std::endl;
    }
};

class GasCar : public Car {
public:
    void drive() override {
        std::cout << "Driving gas car" << std::endl;
    }
};

class GasBike : public Bike {
public:
    void ride() override {
        std::cout << "Riding gas bike" << std::endl;
    }
};

class VehicleFactory {
public:
    virtual ~VehicleFactory() = default;
    virtual Car* createCar() = 0;
    virtual Bike* createBike() = 0;
};

class ElectricVehicleFactory : public VehicleFactory {
public:
    Car* createCar() override {
        return new ElectricCar();
    }

    Bike* createBike() override {
        return new ElectricBike();
    }
};

class GasVehicleFactory : public VehicleFactory {
public:
    Car* createCar() override {
        return new GasCar();
    }

    Bike* createBike() override {
        return new GasBike();
    }
};

int main() {
    VehicleFactory* electricFactory = new ElectricVehicleFactory();
    Car* electricCar = electricFactory->createCar();
    Bike* electricBike = electricFactory->createBike();
    electricCar->drive();
    electricBike->ride();

    delete electricCar;
    delete electricBike;
    delete electricFactory;

    VehicleFactory* gasFactory = new GasVehicleFactory();
    Car* gasCar = gasFactory->createCar();
    Bike* gasBike = gasFactory->createBike();
    gasCar->drive();
    gasBike->ride();

    delete gasCar;
    delete gasBike;
    delete gasFactory;

    return 0;
}
