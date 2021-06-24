#pragma once
#include "event.h"
#include "event_type.h"
#include "hotkey.h"

namespace gitty
{
    class HotkeyEvent : public Event
    {
    public:
        EVENT_TYPE(HotkeyEvent);

        Hotkey GetHotkey() const { return hotkey_; }
        HotkeyEvent(const Hotkey hotkey) : hotkey_(hotkey) {}

    private:
        Hotkey hotkey_;
    };

} // namespace gitty
