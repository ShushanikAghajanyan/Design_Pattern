#include <iostream>
#include <memory>

class Command {
public:
virtual ~Command() = default;
virtual void execute() = 0;
};

class Light {
    public:
    void on(){
        std::cout << "Light is on" << std::endl;
    }
    void off(){
        std::cout << "Light is off" << std::endl;
    }
};

class LightOnCommand : public Command {
    public:
    explicit LightOnCommand(Light& light) : m_light(light){}
    void execute() override {
        m_light.on();
            }

    private:
    Light m_light;
};

class LightOffCommand : public Command {
    public:
    explicit LightOffCommand(Light& light) : m_light(light){}
    void execute() override{
        m_light.off();
    }
    private:
    Light& m_light;
};

class RemoteControl{
    public:
    void setCommand(std::unique_ptr<Command> command){
        m_command = std::move(command);
    }
    void pressButton(){
        if(m_command){
            m_command->execute();
        }
    }
    private:
    std::unique_ptr<Command> m_command;
};

int main(){
    Light livingRoomLight;

    auto lightOn = std::make_unique<LightOnCommand>(livingRoomLight);
    auto lightOff = std::make_unique<LightOffCommand>(livingRoomLight);

    RemoteControl remote;
    remote.setCommand(std::move(lightOn));
    remote.pressButton();

    remote.setCommand(std::move(lightOff));
    remote.pressButton();

    return 0;
}
