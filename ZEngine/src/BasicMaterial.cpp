#include <pch.h>
#include <Rendering/Materials/BasicMaterial.h>

namespace ZEngine::Rendering::Materials {

    BasicMaterial::BasicMaterial() : ShaderMaterial(Shaders::ShaderBuiltInType::BASIC) {
        m_material_name = typeid(*this).name();
        m_texture.reset(Textures::CreateTexture(1, 1));
    }

    void BasicMaterial::Apply(Shaders::Shader* const shader) {
        ShaderMaterial::Apply(shader);
        m_texture->Bind();
    }
} // namespace ZEngine::Rendering::Materials
