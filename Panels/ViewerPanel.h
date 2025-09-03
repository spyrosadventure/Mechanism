#pragma once
#include "Panel.h"
#include <LDChunk.h>
#include <imgui.h>
#include <iomanip>
#include <sstream>

class ViewerPanel : public Panel {
public:
    LDChunk* selectedChunk = nullptr;

    ViewerPanel() : Panel("Inspector") {}

protected:
    void DrawContents() override {
        if (!selectedChunk) {
            ImGui::TextDisabled("No Chunk Selected.");
            return;
        }

        ImGui::Spacing();
        ImGui::Text("Chunk Info");
        ImGui::Separator();

        if (ImGui::BeginTable("ChunkProperties", 2, ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_SizingStretchProp)) {
            ImGui::TableNextRow();

            ImGui::TableNextRow();
            ImGui::TableNextColumn(); ImGui::TextUnformatted("Type");
            ImGui::TableNextColumn(); ImGui::TextUnformatted(ChunkTypeToString(selectedChunk->type));

            ImGui::TableNextRow();
            ImGui::TableNextColumn(); ImGui::TextUnformatted("Version");
            ImGui::TableNextColumn(); ImGui::Text("%d", selectedChunk->version);

            ImGui::TableNextRow();
            ImGui::TableNextColumn(); ImGui::TextUnformatted("Has Children");
            ImGui::TableNextColumn(); ImGui::TextUnformatted(selectedChunk->hasChildren ? "Yes" : "No");

            ImGui::TableNextRow();
            ImGui::TableNextColumn(); ImGui::TextUnformatted("Length");
            ImGui::TableNextColumn(); ImGui::Text("%zu", selectedChunk->length);

            ImGui::TableNextRow();
            ImGui::TableNextColumn(); ImGui::TextUnformatted("Offset");
            ImGui::TableNextColumn(); ImGui::Text("%zu", selectedChunk->offset);

            ImGui::EndTable();
        }

        if (!selectedChunk->GetChildren().empty()) { ImGui::SeparatorText("Children"); ImGui::BulletText("This Chunk has %u children.", selectedChunk->GetChildren().size()); }

        if (!selectedChunk->data.empty()) {
            ImGui::Spacing();
            ImGui::Text("Chunk Data");
            ImGui::Separator();

            ImGui::BeginChild("DataBox", ImVec2(600, ImGui::GetContentRegionAvail().y), true, ImGuiWindowFlags_HorizontalScrollbar);

            const auto& data = selectedChunk->data;
            const size_t rowSize = 16;
            const size_t rows = (data.size() + rowSize - 1) / rowSize;

            ImGuiListClipper clipper;
            clipper.Begin((int)rows);

            while (clipper.Step()) {
                for (int r = clipper.DisplayStart; r < clipper.DisplayEnd; r++) {
                    size_t start = r * rowSize;
                    size_t end = std::min(start + rowSize, data.size());

                    char line[128];
                    int offset = snprintf(line, sizeof(line), "%08X  ", (unsigned int)start);

                    for (size_t i = start; i < end; i++) {
                        offset += snprintf(line + offset, sizeof(line) - offset,
                            "%02X ", data[i]);
                        if (((i - start + 1) % 8) == 0) {
                            line[offset++] = ' ';
                            line[offset] = '\0';
                        }
                    }

                    if (end - start < rowSize) {
                        size_t missing = rowSize - (end - start);
                        for (size_t i = 0; i < missing; i++) {
                            offset += snprintf(line + offset, sizeof(line) - offset, "   ");
                            if (((end - start + i + 1) % 8) == 0) {
                                line[offset++] = ' ';
                                line[offset] = '\0';
                            }
                        }
                    }

                    offset += snprintf(line + offset, sizeof(line) - offset, " ");
                    for (size_t i = start; i < end; i++) {
                        unsigned char c = data[i];
                        line[offset++] = (c >= 32 && c <= 126) ? (char)c : '.';
                    }
                    line[offset] = '\0';

                    ImGui::TextUnformatted(line);
                }
            }

            ImGui::EndChild();
        }
    }
};