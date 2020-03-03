#include "SoilMoisture.h"
#include "../../ModbusMaster/ModbusMaster.h"

#define DEFAULT_PIN_MAX485_RE   2
#define DEFAULT_PIN_MAX485_DE   3
#define DEFAULT_MAX485_BAUDRATE 19200
#define DEFAULT_MAX485_PARITY   SERIAL_8N2

namespace capla
{
namespace sensors
{
    ChirpSoilMoistureRS485::ChirpSoilMoistureRS485()
        : pinRe { DEFAULT_PIN_MAX485_RE },
        pinDe { DEFAULT_PIN_MAX485_DE },
        baudrate { DEFAULT_MAX485_BAUDRATE },
        parity { DEFAULT_MAX485_PARITY }
    {
    }

    ChirpSoilMoistureRS485::ChirpSoilMoistureRS485(int pinDe=DEFAULT_PIN_MAX485_DE, int pinRe=DEFAULT_PIN_MAX485_RE)
        : pinRe { pinRe },
        pinDe { pinDe },
        baudrate { DEFAULT_MAX485_BAUDRATE },
        parity { DEFAULT_MAX485_PARITY }
    {
    }

    int ChirpSoilMoistureRS485::setup()
    {
        // Set pins
        pinMode(this->pinRe, OUTPUT);
        pinMode(this->pinDe, OUTPUT);

        // Init in receive mode
        digitalWrite(this->pinRe, 0);
        digitalWrite(this->pinDe, 0);
        Serial1.begin(this->baudrate, this->parity);
        node.begin(1, Serial1);

        // Callbacks
        node.preTransmission([](void* arg){
            auto *sensor = (ChirpSoilMoistureRS485*)arg;
            digitalWrite(sensor->pinRe, 1);
            digitalWrite(sensor->pinDe, 1);
        }, this);
        node.postTransmission([](void* arg){
            auto *sensor = (ChirpSoilMoistureRS485*)arg;
            digitalWrite(sensor->pinRe, 0);
            digitalWrite(sensor->pinDe, 0);
        }, this);
        // TODO error handling
    }

    int ChirpSoilMoistureRS485::readTemperature(float *temperature)
    {
        uint8_t result;
        uint16_t data[6];
        result = node.readInputRegisters(0x00, 2);
        if (result == node.ku8MBSuccess)
        {
            *temperature = node.getResponseBuffer(0x01) / 10.0;
            // TODO do these values need conversion?
            // TODO error handling
        }
    }

    int ChirpSoilMoistureRS485::readMoisture(float *moisture)
    {
        uint8_t result;
        uint16_t data[6];
        result = node.readInputRegisters(0x00, 2);
        if (result == node.ku8MBSuccess)
        {
            *moisture = node.getResponseBuffer(0x00);
            // TODO do these values need conversion
            // TODO error handling
        }
    }
}
}