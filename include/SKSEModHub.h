#pragma once
#include <imgui.h>

#define EXTERNAL_FUNCTION extern "C" __declspec(dllimport) 

namespace SKSEModHubInternal {

    inline std::string key;

    inline ImGuiContext* ctx;

    EXTERNAL_FUNCTION void AddSection(const char* path, std::function<void()> const& rendererFunction);

    EXTERNAL_FUNCTION void SetContextFetch(std::function<void(ImGuiContext*)> contextSetFunction);

}
namespace SKSEModHub{
     
    EXTERNAL_FUNCTION void AddWindow(const char* key, ImGuiWindowFlags flags,
                                     std::function<void()> const& rendererFunction);

    inline void AddSection(std::string menu, std::function<void()> const& rendererFunction) {
        SKSEModHubInternal::AddSection((SKSEModHubInternal::key + "/" + menu).c_str(),
                                       rendererFunction);
    }

    inline void Init(std::string key) {
        SKSEModHubInternal::key = key;
        SKSEModHubInternal::SetContextFetch([](ImGuiContext* ctx) {
            ImGui::SetCurrentContext(ctx);
        });
    }
}