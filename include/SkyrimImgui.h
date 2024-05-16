#pragma once
#include <imgui.h>

#define EXTERNAL_FUNCTION extern "C" __declspec(dllimport) 

namespace SkyrimImguiInternal {
    std::string key;

    ImGuiContext* ctx;

    EXTERNAL_FUNCTION void AddSection(const char* path, const char* title, std::function<void()> const& rendererFunction);

    EXTERNAL_FUNCTION void SetContextFetch(std::function<void(ImGuiContext*)> contextSetFunction);

}
namespace SkyrimImgui{

    EXTERNAL_FUNCTION void AddWindow(const char* key, ImGuiWindowFlags flags,
                                     std::function<void()> const& rendererFunction);

    void AddSection(std::string menu, std::string title, std::function<void()> const& rendererFunction) {
        SkyrimImguiInternal::AddSection((SkyrimImguiInternal::key + "/" + menu).c_str(), title.c_str(), rendererFunction);
    }

    void Init(std::string key) {
        SkyrimImguiInternal::key = key;
        SkyrimImguiInternal::SetContextFetch([](ImGuiContext* ctx) {
            ImGui::SetCurrentContext(ctx);
        });
    }
}