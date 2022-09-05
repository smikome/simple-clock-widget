#include "labelclockwidget.h"

#include <gtkmm/label.h>
#include "clock.h"

LabelClockWidget::LabelClockWidget()
:mLabel(new Gtk::Label())
{
    int margin = 0;
    mLabel->set_margin_left(margin);
    mLabel->set_margin_right(margin);
    mLabel->set_margin_top(margin);
    mLabel->set_margin_bottom(margin);
    
    Gdk::RGBA blackColor;
    blackColor.set_rgba(0.0f, 0.0f, 0.0f);
    for(int i = 0; i <= 12; i++)
    {
        // always black
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
    Glib::ustring bgColor = "#E0FFFF";

    mLabel->set_text(Glib::ustring::compose("<span size='%1pt' bgcolor='%2'>%3-%4-%5 %6:%7:%8</span>",
        fontSize, bgColor, clock.Year(), clock.Mon(), clock.Day(), clock.Hour(), clock.Min(), clock.Sec()));
    mLabel->set_use_markup(true);
}
