#pragma once
#include <Rendering/Renderers/GraphicRenderer.h>

namespace ZEngine::Rendering::Renderers {

    class GraphicRenderer3D : public GraphicRenderer {
    public:
        explicit GraphicRenderer3D();
        virtual ~GraphicRenderer3D() = default;

        void Initialize() override;

        void AddMesh(Meshes::Mesh& mesh) override;

        virtual void EndScene() override;

    private:
        std::vector<Rendering::Meshes::Mesh> m_mesh_collection;
    };
} // namespace ZEngine::Rendering::Renderers
