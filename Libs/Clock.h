#pragma once

class Clock {
private:
    float speedOfTimePerFrame;
public:
    Clock(float timeSpeed);
    float getTimeSpeed();
    void setTimeSpeed(float timeSpeed);
};