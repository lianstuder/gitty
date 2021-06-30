#pragma once
#include "event.h"

namespace gitty
{
    enum class Hotkey
    {
        None = 0
    };

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
