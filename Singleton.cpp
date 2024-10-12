#include<iostream>

class Singleton{
    private:
    Singleton(){}
    Singleton(const Singleton&) = delete; //don't allow copying
    Singleton operator&=(const Singleton&) = delete; //don't allow assigment

    static Singleton* instance;

    public:
   static  Singleton* getInstance(){
        if(instance == nullptr){
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;

int main(){
   Singleton* obj1 =  Singleton::getInstance();
   Singleton* obj2 = Singleton::getInstance();


    // Test to see if both objects are the same
   if (obj1 == obj2) {  
        std::cout << "obj1 and obj2 point to the same instance." << std::endl;
    }
}
