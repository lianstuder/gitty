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

    class Event
    {
    public:
        virtual EventType GetInstanceEventType() const = 0;
        virtual ~Event() = default;
    };

    class EventDispatcher
    {
    public:
        EventDispatcher(Event *event) : event_(event) {}

        template <typename E>
        bool DispatchEvent(bool (*func)(E *));

        template <typename E>
        bool DispatchEvent(void (*func)(E *));

    private:
        Event *event_;
    };

} // namespace gitty
