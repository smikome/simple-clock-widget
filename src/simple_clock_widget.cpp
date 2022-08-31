#include <window.h>
#include <clock.h>
#include <thread>

int main(int argc, char *argv[])
{
    Clock clock;
    for(int i = 0; i < 10; i++)
    {
        sleep(1);
        clock.Update();
        clock.Dump();
    }
    return 0;
    auto app = Gtk::Application::create(argc, argv, "smikome.simpleclockwidget");

    Window window;
    app->run(window);

    return 0;
}