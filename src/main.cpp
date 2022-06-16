#include <Arduino.h>
#include "params.h"
#include "drive.h"
#include <Wire.h>
#include <VL6180X.h>

VL6180X sensor;


void setup() {

  Serial.begin(115200);

  pinMode(TOF_EN_LEFT, OUTPUT);
  //pinMode(TOF_EN_RIGHT, OUTPUT);

  digitalWrite(TOF_EN_LEFT, LOW);
  //digitalWrite(TOF_EN_RIGHT, LOW);

  for(auto led: LEDS) {
    pinMode(led, OUTPUT);
  }
  drive_init();

  delay(100);
  //digitalWrite(TOF_EN_RIGHT, HIGH);
  
  for(int i=0; i<20; i++) {
    Serial.println(i);
    delay(100);
  }

  Wire.begin();

  #define SYSTEM__FRESH_OUT_OF_RESET 0x016
  Wire.beginTransmission(0x29);
  Wire.write((uint8_t)(SYSTEM__FRESH_OUT_OF_RESET >> 8)); // reg high byte
  Wire.write((uint8_t)(SYSTEM__FRESH_OUT_OF_RESET >> 0)); // reg low byte
  uint8_t i2c_status = Wire.endTransmission();
  Serial.print("1)i2c status:");
  Serial.println(i2c_status);

  delay(1000);

  Wire.beginTransmission(0x29);
  Wire.write((uint8_t)(SYSTEM__FRESH_OUT_OF_RESET >> 8)); // reg high byte
  Wire.write((uint8_t)(SYSTEM__FRESH_OUT_OF_RESET >> 0)); // reg low byte
  i2c_status = Wire.endTransmission();
  Serial.print("2)i2c status:");
  Serial.println(i2c_status);

  i2c_status = Wire.requestFrom(0x29, (uint8_t)1);
  Serial.print("3)i2c status:");
  Serial.println(i2c_status);

  int value = Wire.read();

  //sensor.init();
  //sensor.configureDefault();
  //sensor.stopContinuous();

}

void loop() {
  // for(auto led: LEDS) {
  //   digitalWrite(led, HIGH);
  // }

  // for(auto led: LEDS) {
  //   digitalWrite(led, LOW);
  // }
  
  //uint8_t r = sensor.readRangeSingle();
  
  //Serial.println(r);
  Serial.println("plop");

  delay(1000);
  
  // drive_cmd(Direction::FORWARD);
  // delay(1000);
  // drive_cmd(Direction::FW_LEFT);
  // delay(1000);
  // drive_cmd(Direction::FW_RIGHT);
  // delay(1000);

  // drive_cmd(Direction::STOP);
  // delay(1000);

  // drive_cmd(Direction::BACKWARD);
  // delay(1000);
  // drive_cmd(Direction::BW_LEFT);
  // delay(1000);
  // drive_cmd(Direction::BW_RIGHT);
  // delay(1000);


}
