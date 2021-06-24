#pragma once
#include "event.h"
#include "event_type.h"

namespace gitty
{
    class EventDispatcher
    {
    public:
        EventDispatcher(Event *event) : event_(event) {}

        template <typename E>
        bool DispatchEvent(bool (*func)(E *))
        {
            if ((*event_).GetInstanceEventType() == E::GetStaticEventType())
                return func((E *)event_);
            return false;
        }

        template <typename E>
        bool DispatchEvent(void (*func)(E *))
        {
            if ((*event_).GetInstanceEventType() == E::GetStaticEventType())
            {
                func((E *)event_);
                return true;
            }
            return false;
        }

    private:
        Event *event_;
    };
} // namespace gitty
