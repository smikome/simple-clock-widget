#include "clock.h"

#include <ctime>
#include <iostream>
#include <iomanip>

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

Glib::ustring Clock::Year() const
{
    return Glib::ustring::format(std::setfill(L'0'), std::setw(4), mYear);
}

Glib::ustring Clock::Mon() const
{
    return Glib::ustring::format(std::setfill(L'0'), std::setw(2), mMon);
}

Glib::ustring Clock::Day() const
{
    return Glib::ustring::format(std::setfill(L'0'), std::setw(2), mDay);
}

Glib::ustring Clock::Hour() const
{
    return Glib::ustring::format(std::setfill(L'0'), std::setw(2), mHour);
}

Glib::ustring Clock::Min() const
{
    return Glib::ustring::format(std::setfill(L'0'), std::setw(2), mMin);
}

Glib::ustring Clock::Sec() const
{
    return Glib::ustring::format(std::setfill(L'0'), std::setw(2), mSec);
}
