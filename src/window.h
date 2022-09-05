#pragma once

#include <gtkmm/window.h>

class Clock;
class ClockWidgetBase;
namespace Gtk
{
    class EventBox;
}

class Window : public Gtk::Window
{
public:
    Window();
    ~Window();

    bool UpdateWindow();
    void OnAppStarted();
    bool OnPress(GdkEventButton *eventButton);
    bool OnRelease(GdkEventButton *eventButton);
    bool OnMotionNotify(GdkEventMotion *eventMotion);
    bool OnDraw(const Cairo::RefPtr<Cairo::Context> &cr);

private:
    Clock *mClock;
    ClockWidgetBase *mClockWidget;
    Gtk::EventBox *mEventBox;
    const unsigned int mUpdateInterval;
};
