#include "src/CaplaSensingKit/CaplaSensingKit.h"
//
//capla::sensors::SoilMoistureSensor sensor;
//
//// Should these be versioned? Or part numbered?
capla::sensors::ChirpSoilMoistureRS485 sensor(2, 4);
//capla::sensors::DHT22 lightAndHumiditySensor;

// capla::sensors::ChirpSoilMoistureRS485;

void setup() { 
  // TODO DE and RE are swapped? 
  sensor.setPinDe(5);
  sensor.setup();
}

void loop() {
  float moisture;
  sensor.readMoisture(&moisture);
  if (moisture > 230) {
    Serial.println("WET!");
  } else {
    Serial.println("Dry...");
  }
  delay(1000);
}

/*
 * I want to:
 *     - Setup all sensors
 *     - Log data out to console to make sure things work
 *     
 *     - Setup all sensors
 *     - Write data to SD card
 *     
 *     - Setup all sensors
 *     - Log to remote file?
 */

 /*
  * 0. Basic arduino things
  * 1. Setup simple sensor (temp and humidity?)
  * 2. Change to using capla::sensors (easier but they know-ish what happens behind the scenes)
  * 3. Exercise with sensor
  * 4. More complex sensor (that analog one)
  * 5. Exercise with sensor
  * 6. Option to split here: Soil moisture sensor OR continue to data logging
  * 7a. Soil Moisture sensor
  * 8a. Exercise with soil moisture sensor (measure different levels of wetness?)
  * 9a. ???
  * 7b. Data logging with console
  * 8b. Data logging with SD card?
  */
