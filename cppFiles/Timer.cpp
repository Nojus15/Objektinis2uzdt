#include "../headers/Timer.h"

Timer::Timer() : timeElapsed(0) {}
Timer::~Timer() {}
void Timer::Start()
{
    Start_point = hrClock::now();
    timeElapsed = 0;
}
void Timer::Stop()
{
    timeElapsed += durationDouble(hrClock::now() - Start_point).count();
}
void Timer::Continue()
{
    Start_point = hrClock::now();
}
double Timer::returnTime()
{
    return timeElapsed;
}
double Timer::Stop_Return()
{
    Stop();
    return returnTime();
}