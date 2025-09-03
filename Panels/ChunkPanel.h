#pragma once
#include "Panel.h"
#include <LDChunk.h>
#include <imgui.h>

class ChunkPanel : public Panel {
public:
    std::vector<LDChunk> chunks;
    LDChunk* selectedChunk;
    int game = 0;
    bool is64Bit = false;
    std::string resourceName = "";

    ChunkPanel() : Panel("Chunks") {}

protected:
    bool showResourceNames = false;
    void DrawContents() override {
        ImGui::Checkbox("Show Resource Names", &showResourceNames);
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
        if (!showResourceNames || chunk.children.empty() || !(chunk.children[0].type == CMChunkType::GenSub_ResourceHeader))
        {
            label += std::to_string(chunk.offset);
            label += " | " + std::string(ChunkTypeToString(chunk.type));
            label += " | v" + std::to_string(chunk.version);
        }
        else
        {
            std::string resourceName;
            const auto& data = chunk.children[0].data;

            if (game >= 6) {
                if (data.size() >= 0x1C + 0x40) {
                    const uint8_t* strStart = data.data() + 0x1C;
                    size_t maxLen = 0x40;
                    size_t len = 0;
                    while (len < maxLen && strStart[len] != 0) len++;
                    resourceName = std::string((const char*)strStart, len);
                }
                else {
                    resourceName = "Failed To Read Resource Name!";
                }
            }
            else {
                if (data.size() >= 0x18 + 0x40) {
                    const uint8_t* strStart = data.data() + 0x18;
                    size_t maxLen = 0x40;
                    size_t len = 0;
                    while (len < maxLen && strStart[len] != 0) len++;
                    resourceName = std::string((const char*)strStart, len);
                }
            }

            label += std::to_string(chunk.offset);
            label += " | " + resourceName;
            label += " | v" + std::to_string(chunk.version);
        }

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
