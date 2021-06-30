#include "debug/log.h"

#include "events/event.h"
#include "events/hotkey_event.h"

using namespace gitty;

int main(int argc, char const *argv[])
{
    bool quit = false;

    while (!quit)
    {
        std::cout << "Hello World!" << std::endl;
        quit = true;
    }

    return EXIT_SUCCESS;
}
