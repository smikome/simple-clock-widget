#include "labelclockwidget.h"

#include <gtkmm/label.h>
#include "clock.h"

LabelClockWidget::LabelClockWidget()
:mLabel(new Gtk::Label())
{
    int margin = 50;
    mLabel->set_margin_left(margin);
    mLabel->set_margin_right(margin);
    mLabel->set_margin_top(margin);
    mLabel->set_margin_bottom(margin);

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
