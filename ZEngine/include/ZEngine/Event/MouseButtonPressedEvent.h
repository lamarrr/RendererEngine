#pragma once

#include <fmt/format.h>
#include <Event/MouseEvent.h>
#include <Inputs/KeyCode.h>

namespace ZEngine::Event {

#ifdef ZENGINE_WINDOW_SDL
    class MouseButtonPressedEvent : public MouseEvent {
    public:
        MouseButtonPressedEvent(unsigned char button) : MouseEvent(button) {}

        EVENT_TYPE(MouseButtonPressed)

        virtual EventType GetType() const override {
            return GetStaticType();
        }

        virtual int GetCategory() const override {
            return GetStaticCategory();
        }

        virtual std::string ToString() const override {
            return fmt::format("MouseButtonPressedEvent : {0}", m_button);
        }
    };
#else
    class MouseButtonPressedEvent : public MouseEvent {
    public:
        MouseButtonPressedEvent(ZENGINE_KEYCODE button) : MouseEvent(button) {}

        EVENT_TYPE(MouseButtonPressed)

        virtual EventType GetType() const override {
            return GetStaticType();
        }

        virtual int GetCategory() const override {
            return GetStaticCategory();
        }

        virtual std::string ToString() const override {
            return fmt::format("MouseButtonPressedEvent : {0}", m_button);
        }
    };
#endif
} // namespace ZEngine::Event
