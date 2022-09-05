#pragma once

#include <gtkmm/bin.h>

class Clock;

class ClockWidgetBase : public Gtk::Bin
{
public:
    ClockWidgetBase();
    ~ClockWidgetBase();

    virtual void UpdateWidget(const Clock &clock) = 0;
};
