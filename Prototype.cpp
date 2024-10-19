#include <iostream>
#include <string>

class Character {
public:
    virtual Character* clone() const = 0;
    virtual void describe() const = 0;
    virtual ~Character() = default;
};

class Warrior : public Character {
public:
    Warrior(std::string name, int strength) : name(name), strength(strength) {}

    Character* clone() const override {
        return new Warrior(*this);
    }

    void describe() const override {
        std::cout << "Name: " << name << ", Strength: " << strength << std::endl;
    }

private:
    std::string name;
    int strength;
};

class Mage : public Character {
public:
    Mage(std::string name, int power) : name(name), power(power) {}

    Character* clone() const override {
        return new Mage(*this);
    }

    void describe() const override {
        std::cout << "Name: " << name << ", Power: " << power << std::endl;
    }

private:
    std::string name;
    int power;
};

int main() {
    Warrior originalWarrior("Thor", 200);
    Mage originalMage("Gandalf", 100);

    Character* clonedWarrior = originalWarrior.clone();
    Character* clonedMage = originalMage.clone();

    originalWarrior.describe();
    clonedWarrior->describe();

    originalMage.describe();
    clonedMage->describe();

    delete clonedWarrior;
    delete clonedMage;

    return 0;
}
