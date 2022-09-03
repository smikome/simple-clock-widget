#pragma once

#include <gtkmm/frame.h>

class Clock;

class ClockWidgetBase : public Gtk::Frame
{
public:
    ClockWidgetBase();
    ~ClockWidgetBase();

    virtual void UpdateWidget(const Clock &clock) = 0;
};
