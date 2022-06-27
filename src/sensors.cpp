#include "sensors.h"
#include "params.h"
#include <Wire.h>
#include <VL6180X.h>

VL6180X sensor_left;
VL6180X sensor_right;

void sensors_init() {
  pinMode(TOF_EN_LEFT, OUTPUT);
  pinMode(TOF_EN_RIGHT, OUTPUT);

  digitalWrite(TOF_EN_LEFT, LOW);
  digitalWrite(TOF_EN_RIGHT, LOW);
  delay(50);

  Wire.begin(21, 22);

  digitalWrite(TOF_EN_LEFT, HIGH);
  delay(100);
  sensor_left.init();
  sensor_left.configureDefault();
  sensor_left.stopContinuous();
  sensor_left.setAddress(0x30);


  digitalWrite(TOF_EN_RIGHT, HIGH);
  delay(100);
  sensor_right.init();
  sensor_right.configureDefault();
  sensor_right.stopContinuous();
  sensor_right.setAddress(0x31);

}

uint8_t sensor_range(Sensor sensor) {
  uint8_t r = 255;
  switch (sensor)
  {
  case Sensor::SENSOR_LEFT:
    r = sensor_left.readRangeSingle();
    break;
  case Sensor::SENSOR_RIGHT:
    r = sensor_right.readRangeSingle();
    break;
  }
  return r;
}