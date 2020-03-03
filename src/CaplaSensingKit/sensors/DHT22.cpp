#include "DHT22.h"
_
#define DEFAULT_PIN 13

namespace capla
{
namespace sensors
{
    DHT22::DHT22() : pin { DEFAULT_PIN } {}
    DHT22::DHT22(int pin) : pin { pin } 

    int DHT22::setup() { }
    int DHT22::readTemperature(float *temperature) { }
    int DHT22::readHumidity(float *humidity) { }
}
}