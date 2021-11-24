#include <pch.h>
#include <Rendering/Materials/StandardMaterial.h>

namespace ZEngine::Rendering::Materials {

    StandardMaterial::StandardMaterial()
        :
#ifdef _WIN32
          ShaderMaterial("Resources/Windows/Shaders/standard_shader.glsl"),
#else
          ShaderMaterial("Resources/Unix/Shaders/standard_shader.glsl"),
#endif
          m_tile_factor(1.0f),
          m_tint_color(glm::vec4(1.0f)) {
        m_material_name = typeid(*this).name();
    }

    unsigned int StandardMaterial::GetHashCode() {
        auto hash = static_cast<unsigned int>(m_tile_factor) ^ static_cast<unsigned int>(m_tint_color.x) ^ static_cast<unsigned int>(m_tint_color.y)
                  ^ static_cast<unsigned int>(m_tint_color.z);

        return hash ^ ShaderMaterial::GetHashCode();
    }

    void StandardMaterial::SetTileFactor(float value) {
        m_tile_factor = value;
    }

    void StandardMaterial::SetTintColor(const glm::vec4& value) {
        m_tint_color = value;
    }

    void StandardMaterial::Apply() {
        m_shader->SetUniform("material.tiling_factor", m_tile_factor);
        m_shader->SetUniform("material.tint_color", m_tint_color);
        m_texture->Bind();
    }
} // namespace ZEngine::Rendering::Materials
