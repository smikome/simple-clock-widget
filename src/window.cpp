#include "window.h"

#include <glibmm/main.h>
#include <gtkmm/eventbox.h>
#include "clock.h"
#include "labelclockwidget.h"

Window::Window()
:mUpdateInterval(200)
{
    set_app_paintable(true);
    set_decorated(false);

    mEventBox = new Gtk::EventBox();
    mEventBox->set_events(Gdk::EventMask::BUTTON_PRESS_MASK | Gdk::EventMask::BUTTON_RELEASE_MASK | Gdk::EventMask::BUTTON_MOTION_MASK);
    mEventBox->signal_button_press_event().connect(sigc::mem_fun(*this, &Window::OnPress));
    mEventBox->signal_button_release_event().connect(sigc::mem_fun(*this, &Window::OnRelease));
    mEventBox->signal_motion_notify_event().connect(sigc::mem_fun(*this, &Window::OnMotionNotify));
    add(*mEventBox);
    mEventBox->show();

    mClock = new Clock();
    mClockWidget = new LabelClockWidget();
    mEventBox->add(*mClockWidget);
    mClockWidget->show();
    mClock->Update();
    mClockWidget->UpdateWidget(*mClock);
    unsigned int updateInterval = 100;
    Glib::signal_timeout().connect(sigc::mem_fun(*this, &Window::UpdateWindow), updateInterval);
    Glib::signal_timeout().connect_once(sigc::mem_fun(*this, &Window::OnAppStarted), 0);
    signal_draw().connect(sigc::mem_fun(*this, &Window::OnDraw));
    GdkVisual *visual = gdk_screen_get_rgba_visual(get_screen()->gobj());
    gtk_widget_set_visual(Gtk::Widget::gobj(), visual);
}

Window::~Window()
{
    if(mClock)
    {
        delete mClock;
        mClock = nullptr;
    }
    if(mClockWidget)
    {
        delete mClockWidget;
        mClockWidget = nullptr;
    }
}

bool Window::UpdateWindow()
{
    mClock->Update();
    mClockWidget->UpdateWidget(*mClock);
    return true;
}

void Window::OnAppStarted()
{
    set_keep_above(true);
}

bool Window::OnPress(GdkEventButton *eventButton)
{
    return true;
}

bool Window::OnRelease(GdkEventButton *eventButton)
{
    return true;
}

bool Window::OnMotionNotify(GdkEventMotion *eventMotion)
{
    int width = get_width();
    int height = get_height();
    int x = eventMotion->x_root - (width / 2);
    int y = eventMotion->y_root - (height / 2);
    move(x, y);
    return true;
}

bool Window::OnDraw(const Cairo::RefPtr<Cairo::Context> &cr)
{
    cr->set_source_rgba(1.0, 1.0, 1.0, 0.0);
    cr->set_operator(Cairo::Operator::OPERATOR_SOURCE);
    cr->paint();
    cr->set_operator(Cairo::Operator::OPERATOR_OVER);

    return on_draw(cr);
}
