#include <iostream>


class TV{
    public:
    void turnOn(){
        std::cout << "Tv is on" << std::endl;
    }
    void turnOff(){
        std::cout << "Tv is off" << std::endl;
    }
};

class SoundSystem{
    public:
    void turnOn(){
        std::cout << "Sound system is on" << std::endl;
    }
    void turnOff(){
        std::cout << "Sound system is off" << std::endl;
    }
};

class GamingConsole{
    public:
    void turnOn(){
        std::cout << "Gaming console is on" << std::endl;
    }
    void turnOff(){
        std::cout << "Gaming console is off" << std::endl;
    }
};

class HomeTheaterFacade{
    public:
    HomeTheaterFacade(TV& tv, SoundSystem& soundSystem, GamingConsole& gamingConsole) :
     m_tv(tv), m_soundSystem(soundSystem), m_gamingConsole(gamingConsole){} 

    void startMovieNight(){
        std::cout << "Starting movie night..." << std::endl;
        m_tv.turnOn();
        m_soundSystem.turnOn();
    }

    void endMovieNight(){
        std::cout << "Ending movie night..." << std::endl;
        m_tv.turnOff();
        m_soundSystem.turnOff();
    }

    void startGaming(){
        std::cout << "Start gaming..." << std::endl;
        m_tv.turnOn();
        m_soundSystem.turnOn(); 
        m_gamingConsole.turnOn();      
    }

    void endGaming(){
        std::cout << "End gaming..." << std::endl; 
        m_tv.turnOff();
        m_soundSystem.turnOff(); 
        m_gamingConsole.turnOff(); 
    }

    private:
    TV m_tv;
    SoundSystem m_soundSystem;
    GamingConsole m_gamingConsole;
};

int main(){
    TV tv;
    SoundSystem soundSystem;
    GamingConsole console;

    HomeTheaterFacade homeFacade(tv, soundSystem, console);

    homeFacade.startMovieNight();
    std::cout << std::endl;

    homeFacade.endMovieNight();
    std::cout << std::endl;

    homeFacade.startGaming();
    std::cout << std::endl;

    homeFacade.endGaming();
    std::cout << std::endl;
}
