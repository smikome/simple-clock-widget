#include "labelclockwidget.h"

#include <gtkmm/label.h>
#include "clock.h"

LabelClockWidget::LabelClockWidget()
:mLabel(new Gtk::Label())
{
    int verticalMargin = 5;
    int horizontalMargin = 10;
    mLabel->set_margin_left(horizontalMargin);
    mLabel->set_margin_right(horizontalMargin);
    mLabel->set_margin_top(verticalMargin);
    mLabel->set_margin_bottom(verticalMargin);
    
    Gdk::RGBA blackColor;
    blackColor.set_rgba(1.0f, 1.0f, 1.0f);
    for(int i = 0; i <= 12; i++)
    {
        // always color
        mLabel->override_color(blackColor, (Gtk::StateFlags)(1 << i));
    }

    add(*mLabel);
    mLabel->show();
}

LabelClockWidget::~LabelClockWidget()
{
    if(mLabel)
    {
        delete mLabel;
        mLabel = nullptr;
    }
}

void LabelClockWidget::UpdateWidget(const Clock &clock)
{
    double fontSize = 50.0;
    Glib::ustring bgColor = "#E0FFFF00";

    mLabel->set_text(Glib::ustring::compose("<span size='%1pt'>%2-%3-%4 %5:%6:%7</span>",
        fontSize, clock.Year(), clock.Mon(), clock.Day(), clock.Hour(), clock.Min(), clock.Sec()));
    mLabel->set_use_markup(true);
}
