#include <iostream>

class AmericanSocket {
public:
    virtual void plugIn() = 0;
    virtual ~AmericanSocket() = default;
};

class EuropeanSocket {
public:
    void connect() {
        std::cout << "Connected to European socket." << std::endl;
    }
};

class EuropeanToAmericanAdapter : public AmericanSocket {
public:
    EuropeanToAmericanAdapter(EuropeanSocket* europeanSocket) : europeanSocket(europeanSocket) {}

    void plugIn() override {
        europeanSocket->connect();
    }

private:
    EuropeanSocket* europeanSocket;
};

int main() {
    EuropeanSocket europeanSocket;
    AmericanSocket* adapter = new EuropeanToAmericanAdapter(&europeanSocket);
    adapter->plugIn();
    delete adapter;
    return 0;
}
