#ifndef DHT22_h
#define DHT22_h

#include "../../SimpleDHT/SimpleDHT.h"

namespace capla
{
namespace sensors
{
    class DHT22 {
    private:
        int pin;
    public:
        DHT22();
        DHT22(int pin);
        int setup();
        int setPin(int pin) { this->pin = pin; };
        int readTemperature(float *temperature);
        int readHumidity(float *humidity);
    };
}
}

#endif