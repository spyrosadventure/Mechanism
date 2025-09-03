#pragma once
#include <string>
#include <imgui.h>

class Panel {
public:
    Panel(const std::string& name) : name(name), isOpen(true) {}
    virtual ~Panel() = default;

    void Render() {
        if (!isOpen)
            return;

        if (ImGui::Begin(name.c_str(), &isOpen)) {
            DrawContents();
        }
        ImGui::End();
    }

    bool IsOpen() const { return isOpen; }
    void SetOpen(bool open) { isOpen = open; }
    void DrawProperty(const char* label, const char* value)
    {
        ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.9f, 1.0f), "%s:", label);
        ImGui::SameLine(150);
        ImGui::Text("%s", value);
    }

protected:
    std::string name;
    bool isOpen;

    virtual void DrawContents() = 0;
};