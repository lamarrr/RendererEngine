#pragma once
#include <glad/include/glad/glad.h>

namespace ZEngine::Core {

    struct IGraphicObject {

        virtual GLuint GetIdentifier() const = 0;
    };
} // namespace ZEngine::Core
