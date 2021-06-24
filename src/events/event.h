#pragma once
#include "event_type.h"

namespace gitty
{
    class Event
    {
    public:
        virtual EventType GetInstanceEventType() const = 0;
        virtual ~Event() = default;
    };
} // namespace gitty
