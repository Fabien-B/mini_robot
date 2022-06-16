#include "drive.h"
#include "params.h"
#include <ESP32Servo.h>

Servo servo_left;
Servo servo_right;


void drive_init() {
  servo_left.attach(SERVO_LEFT);
  servo_right.attach(SERVO_RIGHT);
}

void drive_cmd(Direction dir) {
    switch (dir)
    {
    case STOP:
        servo_left.write(LEFT_NEUTRAL);
        servo_right.write(RIGHT_NEUTRAL);
        break;
    case FORWARD:
        servo_left.write(LEFT_FORWARD);
        servo_right.write(RIGHT_FORWARD);
        break;
    case BACKWARD:
        servo_left.write(LEFT_BACKWARD);
        servo_right.write(RIGHT_BACKWARD);
        break;
    case FW_LEFT:
        servo_left.write(LEFT_NEUTRAL);
        servo_right.write(RIGHT_FORWARD);
        break;
    case FW_RIGHT:
        servo_left.write(LEFT_FORWARD);
        servo_right.write(RIGHT_NEUTRAL);
        break;
    case BW_LEFT:
        servo_left.write(LEFT_NEUTRAL);
        servo_right.write(RIGHT_BACKWARD);
        break;
    case BW_RIGHT:
        servo_left.write(LEFT_BACKWARD);
        servo_right.write(RIGHT_NEUTRAL);
        break;
    case LEFT:
        servo_left.write(LEFT_BACKWARD);
        servo_right.write(RIGHT_FORWARD);
        break;
    case RIGHT:
        servo_left.write(LEFT_FORWARD);
        servo_right.write(RIGHT_BACKWARD);
        break;
    default:
        break;
    }
}