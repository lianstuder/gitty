#include <iostream>
#include "events/event_callback.h"
#include "events/event.h"

class Lit
{
public:
    inline void hello()
    {
        std::cout << "Hello" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Lit *lit = new Lit();
    using namespace gitty;

    EventCallback<Lit> *callback = new EventCallback(lit, &Lit::hello);
    Event *e = new Event();
    e->addListener(callback);
    e->trigger();
    return EXIT_SUCCESS;
}
