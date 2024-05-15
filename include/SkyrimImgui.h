#pragma once
#include <imgui.h>

extern "C"
    [[maybe_unused]] __declspec(dllimport) void AddRenderer(const char* menu, std::function<void()> const&rendererFunction);


extern "C" [[maybe_unused]] __declspec(dllimport) ImGuiContext* GetContext();


void Init() {
    ImGui::SetCurrentContext(GetContext());
}