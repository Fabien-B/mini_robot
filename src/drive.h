#pragma once

enum Direction {
    STOP,
    FORWARD,
    BACKWARD,
    FW_LEFT,
    FW_RIGHT,
    BW_LEFT,
    BW_RIGHT,
    LEFT,
    RIGHT,
};

void drive_init();
void drive_cmd(Direction dir);

const int LEFT_NEUTRAL = 92;
const int LEFT_BACKWARD = 0;
const int LEFT_FORWARD = 180;

const int RIGHT_NEUTRAL = 93;
const int RIGHT_BACKWARD = 180;
const int RIGHT_FORWARD = 0;

