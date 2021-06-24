#include "debug/log.h"

#include "events/event_dispatcher.h"
#include "events/hotkey_event.h"
#include "events/hotkey.h"

using namespace gitty;

int main(int argc, char const *argv[])
{
    while (1)
    {
        if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_LSHIFT) && VK_A)
        {
            std::cout << "PRESSED HOTKEY" << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
