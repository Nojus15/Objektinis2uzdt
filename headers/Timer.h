#pragma once

#include <chrono>
#include <iostream>

using timePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
using durationDouble = std::chrono::duration<double>;

using hrClock = std::chrono::high_resolution_clock;

class Timer
{
private:
    timePoint Start_point;
    double timeElapsed;

public:
    Timer();
    ~Timer();
    void Start();
    void Stop();
    void Continue();
    double returnTime();
    double Stop_Return();
};