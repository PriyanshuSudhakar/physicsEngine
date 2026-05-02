#include "Libs/Clock.h"

Clock::Clock(float timeSpeed) {
    this->speedOfTimePerFrame = timeSpeed;
}

float Clock::getTimeSpeed() {
    return this->speedOfTimePerFrame;
}

void Clock::setTimeSpeed(float timeSpeed) {
    this->speedOfTimePerFrame = timeSpeed;
}