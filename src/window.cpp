#include "window.h"

#include <glibmm/main.h>
#include "clock.h"
#include "labelclockwidget.h"

Window::Window()
{
    mClock = new Clock();
    mClockWidget = new LabelClockWidget();
    add(*mClockWidget);
    mClockWidget->show();
    mClock->Update();
    mClockWidget->UpdateWidget(*mClock);
    unsigned int updateInterval = 100;
    Glib::signal_timeout().connect(sigc::mem_fun(*this, &Window::OnTimeOut), updateInterval);
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

bool Window::OnTimeOut()
{
    mClock->Update();
    mClockWidget->UpdateWidget(*mClock);
    return true;
}
