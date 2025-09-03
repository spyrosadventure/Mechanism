#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include "ImGuiStyles.h"
#include <imgui_internal.h>

void SetupStyles() {
    // Setup ImGui style
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 8.0f;
    style.FrameRounding = 6.0f;
    style.GrabRounding = 6.0f;
    style.TabRounding = 6.0f;
    style.ScrollbarRounding = 6.0f;
    style.FrameBorderSize = 1.0f;
    style.WindowBorderSize = 1.0f;
    style.ItemSpacing = ImVec2(8, 6);
    style.ItemInnerSpacing = ImVec2(6, 4);
    style.FramePadding = ImVec2(10, 6);
    style.WindowPadding = ImVec2(12, 10);

    // Colors
    ImVec4* colors = style.Colors;
    colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.11f, 0.13f, 1.0f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.13f, 0.14f, 0.16f, 1.0f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.10f, 0.10f, 0.12f, 0.94f);

    colors[ImGuiCol_Border] = ImVec4(0.28f, 0.28f, 0.30f, 1.0f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.18f, 0.20f, 1.0f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.20f, 0.22f, 0.25f, 1.0f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.25f, 0.27f, 0.30f, 1.0f);

    colors[ImGuiCol_TitleBg] = ImVec4(0.09f, 0.10f, 0.12f, 1.0f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.12f, 0.14f, 0.16f, 1.0f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.08f, 0.09f, 0.10f, 0.75f);

    colors[ImGuiCol_Tab] = ImVec4(0.14f, 0.15f, 0.17f, 1.0f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.29f, 0.36f, 1.0f);
    colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.22f, 0.27f, 1.0f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.14f, 0.15f, 0.17f, 1.0f);
    colors[ImGuiCol_TabUnfocusedActive] = colors[ImGuiCol_TabActive];

    colors[ImGuiCol_Button] = ImVec4(0.18f, 0.20f, 0.23f, 1.0f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.29f, 0.36f, 1.0f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.30f, 0.33f, 0.40f, 1.0f);

    colors[ImGuiCol_Header] = ImVec4(0.20f, 0.22f, 0.25f, 1.0f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.29f, 0.36f, 1.0f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.30f, 0.33f, 0.40f, 1.0f);

    colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.29f, 0.36f, 1.0f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.36f, 0.39f, 0.46f, 1.0f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.42f, 0.46f, 0.52f, 1.0f);

    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.10f, 0.12f, 1.0f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.25f, 0.27f, 0.30f, 1.0f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.30f, 0.33f, 0.36f, 1.0f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.36f, 0.39f, 0.42f, 1.0f);

    colors[ImGuiCol_CheckMark] = ImVec4(0.35f, 0.65f, 0.95f, 1.0f); // accent blue
    colors[ImGuiCol_SliderGrab] = ImVec4(0.35f, 0.65f, 0.95f, 1.0f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.45f, 0.75f, 1.00f, 1.0f);

    colors[ImGuiCol_Text] = ImVec4(0.92f, 0.94f, 0.97f, 1.0f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.55f, 0.58f, 0.62f, 1.0f);

}