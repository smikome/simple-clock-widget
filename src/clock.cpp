#include "clock.h"

// #include <chrono>
#include <ctime>
#include <iostream>

Clock::Clock()
{
    Update();
}

Clock::~Clock()
{
}

void Clock::Update()
{
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);
    mYear = now->tm_year + 1900;
    mMon = now->tm_mon + 1;
    mDay = now->tm_mday;
    mHour = now->tm_hour;
    mMin = now->tm_min;
    mSec = now->tm_sec;
}

void Clock::Dump()
{
    std::cout << "CurrentDate: " 
        << mYear << "/" << mMon << "/" << mDay << " "
        << mHour << ":" << mMin << ":" << mSec << std::endl;
}
