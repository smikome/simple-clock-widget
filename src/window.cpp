#include "window.h"

#include "clock.h"
#include "labelclockwidget.h"

Window::Window()
{
    mClockWidget = new LabelClockWidget();
    add(*mClockWidget);
    mClockWidget->show();
    Clock clock;
    clock.Update();
    mClockWidget->UpdateWidget(clock);
}

Window::~Window()
{
    if(mClockWidget)
    {
        delete mClockWidget;
        mClockWidget = nullptr;
    }
}
