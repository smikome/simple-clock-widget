#pragma once

#include <glibmm/ustring.h>

class Clock
{
public:
    Clock();
    ~Clock();
    void Update();
    void Dump();

    Glib::ustring Year() const;
    Glib::ustring Mon() const;
    Glib::ustring Day() const;
    Glib::ustring Hour() const;
    Glib::ustring Min() const;
    Glib::ustring Sec() const;

    // int YearInt() const { return mYear; }
    // int MonInt() const { return mMon; }
    // int DayInt() const { return mDay; }
    // int HourInt() const { return mHour; }
    // int MinInt() const { return mMin; }
    // int SecInt() const { return mSec; }

private:
    int mYear;
    int mMon;
    int mDay;
    int mHour;
    int mMin;
    int mSec;
};
