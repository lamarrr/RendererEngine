#include <pch.h>
#include <Rendering/Renderers/Pipelines/GraphicRendererDrawStage.h>
#include <Rendering/Renderers/Pipelines/GraphicRendererEndFrameBindingStage.h>
#include <Rendering/Renderers/Pipelines/GraphicRendererPipelineContext.h>
#include <Rendering/Renderers/RenderCommand.h>

namespace ZEngine::Rendering::Renderers::Pipelines {
    GraphicRendererDrawStage::GraphicRendererDrawStage() {
        m_next_stage = std::make_shared<GraphicRendererEndFrameBindingStage>();
    }

    GraphicRendererDrawStage::~GraphicRendererDrawStage() {}

    void GraphicRendererDrawStage::Run(GraphicRendererPipelineInformation& information) {

        auto const  pipeline = reinterpret_cast<GraphicRendererPipelineContext*>(m_context);
        auto const  renderer = pipeline->GetRenderer();
        const auto& camera   = renderer->GetCamera();

        while (!information.GraphicStorageCollection.empty()) {
            const auto& storage = information.GraphicStorageCollection.front();

            const auto& material = storage.GetMaterial();
            const auto& geometry = storage.GetGeometry();

            const auto& shader = storage.GetShader();
            shader->CreateProgram();

            material->Apply(shader.get());

            // Todo : As used by many shader, we should moved it out to an Uniform Buffer
            shader->SetUniform("model", geometry->GetTransform());
            shader->SetUniform("view", camera->GetViewMatrix());
            shader->SetUniform("projection", camera->GetProjectionMatrix());

            const auto& vertex_array = storage.GetVertexArray();
            RendererCommand::DrawIndexed(shader, vertex_array);

            information.GraphicStorageCollection.pop();
        }
    }

} // namespace ZEngine::Rendering::Renderers::Pipelines
