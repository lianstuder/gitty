#include "event.h"

namespace gitty
{
    template <typename E>
    bool EventDispatcher::DispatchEvent(bool (*func)(E *))
    {
        if ((*event_).GetInstanceEventType() == E::GetStaticEventType())
            return func((E *)event_);
        return false;
    }

    template <typename E>
    bool EventDispatcher::DispatchEvent(void (*func)(E *))
    {
        if ((*event_).GetInstanceEventType() == E::GetStaticEventType())
        {
            func((E *)event_);
            return true;
        }
        return false;
    }
} // namespace gitty
