#pragma once
#include "event_callback.h"

#include <vector>

namespace gitty
{
    class Event
    {
    public:
        Event();
        ~Event();

        void addListener(IEventCallback *action);
        void removeListener(IEventCallback *action);
        void trigger();

    private:
        typedef std::vector<IEventCallback *> CallbackArray;
        CallbackArray actions;
    };
} // namespace gitty
