#pragma once
#include "Panel.h"
#include <LDChunk.h>
#include <imgui.h>

class ChunkPanel : public Panel {
public:
    std::vector<LDChunk> chunks;
    LDChunk* selectedChunk;

    ChunkPanel() : Panel("Chunks") {}

protected:
    void DrawContents() override {
        if (chunks.empty()) {
            ImGui::Text("No chunks loaded.");
            return;
        }

        for (size_t i = 0; i < chunks.size(); ++i) {
            DrawChunkTree(chunks[i], i);
        }
    }

private:
    void DrawChunkTree(LDChunk& chunk, int id) {
        ImGui::PushID(id);

        // Label for the node
        std::string label;
        label += std::to_string(chunk.offset);
        label += " | " + std::string(ChunkTypeToString(chunk.type));
        label += " | v" + std::to_string(chunk.version);

        if (!chunk.children.empty()) {
            bool open = ImGui::TreeNode(label.c_str());

            if (ImGui::IsItemClicked()) {
                selectedChunk = &chunk;
            }

            if (open) {
                for (size_t i = 0; i < chunk.children.size(); ++i) {
                    DrawChunkTree(chunk.children[i], static_cast<int>(i));
                }
                ImGui::TreePop();
            }
        }
        else {
            ImGuiTreeNodeFlags flags =
                ImGuiTreeNodeFlags_Leaf |
                ImGuiTreeNodeFlags_NoTreePushOnOpen |
                ImGuiTreeNodeFlags_SpanAvailWidth |
                ((selectedChunk == &chunk) ? ImGuiTreeNodeFlags_Selected : 0);

            ImGui::TreeNodeEx(label.c_str(), flags);

            if (ImGui::IsItemClicked()) {
                selectedChunk = &chunk;
            }
        }

        ImGui::PopID();
    }
};
