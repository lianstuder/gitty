#pragma once

namespace gitty
{
    class IEventCallback
    {
    public:
        virtual void operator()() = 0;
        // virtual bool operator==(IEventCallback *other) = 0;
    };

    template <typename T>
    class EventCallback : public IEventCallback
    {
    public:
        EventCallback(T *instance, void (T::*function)())
            : instance(instance), function(function) {}
        virtual void operator()() override { (instance->*function)(); }
        // virtual bool operator==(IEventCallback *other) override
        // {
        //     EventCallback *otherEventCallback = dynamic_cast<EventCallback>(other);
        //     if (otherEventCallback == nullptr)
        //         return false;

        //     return (this->function == otherEventCallback->function) &&
        //            (this->instance == otherEventCallback->instance);
        // }

    private:
        void (T::*function)();
        T *instance;
    };
} // namespace gitty
