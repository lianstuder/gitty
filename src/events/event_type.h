#pragma once

namespace gitty
{
    enum class EventType
    {
        None = 0,
        ErrorEvent,
        HotkeyEvent
    };

#define EVENT_TYPE(type)                                              \
    static EventType GetStaticEventType() { return EventType::type; } \
    virtual EventType GetInstanceEventType() const override { return GetStaticEventType(); }

} // namespace gitty
