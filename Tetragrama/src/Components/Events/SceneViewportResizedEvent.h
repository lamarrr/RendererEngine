#pragma once
#include <ZEngine/ZEngine.h>

namespace Tetragrama::Components::Event {

    class SceneViewportResizedEvent : public ZEngine::Components::UI::Event::UIComponentEvent {
    public:
        SceneViewportResizedEvent(float width, float heigth) : m_width(width), m_height(heigth) {}

        EVENT_TYPE(SceneViewportResized)

        float GetWidth() const {
            return m_width;
        }
        float GetHeight() const {
            return m_height;
        }

        virtual ZEngine::Event::EventType GetType() const override {
            return GetStaticType();
        }

        virtual int GetCategory() const override {
            return GetStaticCategory();
        }

    private:
        float m_width;
        float m_height;
    };
} // namespace Tetragrama::Components::Event
