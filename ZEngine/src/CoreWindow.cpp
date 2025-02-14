#include <pch.h>
#include <Window/CoreWindow.h>
#include <ZEngineDef.h>

#ifdef ZENGINE_WINDOW_SDL
#include <Window/SDLWin/OpenGLWindow.h>
#else
#include <Window/GlfwWindow/OpenGLWindow.h>
#endif

using namespace ZEngine;
using namespace ZEngine::Event;
using namespace ZEngine::Layers;

namespace ZEngine::Window {
    const char* CoreWindow::ATTACHED_PROPERTY = "WINDOW_ATTACHED_PROPERTY";

    CoreWindow::CoreWindow() : m_layer_stack_ptr(new LayerStack()) {}

    void CoreWindow::SetAttachedEngine(Engine* const engine) {
        m_engine = engine;
    }

    void CoreWindow::PushOverlayLayer(const Ref<Layer>& layer) {
        m_layer_stack_ptr->PushOverlayLayer(layer);
    }

    void CoreWindow::PushLayer(const Ref<Layer>& layer) {
        m_layer_stack_ptr->PushLayer(layer);
    }

    void CoreWindow::PushOverlayLayer(Ref<Layer>&& layer) {
        m_layer_stack_ptr->PushOverlayLayer(layer);
    }

    void CoreWindow::PushLayer(Ref<Layer>&& layer) {
        m_layer_stack_ptr->PushLayer(layer);
    }

    void CoreWindow::ForwardEventToLayers(CoreEvent& event) {
        for (auto it = m_layer_stack_ptr->rbegin(); it != m_layer_stack_ptr->rend(); ++it) {
            if (event.IsHandled()) {
                break;
            }
            it->get()->OnEvent(event);
        }
    }

    CoreWindow* Create(WindowProperty prop) {
        auto core_window = new ZENGINE_OPENGL_WINDOW(prop);
        core_window->SetCallbackFunction(std::bind(&CoreWindow::OnEvent, core_window, std::placeholders::_1));
        return core_window;
    }

} // namespace ZEngine::Window
