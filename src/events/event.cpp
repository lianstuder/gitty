#include "event.h"
#include "../debug/log.h"

namespace gitty
{
    Event::Event() {}
    Event::~Event() {}

    void Event::addListener(IEventCallback *action)
    {
        CallbackArray::iterator position = find(actions.begin(), actions.end(), action);

        if (position != actions.end())
        {
            GT_LOG_WARNING("Action existed in delegate list.");
            return;
        }

        actions.push_back(action);
    }

    void Event::removeListener(IEventCallback *action)
    {
        CallbackArray::iterator position = find(actions.begin(), actions.end(), action);

        if (position == actions.end())
        {
            return;
        }

        actions.erase(position);
    }

    void Event::trigger()
    {
        for (IEventCallback *action : actions)
        {
            (*action)();
        }
    }
} // namespace gitty