#ifndef SoilMoisture_h
#define SoilMoisture_h

#include "../../ModbusMaster/ModbusMaster.h"

namespace capla
{
namespace sensors
{
    class ChirpSoilMoistureRS485 {
    private:
        int pinRe;
        int pinDe;
        int baudrate;
        int parity;
        ModbusMaster node;
    public:
        ChirpSoilMoistureRS485();
        ChirpSoilMoistureRS485(int pinDe, int pinRe);
        int setup();
        int setPinDe(int pin) { pinDe = pin;// Error handling? };
        int setPinRe(int pin) { pinRe = pin;// Error handling? };
        int readTemperature(float *temperature);
        int readMoisture(float *moisture);
    };
}
}

namespace capla
{
namespace sensors
{
    class DHT22 {
    private:
        int pin;
    public:
        DHT22();
        DHT22(int pin, int pinRe);
        int setup();
        int setPin(int pin) { pin = pin; };
        int readTemperature(float *temperature);
        int readHumidity(float *humidity);
    };
}
}

#endif