#include <pch.h>
#include <Rendering/Meshes/MeshBuilder.h>
#include <Rendering/Geometries/QuadGeometry.h>
#include <Rendering/Geometries/SquareGeometry.h>
#include <Rendering/Geometries/CubeGeometry.h>
#include <Rendering/Materials/BasicMaterial.h>
#include <Rendering/Materials/StandardMaterial.h>

using namespace ZEngine::Maths;
using namespace ZEngine::Rendering::Lights;
using namespace ZEngine::Rendering::Textures;
using namespace ZEngine::Rendering::Geometries;
using namespace ZEngine::Rendering::Materials;

namespace ZEngine::Rendering::Meshes {

    Mesh* MeshBuilder::CreateQuad(const Vector2& position, const Vector2& size, float angle) {
        Mesh*             mesh          = new Mesh{};
        QuadGeometry*     quad_geometry = new QuadGeometry({position.x, position.y, 0.0f}, {size.x, size.y, 0.0f}, Vector3(0.0f, 0.0f, 1.0f), angle);
        Texture*          texture       = CreateTexture(1, 1);
        StandardMaterial* material      = new StandardMaterial{};

        material->SetTexture(texture);

        mesh->SetGeometry(quad_geometry);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateQuad(const Vector2& position, const Vector2& size, const Vector3& color, float angle) {
        Mesh*             mesh     = CreateQuad(position, size, angle);
        Texture*          texture  = CreateTexture(1, 1);
        StandardMaterial* material = new StandardMaterial{};

        texture->SetData(color.x, color.y, color.z, 255.0f);
        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateQuad(const Vector2& position, const Vector2& size, const Vector4& color, float angle) {
        Mesh*             mesh     = CreateQuad(position, size, angle);
        Texture*          texture  = CreateTexture(1, 1);
        StandardMaterial* material = new StandardMaterial{};

        texture->SetData(color.x, color.y, color.z, color.w);
        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateQuad(const Vector2& position, const Vector2& size, float angle, Texture2D* const texture) {
        Texture* internal_texture = dynamic_cast<Texture*>(texture);
        return CreateQuad(position, size, angle, internal_texture);
    }

    Mesh* MeshBuilder::CreateQuad(const Vector2& position, const Vector2& size, float angle, Texture* const texture) {
        Mesh*             mesh     = CreateQuad(position, size, angle);
        StandardMaterial* material = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateQuad(const Vector2& position, const Vector2& size, float angle, const Ref<Texture2D>& texture) {
        auto internal_texture = std::dynamic_pointer_cast<Texture>(texture);
        assert(texture != nullptr);
        return CreateQuad(position, size, angle, internal_texture);
    }

    Mesh* MeshBuilder::CreateQuad(const Vector2& position, const Vector2& size, float angle, const Ref<Texture>& texture) {
        Mesh*             mesh     = CreateQuad(position, size, angle);
        StandardMaterial* material = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateQuad(const Vector3& position, const Vector2& size, float angle) {
        Mesh*         mesh          = new Mesh{};
        QuadGeometry* quad_geometry = new QuadGeometry(position, {size.x, size.y, 0.0f}, Vector3(0.0f, 0.0f, 1.0f), angle);

        mesh->SetGeometry(quad_geometry);
        return mesh;
    }

    Mesh* MeshBuilder::CreateQuad(const Vector3& position, const Vector2& size, const Vector3& color, float angle) {
        Mesh*             mesh     = CreateQuad(position, size, angle);
        Texture*          texture  = CreateTexture(1, 1);
        StandardMaterial* material = new StandardMaterial{};

        texture->SetData(color.x, color.y, color.z, 255.f);
        material->SetTexture(texture);
        mesh->SetMaterial(material);

        return mesh;
    }

    Mesh* MeshBuilder::CreateQuad(const Vector3& position, const Vector2& size, const Vector4& color, float angle) {
        Mesh*             mesh     = CreateQuad(position, size, angle);
        Texture*          texture  = CreateTexture(1, 1);
        StandardMaterial* material = new StandardMaterial{};

        texture->SetData(color.x, color.y, color.z, color.w);
        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateQuad(const Vector3& position, const Vector2& size, float angle, Texture2D* const texture) {
        Texture* internal_texture = dynamic_cast<Texture*>(texture);
        return CreateQuad(position, size, angle, internal_texture);
    }

    Mesh* MeshBuilder::CreateQuad(const Vector3& position, const Vector2& size, float angle, Texture* const texture) {
        Mesh*             mesh     = CreateQuad(position, size, angle);
        StandardMaterial* material = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateQuad(const Vector3& position, const Vector2& size, float angle, const Ref<Rendering::Textures::Texture2D>& texture) {
        auto internal_texture = std::dynamic_pointer_cast<Texture>(texture);
        assert(texture != nullptr);
        return CreateQuad(position, size, angle, internal_texture);
    }

    Mesh* MeshBuilder::CreateQuad(const Vector3& position, const Vector2& size, float angle, const Ref<Rendering::Textures::Texture>& texture) {
        Mesh*             mesh     = CreateQuad(position, size, angle);
        StandardMaterial* material = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateQuad(const Vector2& position, const Vector2& size, float angle, ShaderMaterial* const material) {
        Mesh* mesh = CreateQuad(position, size, angle);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateQuad(const Vector3& position, const Vector2& size, float angle, ShaderMaterial* const material) {
        Mesh* mesh = CreateQuad(position, size, angle);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateQuad(const Vector2& position, const Vector2& size, float angle, const Ref<ShaderMaterial>& material) {
        Mesh* mesh = CreateQuad(position, size, angle);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateQuad(const Vector3& position, const Vector2& size, float angle, const Ref<ShaderMaterial>& material) {
        Mesh* mesh = CreateQuad(position, size, angle);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector2& position, const Vector2& size, float angle) {
        Mesh*             mesh          = new Mesh{};
        SquareGeometry*   quad_geometry = new SquareGeometry({position.x, position.y, 0.0f}, {size.x, size.y, 0.0f}, Vector3(0.0f, 0.0f, 1.0f), angle);
        Texture*          texture       = CreateTexture(1, 1);
        StandardMaterial* material      = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetGeometry(quad_geometry);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector2& position, const Vector2& size, const Vector3& color, float angle) {
        Mesh*             mesh     = CreateSquare(position, size, angle);
        Texture*          texture  = CreateTexture(1, 1);
        StandardMaterial* material = new StandardMaterial{};

        texture->SetData(color.x, color.y, color.z, 255.0f);
        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector2& position, const Vector2& size, const Vector4& color, float angle) {
        Mesh*             mesh     = CreateSquare(position, size, angle);
        Texture*          texture  = CreateTexture(1, 1);
        StandardMaterial* material = new StandardMaterial{};

        texture->SetData(color.x, color.y, color.z, color.w);
        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector2& position, const Vector2& size, float angle, Texture2D* const texture) {
        Texture* internal_texture = dynamic_cast<Texture*>(texture);
        return CreateSquare(position, size, angle, internal_texture);
    }

    Mesh* MeshBuilder::CreateSquare(const Vector2& position, const Vector2& size, float angle, Texture* const texture) {
        Mesh*             mesh     = CreateSquare(position, size, angle);
        StandardMaterial* material = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector2& position, const Vector2& size, float angle, const Ref<Texture2D>& texture) {
        auto internal_texture = std::dynamic_pointer_cast<Texture>(texture);
        assert(texture != nullptr);
        return CreateSquare(position, size, angle, internal_texture);
    }

    Mesh* MeshBuilder::CreateSquare(const Vector2& position, const Vector2& size, float angle, const Ref<Texture>& texture) {
        Mesh*             mesh     = CreateSquare(position, size, angle);
        StandardMaterial* material = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector3& position, const Vector2& size, float angle) {
        Mesh*           mesh          = new Mesh{};
        SquareGeometry* quad_geometry = new SquareGeometry(position, {size.x, size.y, 0.0f}, Vector3(0.0f, 0.0f, 1.0f), angle);

        mesh->SetGeometry(quad_geometry);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector3& position, const Vector2& size, const Vector3& color, float angle) {
        Mesh*             mesh     = CreateSquare(position, size, angle);
        Texture*          texture  = CreateTexture(1, 1);
        StandardMaterial* material = new StandardMaterial{};

        texture->SetData(color.x, color.y, color.z, 255.f);
        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector3& position, const Vector2& size, const Vector4& color, float angle) {
        Mesh*             mesh     = CreateSquare(position, size, angle);
        Texture*          texture  = CreateTexture(1, 1);
        StandardMaterial* material = new StandardMaterial{};

        texture->SetData(color.x, color.y, color.z, color.w);
        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector3& position, const Vector2& size, float angle, Texture2D* const texture) {
        Texture* internal_texture = dynamic_cast<Texture*>(texture);
        return CreateSquare(position, size, angle, internal_texture);
    }

    Mesh* MeshBuilder::CreateSquare(const Vector3& position, const Vector2& size, float angle, Texture* const texture) {
        Mesh*             mesh     = CreateSquare(position, size, angle);
        StandardMaterial* material = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector3& position, const Vector2& size, float angle, const Ref<Rendering::Textures::Texture2D>& texture) {
        auto internal_texture = std::dynamic_pointer_cast<Texture>(texture);
        assert(texture != nullptr);
        return CreateSquare(position, size, angle, internal_texture);
    }

    Mesh* MeshBuilder::CreateSquare(const Vector3& position, const Vector2& size, float angle, const Ref<Rendering::Textures::Texture>& texture) {
        Mesh*             mesh     = CreateSquare(position, size, angle);
        StandardMaterial* material = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector2& position, const Vector2& size, float angle, ShaderMaterial* const material) {
        Mesh* mesh = CreateSquare(position, size, angle);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector3& position, const Vector2& size, float angle, ShaderMaterial* const material) {
        Mesh* mesh = CreateSquare(position, size, angle);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector2& position, const Vector2& size, float angle, const Ref<ShaderMaterial>& material) {
        Mesh* mesh = CreateSquare(position, size, angle);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateSquare(const Vector3& position, const Vector2& size, float angle, const Ref<ShaderMaterial>& material) {
        Mesh* mesh = CreateSquare(position, size, angle);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector2& position, const Vector3& size, float angle, const Vector3& axis) {
        Mesh*             mesh          = new Mesh{};
        CubeGeometry*     quad_geometry = new CubeGeometry({position.x, position.y, 0.0f}, size, axis, angle);
        Texture*          texture       = CreateTexture(1, 1);
        StandardMaterial* material      = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetGeometry(quad_geometry);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector2& position, const Vector3& size, const Vector3& color, float angle, const Vector3& axis) {
        Mesh*             mesh     = CreateCube(position, size, angle, axis);
        Texture*          texture  = CreateTexture(1, 1);
        StandardMaterial* material = new StandardMaterial{};

        texture->SetData(color.x, color.y, color.z, 255.0f);
        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector2& position, const Vector3& size, const Vector4& color, float angle, const Vector3& axis) {
        Mesh*             mesh     = CreateCube(position, size, angle, axis);
        Texture*          texture  = CreateTexture(1, 1);
        StandardMaterial* material = new StandardMaterial{};

        texture->SetData(color.x, color.y, color.z, color.w);
        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector2& position, const Vector3& size, float angle, const Vector3& axis, Texture2D* const texture) {
        Texture* internal_texture = dynamic_cast<Texture*>(texture);
        return CreateCube(position, size, angle, axis, internal_texture);
    }

    Mesh* MeshBuilder::CreateCube(const Vector2& position, const Vector3& size, float angle, const Vector3& axis, Texture* const texture) {
        Mesh*             mesh     = CreateCube(position, size, angle, axis);
        StandardMaterial* material = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector2& position, const Vector3& size, float angle, const Vector3& axis, const Ref<Texture2D>& texture) {
        auto internal_texture = std::dynamic_pointer_cast<Texture>(texture);
        assert(texture != nullptr);
        return CreateCube(position, size, angle, axis, internal_texture);
    }

    Mesh* MeshBuilder::CreateCube(const Vector2& position, const Vector3& size, float angle, const Vector3& axis, const Ref<Texture>& texture) {
        Mesh*             mesh     = CreateCube(position, size, angle, axis);
        StandardMaterial* material = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector3& position, const Vector3& size, float angle, const Vector3& axis) {
        Mesh*             mesh          = new Mesh{};
        CubeGeometry*     quad_geometry = new CubeGeometry(position, size, axis, angle);
        Texture*          texture       = CreateTexture(1, 1);
        StandardMaterial* material      = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetGeometry(quad_geometry);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector3& position, const Vector3& size, const Vector3& color, float angle, const Vector3& axis) {
        Mesh*             mesh     = CreateCube(position, size, angle, axis);
        Texture*          texture  = CreateTexture(1, 1);
        StandardMaterial* material = new StandardMaterial{};

        texture->SetData(color.x, color.y, color.z, 255.f);
        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector3& position, const Vector3& size, const Vector4& color, float angle, const Vector3& axis) {
        Mesh*             mesh     = CreateCube(position, size, angle, axis);
        Texture*          texture  = CreateTexture(1, 1);
        StandardMaterial* material = new StandardMaterial{};

        texture->SetData(color.x, color.y, color.z, color.w);
        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector3& position, const Vector3& size, float angle, const Vector3& axis, Texture2D* const texture) {
        Texture* internal_texture = dynamic_cast<Texture*>(texture);
        return CreateCube(position, size, angle, axis, internal_texture);
    }

    Mesh* MeshBuilder::CreateCube(const Vector3& position, const Vector3& size, float angle, const Vector3& axis, Texture* const texture) {
        Mesh*             mesh     = CreateCube(position, size, angle, axis);
        StandardMaterial* material = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector3& position, const Vector3& size, float angle, const Vector3& axis, const Ref<Rendering::Textures::Texture2D>& texture) {
        auto internal_texture = std::dynamic_pointer_cast<Texture>(texture);
        assert(texture != nullptr);
        return CreateCube(position, size, angle, axis, internal_texture);
    }

    Mesh* MeshBuilder::CreateCube(const Vector3& position, const Vector3& size, float angle, const Vector3& axis, const Ref<Rendering::Textures::Texture>& texture) {
        Mesh*             mesh     = CreateCube(position, size, angle, axis);
        StandardMaterial* material = new StandardMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector2& position, const Vector3& size, float angle, const Vector3& axis, ShaderMaterial* const material) {
        Mesh* mesh = CreateCube(position, size, angle, axis);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector3& position, const Vector3& size, float angle, const Vector3& axis, ShaderMaterial* const material) {
        Mesh* mesh = CreateCube(position, size, angle, axis);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector2& position, const Vector3& size, float angle, const Vector3& axis, const Ref<ShaderMaterial>& material) {
        Mesh* mesh = CreateCube(position, size, angle, axis);
        mesh->SetMaterial(material);
        return mesh;
    }

    Mesh* MeshBuilder::CreateCube(const Vector3& position, const Vector3& size, float angle, const Vector3& axis, const Ref<ShaderMaterial>& material) {
        Mesh* mesh = CreateCube(position, size, angle, axis);
        mesh->SetMaterial(material);
        return mesh;
    }

    Light* MeshBuilder::CreateLight(const Vector3& position, const Vector3& size, float angle, const Vector3& axis) {
        Light*         mesh          = new Light{};
        CubeGeometry*  quad_geometry = new CubeGeometry(position, size, axis, angle);
        Texture*       texture       = CreateTexture(1, 1);
        BasicMaterial* material      = new BasicMaterial{};

        material->SetTexture(texture);
        mesh->SetGeometry(quad_geometry);
        mesh->SetMaterial(material);
        return mesh;
    }

    Light* MeshBuilder::CreateLight(const Vector3& position, const Vector3& size, const Vector3& color, float angle, const Vector3& axis) {
        Light*         mesh     = CreateLight(position, size, angle, axis);
        Texture*       texture  = CreateTexture(1, 1);
        BasicMaterial* material = new BasicMaterial{};

        texture->SetData(color.x, color.y, color.z, 255.f);
        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Light* MeshBuilder::CreateLight(const Vector3& position, const Vector3& size, const Vector4& color, float angle, const Vector3& axis) {
        Light*         mesh     = CreateLight(position, size, angle, axis);
        Texture*       texture  = CreateTexture(1, 1);
        BasicMaterial* material = new BasicMaterial{};

        texture->SetData(color.x, color.y, color.z, color.w);
        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Light* MeshBuilder::CreateLight(const Vector3& position, const Vector3& size, float angle, const Vector3& axis, Texture2D* const texture) {
        Texture* internal_texture = reinterpret_cast<Texture*>(texture);
        return CreateLight(position, size, angle, axis, internal_texture);
    }

    Light* MeshBuilder::CreateLight(const Vector3& position, const Vector3& size, float angle, const Vector3& axis, Texture* const texture) {
        Light*         mesh     = CreateLight(position, size, angle, axis);
        BasicMaterial* material = new BasicMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }

    Light* MeshBuilder::CreateLight(const Vector3& position, const Vector3& size, float angle, const Vector3& axis, const Ref<Rendering::Textures::Texture2D>& texture) {
        auto internal_texture = std::dynamic_pointer_cast<Texture>(texture);
        assert(texture != nullptr);
        return CreateLight(position, size, angle, axis, internal_texture);
    }

    Light* MeshBuilder::CreateLight(const Vector3& position, const Vector3& size, float angle, const Vector3& axis, const Ref<Rendering::Textures::Texture>& texture) {
        Light*         mesh     = CreateLight(position, size, angle, axis);
        BasicMaterial* material = new BasicMaterial{};

        material->SetTexture(texture);
        mesh->SetMaterial(material);
        return mesh;
    }
} // namespace ZEngine::Rendering::Meshes
