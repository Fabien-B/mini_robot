#pragma once
#include <inttypes.h>

enum Sensor {
    SENSOR_LEFT,
    SENSOR_RIGHT,
};

void sensors_init();

uint8_t sensor_range(Sensor sensor);
