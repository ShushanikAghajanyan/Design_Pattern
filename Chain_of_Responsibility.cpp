#include <iostream>
#include <memory>


class CashHandler {
    protected:
    std::shared_ptr<CashHandler> next;
    public:
    virtual ~CashHandler() = default;

    void setnext(std::shared_ptr<CashHandler> nextHandler){
        next = std::move(nextHandler);
    }
    virtual void handle(int amount){
        if(next){
            next->handle(amount);
        }
        else if(amount > 0){
            std::cout << "Cannot dispense remaining amount: " << amount << "\n";
        }
    }
};

class HundredHandler : public CashHandler{
    public:
    void handle(int amount) override{
        int count = amount / 100;
        if(count > 0){
           std::cout << "Dispensing " << count << " x 100 bills\n";
        }
        int remainder = amount % 100;
        if(remainder > 0 && next){
            next->handle(remainder);
        }
        else if(remainder > 0){
            std::cout << "Cannot dispense remaining amount: " << remainder << "\n";
        }
    }
};

class FiftyHandler : public CashHandler{
    public:
    void handle(int amount) override{
        int count = amount / 50;
        if(count > 0){
            std::cout << "Dispensing " << count << " x 50 bills\n";
        }
        int remainder = amount % 50;
        if(remainder > 0 && next){
            next->handle(remainder);
        }
        else if(remainder > 0){
            std::cout << "Cannot dispense remaining amount: " << remainder << "\n";
        }
    }
};

class TwentyHandler : public CashHandler{
    public:
    void handle(int amount) override{
        int count = amount / 20;
        if(count > 0){
            std::cout << "Dispensing " << count << " x 20 bills\n";
        }
        int remainder = amount % 20;
        if(remainder > 0 && next){
            next->handle(remainder);
        }
        else if(remainder > 0){
            std::cout << "Cannot dispense remaining amount: " << remainder << "\n";
        }
    }
};

int main(){
    auto hundredHandler = std::make_shared<HundredHandler>();
    auto fiftyHandler = std::make_shared<FiftyHandler>();
    auto twentyHandler = std::make_shared<TwentyHandler>();

    hundredHandler->setnext(fiftyHandler);
    fiftyHandler->setnext(twentyHandler);

    int amount_1 = 380;
    std::cout << "Processing withdrawal of " << amount_1 << ":\n";
    hundredHandler->handle(amount_1);

    std::cout << "\n";

    int amount_2 = 75;
    std::cout << "Processing withdrawal of " << amount_2 << ":\n";
    fiftyHandler->handle(amount_2);

    return 0;


}
