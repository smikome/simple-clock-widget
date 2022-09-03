#pragma once

#include <gtkmm/window.h>

class ClockWidgetBase;

class Window : public Gtk::Window
{
public:
    Window();
    ~Window();

private:
    ClockWidgetBase *mClockWidget;
};
