#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>


class Observer{
    public:
    virtual ~Observer() = default;
    virtual void update(float) = 0;
};

class Investor : public Observer {
    public:
    void update(float price) override{
        std::cout << "Investor notified: Stock price updated to $" << price << "\n";
    }
};

class Stock{
    private:
    std::vector<std::shared_ptr<Observer>> observers;
    float price;

    public:
    Stock(float initPrice) : price(initPrice){}

    void addObserver(std::shared_ptr<Observer> observer){
        observers.push_back(observer);
    }
    void removeObserver(std::shared_ptr<Observer> observer){
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void setPrice(float newPrice){
        price = newPrice;
        notify();
    }
    void notify(){
        for(auto& observer : observers){
            observer->update(price);
        }
    }
};

int main(){
    auto stock = std::make_shared<Stock>(100.0f);
    auto investor_1 = std::make_shared<Investor>();
    auto investor_2 = std::make_shared<Investor>();

    stock->addObserver(investor_1);
    stock->addObserver(investor_2);
    stock->setPrice(105.0f);
    stock->removeObserver(investor_1);
    stock->setPrice(110.0f);

    return 0;
}
