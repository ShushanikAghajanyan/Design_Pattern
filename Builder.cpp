#include<iostream>
#include<vector>

class Cake{
    public:
    std::string size;
    std::string flavor;
    std::vector<std::string> toppings;

    void show() 
    {
     std::cout << "Cake with:\n";    
     std::cout << "Size: " << size << "\n";
     std::cout << "Flavor: " << flavor << "\n";
     std::cout << "Toppings: ";
     for (const auto& topping : toppings) {
     std::cout << topping << " ";
     }
     std::cout << "\n";
    }
};

class CakeBuilder{
    public:
    virtual void setSize() = 0;
    virtual void setFlavor() = 0;
    virtual void setToppings() = 0;
    virtual Cake* getResult() = 0;
    virtual ~CakeBuilder() {}
};
class ChocolateCakeBuilder : public CakeBuilder{
    private:
    Cake *cake;
    public:
    ChocolateCakeBuilder(){
        cake = new Cake();
    }
    void setSize() override{
        cake->size = "medium";
    }
    void setFlavor() override{
        cake->flavor = "chocolate";
    }
    void setToppings() override{
        cake->toppings.push_back("Chocolate chips");
        cake->toppings.push_back("Whipped cream");
    }
    Cake* getResult() override{

        return cake;
    }
};

class VanillaCakeBuilder : public CakeBuilder{
    private:
    Cake* cake;

    public:
    VanillaCakeBuilder(){
        cake = new Cake();
    }

    void setSize() override{
        cake->size = "large";
    }
    void setFlavor() override{
        cake->flavor = "vanilla";
    }
    void setToppings() override{
        cake->toppings.push_back("Sprinkles");
        cake->toppings.push_back("Vanilla frosting");
    }
    Cake* getResult() override{
        return cake;
    }
};

class CakeChef{
    private: 
    CakeBuilder* builder;
    public:
    void setBuilder(CakeBuilder* bulider){
        this->builder = bulider;
    }
    Cake* constructCake(){
        builder->setSize();
        builder->setFlavor();
        builder->setToppings();
        return builder->getResult();
    }
};

int main(){
    CakeChef chef;

    ChocolateCakeBuilder chocolatecakebuilder;
    chef.setBuilder(&chocolatecakebuilder);
    Cake* chocolatecake = chef.constructCake();
    chocolatecake->show();

    delete chocolatecake;

    VanillaCakeBuilder vanillacakebuilder;
    chef.setBuilder(&vanillacakebuilder);
    Cake* vanillacake = chef.constructCake();
    vanillacake->show();

    delete vanillacake;

}
