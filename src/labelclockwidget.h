#pragma once

#include "clockwidgetbase.h"

namespace Gtk
{
    class Label;
}

class LabelClockWidget : public ClockWidgetBase
{
public:
    LabelClockWidget();
    ~LabelClockWidget();

    virtual void UpdateWidget(const Clock &clock) override;

protected:
    Gtk::Label *mLabel;
};
