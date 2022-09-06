#include <window.h>
#include <gtkmm/application.h>
#include <clock.h>
#include <thread>

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "smikome.simpleclockwidget");
    Window window;
    return app->run(window);
}
