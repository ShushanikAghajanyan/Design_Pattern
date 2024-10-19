#include <iostream>
#include <vector>
#include <string>

class IItem {
public:
    virtual int GetPrice() const = 0;
    virtual const std::string& GetName() const = 0;
    virtual ~IItem() = default;
};

class AItem : public IItem {
public:
    AItem(const std::string& name) : name(name) {}

    const std::string& GetName() const override {
        return name;
    }

    void SetName(const std::string& name) { 
        this->name = name;
    }

protected:
    std::string name;
};

class Item : public AItem {
public:
    Item(int price, const std::string& name) : AItem(name), price(price) {}

    int GetPrice() const override {
        return price;
    }

    void SetPrice(int price) {
        this->price = price;
    }

private:
    int price;
};

class Group : public AItem {
public:
    Group(const std::string& name) : AItem(name) {} 

    int GetPrice() const override {
        int result = 0;
        for (auto&& i : items) {
            result += i->GetPrice();
        }
        return result; 
    }

    void AddItem(IItem* item) { 
        items.push_back(item);
    }

private:
    std::vector<IItem*> items; 
};

int main() {
    Group* group1 = new Group("group1"); 
    Item* item1 = new Item(20, "item1"); 
    Item* item2 = new Item(30, "item2"); 

    group1->AddItem(item1);
    group1->AddItem(item2); 

    std::cout << "Total Price in " << group1->GetName() << ": " << group1->GetPrice() << std::endl;


    delete item1;
    delete item2;
    delete group1;

    return 0;
}
