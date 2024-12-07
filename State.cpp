#include <iostream>

class TrafficLight;

class State{
    public:
    virtual ~State() = default;
    virtual void handle(TrafficLight& light) = 0;
};

class RedLight : public State{
    public:
    void handle(TrafficLight& light) override;
};

class YellowLight : public State {
    public:
    void handle(TrafficLight& light) override;
};

class GreenLight : public State{
    public:
    void handle(TrafficLight& light) override;
};

class TrafficLight{
    public:
    TrafficLight(State* state) : m_state(state){}
    void setState(State* state){
        m_state = state;
    }
    void request(){
        m_state->handle(*this);
    }
    private:
    State* m_state;
};

void RedLight::handle(TrafficLight& light){
    std::cout << "Red Light." << std::endl;
    light.setState(new YellowLight());
}

void GreenLight::handle(TrafficLight& light){
    std::cout << "Green light." << std::endl;
    light.setState(new RedLight());
}

void YellowLight::handle(TrafficLight& light){
    std::cout << "Yellow light." << std::endl;
    light.setState(new GreenLight());
}

int main(){
    TrafficLight light(new RedLight());
        for(int i = 0; i < 6; ++i){
            light.request();
    }
    return 0;
}
