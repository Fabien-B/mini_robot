#include <Arduino.h>
#include "params.h"
#include "drive.h"
#include "sensors.h"


void setup() {

  Serial.begin(115200);



  for(auto led: LEDS) {
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
  }

  drive_init();
  sensors_init();

}

void loop() {

  uint8_t rl = sensor_range(Sensor::SENSOR_LEFT);
  bool dl = rl < 45 || rl == 255;
  digitalWrite(LED_FRONT_LEFT, rl < 45);
  digitalWrite(LED_REAR_LEFT, rl == 255);

  uint8_t rr = sensor_range(Sensor::SENSOR_RIGHT);
  bool dr = rr < 45 || rr == 255;
  digitalWrite(LED_FRONT_RIGHT, rr < 45);
  digitalWrite(LED_REAR_RIGHT, rr == 255);


  if(dl && dr) {
    drive_cmd(Direction::LEFT);
  } else if (dl) {
    drive_cmd(Direction::FW_RIGHT);
  } else if(dr) {
    drive_cmd(Direction::FW_LEFT);
  } else {
    drive_cmd(Direction::FORWARD);
  }

  delay(100);
  
}
