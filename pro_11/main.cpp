#include <iostream>
#include <string>

class Temperature;

class Humidity {
    private:
        int m_humidity {};
    public:
        Humidity(int humidity=0): m_humidity { humidity }{}

        void printWeather(const Temperature& Temperature);
};

class Temperature {
    private:
        int m_temp {};
    public:
        Temperature(int temp=0) : m_temp { temp }{}

        friend void Humidity::printWeather(const Temperature& temperature);
};

void Humidity::printWeather(const Temperature& temperature) {
    std::cout << "The temperature is " << temperature.m_temp <<
    " and the humidity is " << m_humidity << '\n';
}

int main() {

    return 0;
}