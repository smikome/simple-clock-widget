#pragma once

#include <gtkmm/window.h>

class Clock;
class ClockWidgetBase;

class Window : public Gtk::Window
{
public:
    Window();
    ~Window();

    bool OnTimeOut();

private:
    Clock *mClock;
    ClockWidgetBase *mClockWidget;
};
