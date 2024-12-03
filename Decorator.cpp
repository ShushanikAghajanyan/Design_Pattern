#include <iostream>
#include <string>
#include <memory>


class Coffee{
    public:
    virtual ~Coffee() = default;
    virtual double cost() const = 0;
    virtual std::string description() const = 0;
};

class SimpleCoffee : public Coffee{
    public:
    double cost() const override{
        return 5.0;
    }
    std::string description() const override{
        return "Simple Coffee";
    }

};

class CoffeeDecorator : public Coffee{
    protected:
    std::shared_ptr<Coffee> coffee;
    public:
    explicit CoffeeDecorator(std::shared_ptr<Coffee> coffee) : coffee(std::move(coffee)){}


};

class Milk : public CoffeeDecorator{
    public:
    explicit Milk(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(std::move(coffee)){}

    double cost() const override{
        return coffee->cost() + 1.5;
    }
    std::string description() const override{
        return coffee->description() + ", Milk"; 
    }
};

class Sugar : public CoffeeDecorator{
    public:
    explicit Sugar(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(std::move(coffee)) {}

    double cost() const override{
        return coffee->cost() + 0.5;
    }
    std::string description() const override{
        return coffee->description() + ", Sugar";
    }
};

class WhippedCream : public CoffeeDecorator{
    public:
    explicit WhippedCream(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(std::move(coffee)){}

    double cost() const override{
        return coffee->cost() + 2.0;
    }
    std::string description() const override{
        return coffee->description() + ", WhippedCream";
    }
};

int main(){
    std::shared_ptr<Coffee> myCoffee = std::make_shared<SimpleCoffee>();
    std::cout << myCoffee->description() << " - $" << myCoffee->cost() << "\n";

    myCoffee = std::make_shared<Milk>(myCoffee);
    std::cout << myCoffee->description() << " - $" << myCoffee->cost() << "\n";

    myCoffee = std::make_shared<Sugar>(myCoffee);
    std::cout << myCoffee->description() << " - $" << myCoffee->cost() << "\n";

    myCoffee = std::make_shared<WhippedCream>(myCoffee);
    std::cout << myCoffee->description() << " - $" << myCoffee->cost() << "\n"; 
}
